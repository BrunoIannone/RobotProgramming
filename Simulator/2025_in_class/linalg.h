#pragma once
#include "math.h"
#include <iostream>
struct Vector2f {
  float _values[2];
  Vector2f(float x=0, float y=0) {
    _values[0]=x;
    _values[1]=y;
  }
  
  inline float x() const {
    return _values[0];
  }

  inline float y() const {
    return _values[1];
  }

  inline float& x()  {
    return _values[0];
  }

  inline float& y() {
    return _values[1];
  }

  inline Vector2f operator+(const Vector2f& other) const  {
    return Vector2f(_values[0]+other._values[0],
                    _values[1]+other._values[1]);
  }

  inline Vector2f operator-(const Vector2f& other) const {
    return Vector2f(_values[0]-other._values[0],
                    _values[1]-other._values[1]);
  }
   inline Vector2f operator-() const {
    return Vector2f(-_values[0],-_values[1]);
  }

  inline Vector2f& operator+=(Vector2f& other)  {
    _values[0]+=other._values[0];
    _values[1]+=other._values[1];
    return *this;
  }

  inline Vector2f& operator-=(Vector2f& other)  {
    _values[0]-=other._values[0];
    _values[1]-=other._values[1];
    return *this;
  }
};

struct Vector2i {
  int _values[2];
  Vector2i(int x=0, int y=0) {
    _values[0]=x;
    _values[1]=y;
  }
  
  inline int x() const {
    return _values[0];
  }

  inline int y() const {
    return _values[1];
  }

  inline int& x()  {
    return _values[0];
  }

  inline int& y() {
    return _values[1];
  }

  inline Vector2i operator+(const Vector2i& other) const  {
    return Vector2i(_values[0]+other._values[0],
                    _values[1]+other._values[1]);
  }

  inline Vector2i operator-(const Vector2i& other) const {
    return Vector2i(_values[0]-other._values[0],
                    _values[1]-other._values[1]);
  }
 
  inline Vector2i& operator+=(Vector2i& other)  {
    _values[0]+=other._values[0];
    _values[1]+=other._values[1];
    return *this;
  }

  inline Vector2i& operator-=(Vector2i& other)  {
    _values[0]-=other._values[0];
    _values[1]-=other._values[1];
    return *this;
  }
};


struct Rotation2f {
  float _values[2][2];

  Rotation2f() {
    _values[0][0]=1; _values[0][1]=0;
    _values[1][0]=0; _values[1][1]=1;
  }

  Rotation2f(float theta) {
    float s=sin(theta);
    float c=cos(theta);
    _values[0][0]=c; _values[0][1]=-s;
    _values[1][0]=s; _values[1][1]= c;
  }

  inline float angle() const {
    return atan2(_values[1][0], _values[0][0]);
  }

  inline Rotation2f operator*(const Rotation2f& other) const {
    Rotation2f ret;
    for (int r=0; r<2; ++r) {
      for (int c=0; c<2; ++c){
        float acc=0;
        for (int i=0; i<2; ++i) {
          acc += _values[r][i]*other._values[i][c];
        }
        ret._values[r][c]=acc;
      }
    }
    return ret;
  }

  inline Rotation2f transpose() const {
    Rotation2f ret(*this);
    ret._values[1][0]=-ret._values[1][0];
    ret._values[0][1]=-ret._values[0][1];
    return ret;
  }

  inline Vector2f operator*(const Vector2f& other) const {
    return Vector2f (_values[0][0]*other.x()+_values[0][1]*other.y(),
                     _values[1][0]*other.x()+_values[1][1]*other.y());
                     
  }

  
};

std::ostream& operator<<(std::ostream& os,const Rotation2f& rot) {
  
  os << "  values:[ " << std::endl;
  for (int r=0; r<2; ++r) {
    os << "\t";
    for (int c=0; c<2; ++c) {
      os << rot._values[r][c] <<  " ";
    }
    os << std::endl;
  }
  os << " ]" << std::endl << "}";
  return os;
}
struct Isometry2f {
  Vector2f _translation;
  Rotation2f _rotation;

  Isometry2f() {
    _rotation = Rotation2f();
    _translation = Vector2f(0,0);
    
  }

  Isometry2f(float x, float y, float theta){
    _rotation = Rotation2f(theta);
    _translation = Vector2f(x,y);  
  }
  void setIdentity(){
    _rotation = Rotation2f();
    _translation = Vector2f(0,0);
  }

  Isometry2f operator* (const Isometry2f& other) const {
    
    // complete R*other.R | t+R*other.t
    Isometry2f res;
    res._rotation = _rotation*other._rotation;
    res._translation =_translation + _rotation*other._translation;
    return res;

  }

  Vector2f operator* (const Vector2f& other) const {
    //complete R*other+t
    return Vector2f(_rotation*other + _translation);
    
    
  }

  Isometry2f inverse() const {
    // complete R' | -R' *t
    Isometry2f res;
    res._rotation = _rotation.transpose();
    res._translation = -(_rotation.transpose()*_translation); //R*t = vector
    return res;
  }

  
};
