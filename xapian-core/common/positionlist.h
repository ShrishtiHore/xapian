/* positionlist.h
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

#ifndef OM_HGUARD_POSITIONLIST_H
#define OM_HGUARD_POSITIONLIST_H

#include "omassert.h"

#include "om/omtypes.h"
#include "om/omerror.h"

/** Abstract base class for position lists. */
class PositionList
{
    private:
	/// Copying is not allowed.
	PositionList(const PositionList &);

	/// Assignment is not allowed.
	void operator=(const PositionList &);
    public:
	/// Default constructor.
	PositionList() {}

	/// Destructor.
	virtual ~PositionList() { return; }
	
	/// Gets size of position list.
	virtual om_termcount get_size() const = 0;

	/// Gets current position.
	virtual om_termpos get_position() const = 0;

	/** Move to the next item in the list.
	 *  This must be called before get_position() - the list initially
	 *  points to before the beginning of the list.
	 */
	virtual void next() = 0;

	/// True if we're off the end of the list
	virtual bool at_end() const = 0;
};

#endif /* OM_HGUARD_POSITIONLIST_H */
