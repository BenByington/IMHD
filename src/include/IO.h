/*
 * Copywrite 2013 Benjamin Byington
 *
 * This file is part of the IMHD software package
 * 
 * IMHD is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public Liscence as published by the Free 
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

/* 
 * File:   IO.h
 * Author: Ben
 *
 * Created on March 31, 2010, 3:19 PM
 */

#ifndef _IO_H
#define	_IO_H

#include "Precision.h"
#include <string.h>
#include "Field.h"

void testIO();
void initIO();

void writeSpatial(p_field f, char * name);
void readSpatial(p_field f, char * name);

void writeCheckpoint();
void readCheckpoint();

void performOutput();

#endif	/* _IO_H */

