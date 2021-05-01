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

template <class T>
class Shape {
    
    std::vector<Vector3<T>> _vecs;
    
public:
    
    Shape(std::initializer_list<Vector3<T>> list) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            _vecs.push_back(*i);
        }
    }
    
    Vector3<T> centroid() {
        Vector3<T> cent = {0,0,0};
        for (auto i = _vecs.begin(); i != _vecs.end(); ++i) {
            cent += *i;
        }
        return cent/this->_vecs.size();
    }
    
};

#endif /* Shape_h */
