#ifndef FortranMatrixH
#define FortranMatrixH
//==============================================================================
//    Copyright 2010 Petr Kulhanek
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
#include <FortranRow.hpp>
#include <stddef.h>

//------------------------------------------------------------------------------

class CXMLBinData;

//------------------------------------------------------------------------------

class SCIMAFIC_PACKAGE CFortranMatrix {
public:
    CFortranMatrix(void);
    CFortranMatrix(const CFortranMatrix& src);
    ~CFortranMatrix(void);

// setup methods ---------------------------------------------------------------
    bool CreateMatrix(const size_t rows,const size_t columns);
    void FreeMatrix(void);

// information method ----------------------------------------------------------
    size_t  GetNumberOfRows(void) const;
    size_t  GetNumberOfColumns(void) const;
    double* GetRawDataField(void);

// set method ------------------------------------------------------------------
    void SetZero(void);
    bool SetUnit(void);

// access method ---------------------------------------------------------------
    const CFortranRow operator[](const size_t row) const;
    CFortranRow       operator[](const size_t row);
    void              operator=(const CFortranMatrix& src);

// I/O methods -----------------------------------------------------------------
    /// load matrix data from XMLBinData
    void Load(CXMLBinData* p_ele);

    /// load matrix data from XMLBinData
    void Save(CXMLBinData* p_ele);

// section of private data -----------------------------------------------------
private:
    size_t      NRows;
    size_t      NColumns;
    double*     Array;

    friend class CFortranRow;
};

//------------------------------------------------------------------------------

#endif
