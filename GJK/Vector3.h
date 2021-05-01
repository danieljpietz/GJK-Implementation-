//
//  Vector3.h
//  GJK
//
//  Created by Daniel Pietz on 4/21/21.
//

#ifndef Vector3_h
#define Vector3_h

template <class T>
class Vector3 {
    T _x;
    T _y;
    T _z;
public:
    
    Vector3(T x, T y, T z) {
        this->_x = x;
        this->_y = y;
        this->_z = z;
    }
    
    Vector3(const T v[3]) {
        this->_x = v[0];
        this->_y = v[1];
        this->_z = v[2];
    }
    
    Vector3(const Vector3& v) {
        this->_x = v.x();
        this->_y = v.y();
        this->_z = v.z();
    }
    
    T x() const {
        return this->_x;
    }
    
    T y() const {
        return this->_y;
    }
    
    T z() const {
        return this->_z;
    }
    
    Vector3 operator +(const Vector3& v1) const {
        return Vector3(this->x() + v1.x(), this->y() + v1.y(), this->z() + v1.z());
    }
    
    void operator +=(const Vector3& v1) {
        this->_x += v1.x();
        this->_y += v1.y();
        this->_z += v1.z();
    }
    
    void operator -=(const Vector3& v1)  {
        this->_x -= v1.x();
        this->_y -= v1.y();
        this->_z -= v1.z();
    }
    
    Vector3 operator -() const {
        return Vector3(-this->x(), -this->y(), -this->z());
    }
    
    Vector3 operator -(const Vector3& v1) const {
        return *this + (-v1);
    }
    
    Vector3 operator *(const T& f) const {
        return Vector3(this->x() * f, this->y() * f, this->z() * f);
    }
    
    Vector3 operator /(const T& f) const {
        return Vector3(this->x() / f, this->y() / f, this->z() / f);
    }
    
    T norm() {
        return sqrt(this->x()*this->x() + this->y()*this->y() + this->z()*this->z());
    }
    
    Vector3 normalize() {
        return *this/this->norm();
    }
    
};

template <class T>
Vector3<T> operator *(const T& f, const Vector3<T>& v1) {
    return v1 * f;
}

template <class T>
T dot(const Vector3<T>& v1, const Vector3<T>& v2) {
    return v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
}

#endif /* Vector3_h */
