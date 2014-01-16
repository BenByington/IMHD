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

#ifndef TENSOR_H
#define	TENSOR_H

#include "GNode.h"

class Vector;

class Tensor
{
protected:
    Tensor();
    
public:
    virtual ~Tensor(){}
    virtual Vector * createVector() = 0;
    virtual Tensor * createTensor() = 0;
    
    /*Arithmetic operations between vectors fields*/
    Tensor * operator +(Tensor * r);
    Tensor * operator -(Tensor * r);
    
    virtual Vector * divergence() = 0;
    
    GNode * op;
private:
    class TensorArithmetic : public GNode
    {
        friend class Tensor;
    public:
        TensorArithmetic(Tensor * v1, Tensor * v2);
        virtual void execute();
        virtual std::string executeText();
        
    private:
        Tensor * p1;
        Tensor * p2;
        
        enum operations {add, sub};
        operations op;
    };
    
    
};

#endif	/* TENSOR_H */
