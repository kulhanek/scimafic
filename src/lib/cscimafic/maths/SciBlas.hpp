#ifndef SciBlasH
#define SciBlasH
//==============================================================================
//    Copyright 2019 Petr Kulhanek
//
//    This file is part of SciMaFic library.
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Lesser General Public
//    License as published by the Free Software Foundation; either
//    version 2.1 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 51 Franklin Street, Fifth Floor,
//    Boston, MA  02110-1301  USA
//==============================================================================

#include <SciMaFicMainHeader.hpp>
#include <FortranMatrix.hpp>
#include <Vector.hpp>

//------------------------------------------------------------------------------

class SCIMAFIC_PACKAGE CSciBlas {
public:
    /// dot product
    static double dot(CVector& a,CVector& b);

    /// matrix vector multiplication
    static void gemv(double alpha,CFortranMatrix& a,CVector& x,double beta,CVector& y);
};

//------------------------------------------------------------------------------

// blas entry points

extern "C" double ddot_(int* N,double* DX,int* INCX,double* DY,int* INCY);
extern "C" void dgemv_(char* trans,int* M, int* N, double* ALPHA,
                      double* A,int* LDA,double* X,int* INCX,double* BETA,double* Y,int* INCY);

extern "C" void dgemm_(char* transa, char* transb,int* M,int* N,int* K,double* alpha,
                       double* a,int* lda,double* b,int* ldb,double* beta,double* c, int* ldc);

//------------------------------------------------------------------------------

#endif