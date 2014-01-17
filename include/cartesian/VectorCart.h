/*
 * Copywrite 2013-2014 Benjamin Byington
 *
 * This file is part of the Proteus software package
 * 
 * Proteus is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Proteus is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with Proteus.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef VECTOR_CARTESIAN_H
#define VECTOR_CARTESIAN_H

#include "Vector.h"

class VectorCart : public Vector
{
    //friend class FieldCart;
protected:
    VectorCart();
        
public:
    virtual ~VectorCart(){}
    
    virtual Solenoid * decompose();
    virtual Solenoid * decomposeCurl();
    virtual Field * divergence();
    virtual Vector * curl();
    virtual Tensor * gradient();
    virtual Vector * laplacian();

private:
    class AgnosticDeriv : public GNode
    {
        friend class VectorCart;
    public:
        AgnosticDeriv(VectorCart * v);
        virtual void execute();
        virtual std::string executeText();
    private:
        VectorCart * vParent;
        
        enum operations {div, curl, grad, laplace, decomp, decompCurl};
        operations op;
    };
    
};
#endif