/***************************************************************************
 *   Copyright (C) 2004 by Olivier Galizzi                                 *
 *   olivier.galizzi@imag.fr                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __QTGUIGENERATOR_HPP__
#define __QTGUIGENERATOR_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


#include "QtGUISignalCatcher.h"

#include <qframe.h>
#include "XMLManager.hpp"
#include <qlineedit.h>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <qobject.h>
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief 

	
*/
class QtGUIGenerator : public XMLManager,  public QtGUISignalCatcher
{

	

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Attributes											///
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	class AttributeDescriptor
	{
		public : string name;
		public : vector<QLineEdit*> lineEdits;
	};
	
	public : vector<shared_ptr<AttributeDescriptor> > descriptors;
	public : map<string,int> lookUp;
	public : shared_ptr<Serializable> serializable;	
///////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor/Destructor									///
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*! Constructor */
	public : QtGUIGenerator ();

	/*! Destructor */
	public : virtual ~QtGUIGenerator ();

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods											///
///////////////////////////////////////////////////////////////////////////////////////////////////

	public : void buildGUI(shared_ptr<Serializable> s, QWidget * parent, QFrame * frame);
	
	public slots : virtual void pushButtonOkClicked() ;
	public slots : virtual void pushButtonApplyClicked() ;
	public slots : virtual void pushButtonCancelClicked() ;

};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __QTGUIGENERATOR_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

