/*
 * Copyright (c) 1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */ 
# include "stlport_prefix.h"

// #include <string>
#include <istream>

__STL_BEGIN_NAMESPACE

#if !defined(__STL_NO_FORCE_INSTANTIATE)
// instantiations
# if defined (__STL_USE_TEMPLATE_EXPORT)
template  class __STL_CLASS_DECLSPEC _Isentry<char, char_traits<char> >;
# endif
template  class __STL_CLASS_DECLSPEC basic_iostream<char, char_traits<char> >;
#if !defined(__STL_MSVC) || (__STL_MSVC > 1100)
template  class __STL_CLASS_DECLSPEC basic_istream<char, char_traits<char> >;
#endif

#ifndef __STL_NO_WCHAR_T
# if defined (__STL_USE_TEMPLATE_EXPORT)
template class __STL_CLASS_DECLSPEC _Isentry<wchar_t, char_traits<wchar_t> >;
# endif
#if !defined(__STL_MSVC) || (__STL_MSVC > 1100)
template class __STL_CLASS_DECLSPEC basic_istream<wchar_t, char_traits<wchar_t> >;
#endif
template class __STL_CLASS_DECLSPEC basic_iostream<wchar_t, char_traits<wchar_t> >;
#endif /* INSTANTIATE_WIDE_STREAMS */
#endif

__STL_END_NAMESPACE


// Local Variables:
// mode:C++
// End:
