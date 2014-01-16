/*
 * Copywrite 2013-2014 Benjamin Byington
 *
 * This file is part of the IMHD software package
 * 
 * IMHD is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * IMHD is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with IMHD.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "GNode.h"

#include <string>

class Field;
class Solenoid;
class Tensor;
class Scalar;

class Vector 
{
protected:
    Vector();
    
public:
    virtual ~Vector(){}
    virtual Vector * createVector() = 0;
    virtual Field * createField() = 0;
    virtual Solenoid * createSolenoid() = 0;
    virtual Tensor * createTensor() = 0;
    
    Vector * operator *(Scalar * fact);
    Vector * operator /(Scalar * mult);
    
    /*Arithmetic operations between vectors fields*/
    Vector * operator +(Vector * r);
    Vector * operator -(Vector * r);
    
    Field * dot(Vector * r);
    Vector * cross(Vector * r);
    
    virtual Solenoid * decompose() = 0;
    virtual Solenoid * decomposeCurl() = 0;
    virtual Field * divergence() = 0;
    virtual Vector * curl() = 0;
    virtual Tensor * gradient() = 0;

    GNode * op;
private:
    class VectorArithmetic : public GNode
    {
        friend class Vector;
    public:
        VectorArithmetic(Vector * v1, Vector * v2);
        virtual void execute();
        virtual std::string executeText();
        
    private:
        Vector * p1;
        Vector * p2;
        
        enum operations {add, sub, dot, cross};
        operations op;
    };
    
    class ScalarFactor : public GNode
    {
        friend class Vector;
    public:
        ScalarFactor(Scalar * s, Vector * v);
        virtual void execute();
        virtual std::string executeText();
        
    private:
        Scalar * sParent;
        Vector* vParent;
        
        enum operations {mul, divide};        
        operations op;
    };
};

#endif