/*
 * DSIGTransformList.cpp
 *
 *  Created on: 2013/05/03
 *      Author: mugwort_rc
 */

#include "DSIGTransformList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xsec/dsig/DSIGTransform.hpp>

#include <xsec/dsig/DSIGTransformList.hpp>

namespace pyxsec {

void DSIGTransformList_init(void) {
	//! DSIGTransformList
	boost::python::class_<DSIGTransformList, boost::noncopyable>("DSIGTransformList")
			.def("addTransform", &DSIGTransformList::addTransform)
			.def("removeTransform", &DSIGTransformList::removeTransform)
			.def("item", &DSIGTransformList::item, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSize", &DSIGTransformList::getSize)
			.def("empty", &DSIGTransformList::empty)
			;
}

} /* namespace pyxsec */
