/* omwritabledbinternal.h: Class definition for OmWritableDatabase::Internal
 *
 * ----START-LICENCE----
 * Copyright 1999,2000 Dialog Corporation
 * 
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 * -----END-LICENCE-----
 */

#ifndef OM_HGUARD_OMWRITABLEDBINTERNAL_H
#define OM_HGUARD_OMWRITABLEDBINTERNAL_H

#include <vector>

#include <om/omindexer.h>
#include "omlocks.h"
#include "omrefcnt.h"
#include "database_builder.h"
#include "database.h"

/////////////////////////////////////
// Internals of OmWritableDatabase //
/////////////////////////////////////

/** Reference counted internals for OmWritableDatabase.
 */
class OmWritableDatabase::Internal {
    public:
	/** Make a new internal object, with the user supplied parameters.
	 *
	 *  This opens the database and stores it in the ref count pointer.
	 *
	 *  @param type    a string describing the database type.
	 *  @param params  a vector of parameters to be used to open the
	 *                 database: meaning and number required depends
	 *                 on database type.
	 */
	Internal(const string & type,
		 const vector<string> & paths);

	/** Make a copy of this object, copying the ref count pointer.
	 */
	Internal(const Internal &other)
		: mydb(other.mydb), mutex() {}

	/** The database.  Access to this is not protected by a mutex here -
	 *  it is up to the database to deal with thread safety.
	 */
	OmRefCntPtr<IRDatabase> mydb;

	/** A lock to control concurrent access to this object.
	 *  This is not intended to control access to the IRDatabase object.
	 */
	OmLock mutex;
};

#endif // OM_HGUARD_OMWRITABLEDBINTERNAL_H
