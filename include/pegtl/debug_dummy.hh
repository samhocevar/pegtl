// Copyright (c) 2008 by Dr. Colin Hirsch 
// Please see license.txt for license.

#ifndef COHI_PEGTL_HH
#error "Please #include only pegtl.hh (rather than individual pegtl_*.hh files)."
#endif

#ifndef COHI_PEGTL_DEBUG_DUMMY_HH
#define COHI_PEGTL_DEBUG_DUMMY_HH


namespace pegtl
{
   struct dummy_debug
   {
      dummy_debug()
      { }

      template< typename TopRule >
      dummy_debug( const tag< TopRule > & )
      { }

      template< bool Must, typename Rule, typename Input, typename... Class >
      bool match( Input & in, Class && ... cl )
      {
	 return Rule::template s_match< Must >( in, *this, std::forward< Class >( cl ) ... );
      }
   };

} // pegtl

#endif
