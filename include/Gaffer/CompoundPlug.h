//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2011-2012, John Haddon. All rights reserved.
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      * Redistributions of source code must retain the above
//        copyright notice, this list of conditions and the following
//        disclaimer.
//
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following
//        disclaimer in the documentation and/or other materials provided with
//        the distribution.
//
//      * Neither the name of John Haddon nor the names of
//        any other contributors to this software may be used to endorse or
//        promote products derived from this software without specific prior
//        written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef GAFFER_COMPOUNDPLUG_H
#define GAFFER_COMPOUNDPLUG_H

#include "Gaffer/ValuePlug.h"

namespace Gaffer
{

/// \todo Remove this type entirely - it only existed to allow
/// "plugs with children", and now the Plug and ValuePlug classes
/// implement that directly. When doing this, refactor ValuePlug
/// to accept only ValuePlugs as children rather than also accepting
/// normal Plugs. It's currently accepting Plugs for backwards
/// compatibility with CompoundPlug, and having to do a number of
/// runTimeCast<Value>Plug() operations internally to work around that.
class CompoundPlug : public ValuePlug
{

	public :

		CompoundPlug( const std::string &name=defaultName<CompoundPlug>(), Direction direction=In, unsigned flags=Default );
		~CompoundPlug() override;

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( Gaffer::CompoundPlug, CompoundPlugTypeId, ValuePlug );

		PlugPtr createCounterpart( const std::string &name, Direction direction ) const override;

};

IE_CORE_DECLAREPTR( CompoundPlug );

typedef FilteredChildIterator<PlugPredicate<Plug::Invalid, CompoundPlug> > CompoundPlugIterator;
typedef FilteredChildIterator<PlugPredicate<Plug::In, CompoundPlug> > InputCompoundPlugIterator;
typedef FilteredChildIterator<PlugPredicate<Plug::Out, CompoundPlug> > OutputCompoundPlugIterator;

typedef FilteredRecursiveChildIterator<PlugPredicate<Plug::Invalid, CompoundPlug>, PlugPredicate<> > RecursiveCompoundPlugIterator;
typedef FilteredRecursiveChildIterator<PlugPredicate<Plug::In, CompoundPlug>, PlugPredicate<> > RecursiveInputCompoundPlugIterator;
typedef FilteredRecursiveChildIterator<PlugPredicate<Plug::Out, CompoundPlug>, PlugPredicate<> > RecursiveOutputCompoundPlugIterator;

} // namespace Gaffer

#endif // GAFFER_COMPOUNDPLUG_H
