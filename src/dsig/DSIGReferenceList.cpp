/*
 * DSIGReferenceList.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGReferenceList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/dsig/DSIGReference.hpp>

#include <xsec/dsig/DSIGReferenceList.hpp>

namespace pyxsec {

void DSIGReferenceList_init(void) {
	//! DSIGReferenceList
	boost::python::class_<DSIGReferenceList, boost::noncopyable>("DSIGReferenceList")
			.def("addReference", &DSIGReferenceList::addReference)
			.def("removeReference", &DSIGReferenceList::removeReference, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("item", &DSIGReferenceList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSize", &DSIGReferenceList::getSize)
			.def("empty", &DSIGReferenceList::empty)
			;
}

} /* namespace pyxsec */
