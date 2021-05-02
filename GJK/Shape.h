//
//  Shape.h
//  GJK
//
//  Created by Daniel Pietz on 4/21/21.
//

#ifndef Shape_h
#define Shape_h

#include "Vector3.h"
#include <vector>
#include <initializer_list>
#include <algorithm>

template <class T>
class Shape {
    
    std::vector<Vector3<T>> _vecs;
    
public:
    
    Shape(std::initializer_list<Vector3<T>> list) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            _vecs.push_back(*i);
        }
    }
    
    Shape(const std::initializer_list<T> x, const std::initializer_list<T> y) {
        for (int i = 0; i < x.size(); ++i) {
            _vecs.push_back(Vector3<T>(*(x.begin()+i), *(y.begin()+i), 0));
        }
        
        
    }
    
    Vector3<T> centroid() {
        Vector3<T> cent = {0,0,0};
        for (auto i = _vecs.begin(); i != _vecs.end(); ++i) {
            cent += *i;
        }
        return cent/this->_vecs.size();
    }
    
    Vector3<T> furthestPoint(Vector3<T> v) {
        T dotMax = 0;
        Vector3<T> currentVector(0,0,0);
        for (auto i = _vecs.begin(); i < _vecs.end(); ++i) {
            T dotCurrent = dot(*i - centroid(), v);
            if (dotCurrent > dotMax) {
                dotMax = dotCurrent;
                currentVector = *i;
            }
        }
        return currentVector;
    }
};

template <class T>
Vector3<T> support(Shape<T> s1, Shape<T> s2, Vector3<T>& d) {
    return s1.furthestPoint(d) - s2.furthestPoint(-d);
}


template <class T>
bool lineCase(std::vector<Vector3<T>> simplex, Vector3<T>& d) {
    
    auto B = *(simplex.end() - 2);
    auto A = *(simplex.end() - 1);
    auto AB = B - A;
    auto AO = ORIGIN - A;
    auto ABPerp = tripProd(AB, AO, AB);
    d = ABPerp;
    return false;
    
}


template <class T>
bool triangleCase(std::vector<Vector3<T>>& simplex, Vector3<T>& d) {
    
    auto C = *(simplex.end() - 3);
    auto B = *(simplex.end() - 2);
    auto A = *(simplex.end() - 1);
    
    auto AB = B - A;
    auto AC = C - A;
    auto AO = ORIGIN - A;
    
    auto ABPerp = tripProd(AC, AB, AB);
    auto ACPerp = tripProd(AB, AC, AC);
    
    if (dot(ABPerp, AO) > 0) {
        simplex.erase(simplex.end() - 3);
        d = ABPerp;
        return false;
    }
    else if (dot(ACPerp, AO) > 0) {
        simplex.erase(simplex.end() - 2);
        d = ACPerp;
        return false;
    }
    return true;
}


template <class T>
bool handleSimplex(std::vector<Vector3<T>> simplex, Vector3<T>& d) {
    if (simplex.size() == 2) {
        return lineCase(simplex, d);
    }
    else {
        return triangleCase(simplex, d);
    }
}

#endif /* Shape_h */
