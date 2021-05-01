//
//  main.cpp
//  GJK
//
//  Created by Daniel Pietz on 4/21/21.
//

#include <iostream>
#include "Shape.h"
#include <algorithm>


template <class T>
bool GJK(Shape<T> s1, Shape<T> s2) {

    Vector3<T> d = (s2.centroid() - s1.centroid()).normalize();
    
    std::vector<Vector3<T>> simplex = {support(s1, s2, d)};
    
    d = ORIGIN - simplex[0];
    
    while (true) {
        Vector3<T> A = support(s1, s2, d);
        if (dot(A,d) < 0) {
            return false;
        }
        else {
            simplex.push_back(A);
            if (handleSimplex(simplex, d)) {
                return true;
            }
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...

    Shape<double> t1({1.03, 4.38, 3.75}, {-2.9, -2.02, -3.1});
    Shape<double> t2({1,3,4.66}, {1,-.2,-2.63});
    
    
    std::cout << GJK(t1, t2) << std::endl;
    
    return 0;
}
