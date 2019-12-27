#define DATA_0  \
"/*!\n" \
" * jQuery JavaScript Library v1.8.3\n" \
" * http://jquery.com/\n" \
" *\n" \
" * Includes Sizzle.js\n" \
" * http://sizzlejs.com/\n" \
" *\n" \
" * Copyright 2012 jQuery Foundation and other contributors\n" \
" * Released under the MIT license\n" \
" * http://jquery.org/license\n" \
" *\n" \
" * Date: Tue Nov 13 2012 08:20:33 GMT-0500 (Eastern Standard Time)\n" \
" */\n" \
"(function( window, undefined ) {\n" \
"var\n" \
"	// A central reference to the root jQuery(document)\n" \
"	rootjQuery,\n" \
"\n" \
"	// The deferred used on DOM ready\n" \
"	readyList,\n" \
"\n" \
"	// Use the correct document accordingly with window argument (sandbox)\n" \
"	document = window.document,\n" \
"	location = window.location,\n" \
"	navigator = window.navigator,\n" \
"\n" \
"	// Map over jQuery in case of overwrite\n" \
"	_jQuery = window.jQuery,\n" \
"\n" \
"	// Map over the $ in case of overwrite\n" \
"	_$ = window.$,\n" \
"\n" \
"	// Save a reference to some core methods\n" \
"	core_push = Array.prototype.push,\n" \
"	core_slice = Array.prototype.slice,\n" \
"	core_indexOf = Array.prototype.indexOf,\n" \
"	core_toString = Object.prototype.toString,\n" \
"	core_hasOwn = Object.prototype.hasOwnProperty,\n" \
"	core_trim = String.prototype.trim,\n" \
"\n" \
"	// Define a local copy of jQuery\n" \
"	jQuery = function( selector, context ) {\n" \
"		// The jQuery object is actually just the init constructor 'enhanced'\n" \
"		return new jQuery.fn.init( selector, context, rootjQuery );\n" \
"	},\n" \
"\n" \
"	// Used for matching numbers\n" \
"	core_pnum = /[\\-+]?(?:\\d*\\.|)\\d+(?:[eE][\\-+]?\\d+|)/.source,\n" \
"\n" \
"	// Used for detecting and trimming whitespace\n" \
"	core_rnotwhite = /\\S/,\n" \
"	core_rspace = /\\s+/,\n" \
"\n" \
"	// Make sure we trim BOM and NBSP (here's looking at you, Safari 5.0 and IE)\n" \
"	rtrim = /^[\\s\\uFEFF\\xA0]+|[\\s\\uFEFF\\xA0]+$/g,\n" \
"\n" \
"	// A simple way to check for HTML strings\n" \
"	// Prioritize #id over <tag> to avoid XSS via location.hash (#9521)\n" \
"	rquickExpr = /^(?:[^#<]*(<[\\w\\W]+>)[^>]*$|#([\\w\\-]*)$)/,\n" \
"\n" \
"	// Match a standalone tag\n" \
"	rsingleTag = /^<(\\w+)\\s*\\/?>(?:<\\/\\1>|)$/,\n" \
"\n" \
"	// JSON RegExp\n" \
"	rvalidchars = /^[\\],:{}\\s]*$/,\n" \
"	rvalidbraces = /(?:^|:|,)(?:\\s*\\[)+/g,\n" \
"	rvalidescape = /\\\\(?:[\"\\\\\\/bfnrt]|u[\\da-fA-F]{4})/g,\n" \
"	rvalidtokens = /\"[^\"\\\\\\r\\n]*\"|true|false|null|-?(?:\\d\\d*\\.|)\\d+(?:[eE][\\-+]?\\d+|)/g,\n" \
"\n" \
"	// Matches dashed string for camelizing\n" \
"	rmsPrefix = /^-ms-/,\n" \
"	rdashAlpha = /-([\\da-z])/gi,\n" \
"\n" \
"	// Used by jQuery.camelCase as callback to replace()\n" \
"	fcamelCase = function( all, letter ) {\n" \
"		return ( letter + \"\" ).toUpperCase();\n" \
"	},\n" \
"\n" \
"	// The ready event handler and self cleanup method\n" \
"	DOMContentLoaded = function() {\n" \
"		if ( document.addEventListener ) {\n" \
"			document.removeEventListener( \"DOMContentLoaded\", DOMContentLoaded, false );\n" \
"			jQuery.ready();\n" \
"		} else if ( document.readyState === \"complete\" ) {\n" \
"			// we're here because readyState === \"complete\" in oldIE\n" \
"			// which is good enough for us to call the dom ready!\n" \
"			document.detachEvent( \"onreadystatechange\", DOMContentLoaded );\n" \
"			jQuery.ready();\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// [[Class]] -> type pairs\n" \
"	class2type = {};\n" \
"\n" \
"jQuery.fn = jQuery.prototype = {\n" \
"	constructor: jQuery,\n" \
"	init: function( selector, context, rootjQuery ) {\n" \
"		var match, elem, ret, doc;\n" \
"\n" \
"		// Handle $(\"\"), $(null), $(undefined), $(false)\n" \
"		if ( !selector ) {\n" \
"			return this;\n" \
"		}\n" \
"\n" \
"		// Handle $(DOMElement)\n" \
"		if ( selector.nodeType ) {\n" \
"			this.context = this[0] = selector;\n" \
"			this.length = 1;\n" \
"			return this;\n" \
"		}\n" \
"\n" \
"		// Handle HTML strings\n" \
"		if ( typeof selector === \"string\" ) {\n" \
"			if ( selector.charAt(0) === \"<\" && selector.charAt( selector.length - 1 ) === \">\" && selector.length >= 3 ) {\n" \
"				// Assume that strings that start and end with <> are HTML and skip the regex check\n" \
"				match = [ null, selector, null ];\n" \
"\n" \
"			} else {\n" \
"				match = rquickExpr.exec( selector );\n" \
"			}\n" \
"\n" \
"			// Match html or make sure no context is specified for #id\n" \
"			if ( match && (match[1] || !context) ) {\n" \
"\n" \
"				// HANDLE: $(html) -> $(array)\n" \
"				if ( match[1] ) {\n" \
"					context = context instanceof jQuery ? context[0] : context;\n" \
"					doc = ( context && context.nodeType ? context.ownerDocument || context : document );\n" \
"\n" \
"					// scripts is true for back-compat\n" \
"					selector = jQuery.parseHTML( match[1], doc, true );\n" \
"					if ( rsingleTag.test( match[1] ) && jQuery.isPlainObject( context ) ) {\n" \
"						this.attr.call( selector, context, true );\n" \
"					}\n" \
"\n" \
"					return jQuery.merge( this, selector );\n" \
"\n" \
"				// HANDLE: $(#id)\n" \
"				} else {\n" \
"					elem = document.getElementById( match[2] );\n" \
"\n" \
"					// Check parentNode to catch when Blackberry 4.6 returns\n" \
"					// nodes that are no longer in the document #6963\n" \
"					if ( elem && elem.parentNode ) {\n" \
"						// Handle the case where IE and Opera return items\n" \
"						// by name instead of ID\n" \
"						if ( elem.id !== match[2] ) {\n" \
"							return rootjQuery.find( selector );\n" \
"						}\n" \
"\n" \
"						// Otherwise, we inject the element directly into the jQuery object\n" \
"						this.length = 1;\n" \
"						this[0] = elem;\n" \
"					}\n" \
"\n" \
"					this.context = document;\n" \
"					this.selector = selector;\n" \
"					return this;\n" \
"				}\n" \
"\n" \
"			// HANDLE: $(expr, $(...))\n" \
"			} else if ( !context || context.jquery ) {\n" \
"				return ( context || rootjQuery ).find( selector );\n" \
"\n" \
"			// HANDLE: $(expr, context)\n" \
"			// (which is just equivalent to: $(context).find(expr)\n" \
"			} else {\n" \
"				return this.constructor( context ).find( selector );\n" \
"			}\n" \
"\n" \
"		// HANDLE: $(function)\n" \
"		// Shortcut for document ready\n" \
"		} else if ( jQuery.isFunction( selector ) ) {\n" \
"			return rootjQuery.ready( selector );\n" \
"		}\n" \
"\n" \
"		if ( selector.selector !== undefined ) {\n" \
"			this.selector = selector.selector;\n" \
"			this.context = selector.context;\n" \
"		}\n" \
"\n" \
"		return jQuery.makeArray( selector, this );\n" \
"	},\n" \
"\n" \
"	// Start with an empty selector\n" \
"	selector: \"\",\n" \
"\n" \
"	// The current version of jQuery being used\n" \
"	jquery: \"1.8.3\",\n" \
"\n" \
"	// The default length of a jQuery object is 0\n" \
"	length: 0,\n" \
"\n" \
"	// The number of elements contained in the matched element set\n" \
"	size: function() {\n" \
"		return this.length;\n" \
"	},\n" \
"\n" \
"	toArray: function() {\n" \
"		return core_slice.call( this );\n" \
"	},\n" \
"\n" \
"	// Get the Nth element in the matched element set OR\n" \
"	// Get the whole matched element set as a clean array\n" \
"	get: function( num ) {\n" \
"		return num == null ?\n" \
"\n" \
"			// Return a 'clean' array\n" \
"			this.toArray() :\n" \
"\n" \
"			// Return just the object\n" \
"			( num < 0 ? this[ this.length + num ] : this[ num ] );\n" \
"	},\n" \
"\n" \
"	// Take an array of elements and push it onto the stack\n" \
"	// (returning the new matched element set)\n" \
"	pushStack: function( elems, name, selector ) {\n" \
"\n" \
"		// Build a new jQuery matched element set\n" \
"		var ret = jQuery.merge( this.constructor(), elems );\n" \
"\n" \
"		// Add the old object onto the stack (as a reference)\n" \
"		ret.prevObject = this;\n" \
"\n" \
"		ret.context = this.context;\n" \
"\n" \
"		if ( name === \"find\" ) {\n" \
"			ret.selector = this.selector + ( this.selector ? \" \" : \"\" ) + selector;\n" \
"		} else if ( name ) {\n" \
"			ret.selector = this.selector + \".\" + name + \"(\" + selector + \")\";\n" \
"		}\n" \
"\n" \
"		// Return the newly-formed element set\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	// Execute a callback for every element in the matched set.\n" \
"	// (You can seed the arguments with an array of args, but this is\n" \
"	// only used internally.)\n" \
"	each: function( callback, args ) {\n" \
"		return jQuery.each( this, callback, args );\n" \
"	},\n" \
"\n" \
"	ready: function( fn ) {\n" \
"		// Add the callback\n" \
"		jQuery.ready.promise().done( fn );\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	eq: function( i ) {\n" \
"		i = +i;\n" \
"		return i === -1 ?\n" \
"			this.slice( i ) :\n" \
"			this.slice( i, i + 1 );\n" \
"	},\n" \
"\n" \
"	first: function() {\n" \
"		return this.eq( 0 );\n" \
"	},\n" \
"\n" \
"	last: function() {\n" \
"		return this.eq( -1 );\n" \
"	},\n" \
"\n" \
"	slice: function() {\n" \
"		return this.pushStack( core_slice.apply( this, arguments ),\n" \
"			\"slice\", core_slice.call(arguments).join(\",\") );\n" \
"	},\n" \
"\n" \
"	map: function( callback ) {\n" \
"		return this.pushStack( jQuery.map(this, function( elem, i ) {\n" \
"			return callback.call( elem, i, elem );\n" \
"		}));\n" \
"	},\n" \
"\n" \
"	end: function() {\n" \
"		return this.prevObject || this.constructor(null);\n" \
"	},\n" \
"\n" \
"	// For internal use only.\n" \
"	// Behaves like an Array's method, not like a jQuery method.\n" \
"	push: core_push,\n" \
"	sort: [].sort,\n" \
"	splice: [].splice\n" \
"};\n" \
"\n" \
"// Give the init function the jQuery prototype for later instantiation\n" \
"jQuery.fn.init.prototype = jQuery.fn;\n" \
"\n" \
"jQuery.extend = jQuery.fn.extend = function() {\n" \
"	var options, name, src, copy, copyIsArray, clone,\n" \
"		target = arguments[0] || {},\n" \
"		i = 1,\n" \
"		length = arguments.length,\n" \
"		deep = false;\n" \
"\n" \
"	// Handle a deep copy situation\n" \
"	if ( typeof target === \"boolean\" ) {\n" \
"		deep = target;\n" \
"		target = arguments[1] || {};\n" \
"		// skip the boolean and the target\n" \
"		i = 2;\n" \
"	}\n" \
"\n" \
"	// Handle case when target is a string or something (possible in deep copy)\n" \
"	if ( typeof target !== \"object\" && !jQuery.isFunction(target) ) {\n" \
"		target = {};\n" \
"	}\n" \
"\n" \
"	// extend jQuery itself if only one argument is passed\n" \
"	if ( length === i ) {\n" \
"		target = this;\n" \
"		--i;\n" \
"	}\n" \
"\n" \
"	for ( ; i < length; i++ ) {\n" \
"		// Only deal with non-null/undefined values\n" \
"		if ( (options = arguments[ i ]) != null ) {\n" \
"			// Extend the base object\n" \
"			for ( name in options ) {\n" \
"				src = target[ name ];\n" \
"				copy = options[ name ];\n" \
"\n" \
"				// Prevent never-ending loop\n" \
"				if ( target === copy ) {\n" \
"					continue;\n" \
"				}\n" \
"\n" \
"				// Recurse if we're merging plain objects or arrays\n" \
"				if ( deep && copy && ( jQuery.isPlainObject(copy) || (copyIsArray = jQuery.isArray(copy)) ) ) {\n" \
"					if ( copyIsArray ) {\n" \
"						copyIsArray = false;\n" \
"						clone = src && jQuery.isArray(src) ? src : [];\n" \
"\n" \
"					} else {\n" \
"						clone = src && jQuery.isPlainObject(src) ? src : {};\n" \
"					}\n" \
"\n" \
"					// Never move original objects, clone them\n" \
"					target[ name ] = jQuery.extend( deep, clone, copy );\n" \
"\n" \
"				// Don't bring in undefined values\n" \
"				} else if ( copy !== undefined ) {\n" \
"					target[ name ] = copy;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Return the modified object\n" \
"	return target;\n" \
"};\n" \
"\n" \
"jQuery.extend({\n" \
"	noConflict: function( deep ) {\n" \
"		if ( window.$ === jQuery ) {\n" \
"			window.$ = _$;\n" \
"		}\n" \
"\n" \
"		if ( deep && window.jQuery === jQuery ) {\n" \
"			window.jQuery = _jQuery;\n" \
"		}\n" \
"\n" \
"		return jQuery;\n" \
"	},\n" \
"\n" \
"	// Is the DOM ready to be used? Set to true once it occurs.\n" \
"	isReady: false,\n" \
"\n" \
"	// A counter to track how many items to wait for before\n" \
"	// the ready event fires. See #6781\n" \
"	readyWait: 1,\n" \
"\n" \
"	// Hold (or release) the ready event\n" \
"	holdReady: function( hold ) {\n" \
"		if ( hold ) {\n" \
"			jQuery.readyWait++;\n" \
"		} else {\n" \
"			jQuery.ready( true );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Handle when the DOM is ready\n" \
"	ready: function( wait ) {\n" \
"\n" \
"		// Abort if there are pending holds or we're already ready\n" \
"		if ( wait === true ? --jQuery.readyWait : jQuery.isReady ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Make sure body exists, at least, in case IE gets a little overzealous (ticket #5443).\n" \
"		if ( !document.body ) {\n" \
"			return setTimeout( jQuery.ready, 1 );\n" \
"		}\n" \
"\n" \
"		// Remember that the DOM is ready\n" \
"		jQuery.isReady = true;\n" \
"\n" \
"		// If a normal DOM Ready event fired, decrement, and wait if need be\n" \
"		if ( wait !== true && --jQuery.readyWait > 0 ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// If there are functions bound, to execute\n" \
"		readyList.resolveWith( document, [ jQuery ] );\n" \
"\n" \
"		// Trigger any bound ready events\n" \
"		if ( jQuery.fn.trigger ) {\n" \
"			jQuery( document ).trigger(\"ready\").off(\"ready\");\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// See test/unit/core.js for details concerning isFunction.\n" \
"	// Since version 1.3, DOM methods and functions like alert\n" \
"	// aren't supported. They return false on IE (#2968).\n" \
"	isFunction: function( obj ) {\n" \
"		return jQuery.type(obj) === \"function\";\n" \
"	},\n" \
"\n" \
"	isArray: Array.isArray || function( obj ) {\n" \
"		return jQuery.type(obj) === \"array\";\n" \
"	},\n" \
"\n" \
"	isWindow: function( obj ) {\n" \
"		return obj != null && obj == obj.window;\n" \
"	},\n" \
"\n" \
"	isNumeric: function( obj ) {\n" \
"		return !isNaN( parseFloat(obj) ) && isFinite( obj );\n" \
"	},\n" \
"\n" \
"	type: function( obj ) {\n" \
"		return obj == null ?\n" \
"			String( obj ) :\n" \
"			class2type[ core_toString.call(obj) ] || \"object\";\n" \
"	},\n" \
"\n" \
"	isPlainObject: function( obj ) {\n" \
"		// Must be an Object.\n" \
"		// Because of IE, we also have to check the presence of the constructor property.\n" \
"		// Make sure that DOM nodes and window objects don't pass through, as well\n" \
"		if ( !obj || jQuery.type(obj) !== \"object\" || obj.nodeType || jQuery.isWindow( obj ) ) {\n" \
"			return false;\n" \
"		}\n" \
"\n" \
"		try {\n" \
"			// Not own constructor property must be Object\n" \
"			if ( obj.constructor &&\n" \
"				!core_hasOwn.call(obj, \"constructor\") &&\n" \
"				!core_hasOwn.call(obj.constructor.prototype, \"isPrototypeOf\") ) {\n" \
"				return false;\n" \
"			}\n" \
"		} catch ( e ) {\n" \
"			// IE8,9 Will throw exceptions on certain host objects #9897\n" \
"			return false;\n" \
"		}\n" \
"\n" \
"		// Own properties are enumerated firstly, so to speed up,\n" \
"		// if last one is own, then all properties are own.\n" \
"\n" \
"		var key;\n" \
"		for ( key in obj ) {}\n" \
"\n" \
"		return key === undefined || core_hasOwn.call( obj, key );\n" \
"	},\n" \
"\n" \
"	isEmptyObject: function( obj ) {\n" \
"		var name;\n" \
"		for ( name in obj ) {\n" \
"			return false;\n" \
"		}\n" \
"		return true;\n" \
"	},\n" \
"\n" \
"	error: function( msg ) {\n" \
"		throw new Error( msg );\n" \
"	},\n" \
"\n" \
"	// data: string of html\n" \
"	// context (optional): If specified, the fragment will be created in this context, defaults to document\n" \
"	// scripts (optional): If true, will include scripts passed in the html string\n" \
"	parseHTML: function( data, context, scripts ) {\n" \
"		var parsed;\n" \
"		if ( !data || typeof data !== \"string\" ) {\n" \
"			return null;\n" \
"		}\n" \
"		if ( typeof context === \"boolean\" ) {\n" \
"			scripts = context;\n" \
"			context = 0;\n" \
"		}\n" \
"		context = context || document;\n" \
"\n" \
"		// Single tag\n" \
"		if ( (parsed = rsingleTag.exec( data )) ) {\n" \
"			return [ context.createElement( parsed[1] ) ];\n" \
"		}\n" \
"\n" \
"		parsed = jQuery.buildFragment( [ data ], context, scripts ? null : [] );\n" \
"		return jQuery.merge( [],\n" \
"			(parsed.cacheable ? jQuery.clone( parsed.fragment ) : parsed.fragment).childNodes );\n" \
"	},\n" \
"\n" \
"	parseJSON: function( data ) {\n" \
"		if ( !data || typeof data !== \"string\") {\n" \
"			return null;\n" \
"		}\n" \
"\n" \
"		// Make sure leading/trailing whitespace is removed (IE can't handle it)\n" \
"		data = jQuery.trim( data );\n" \
"\n" \
"		// Attempt to parse using the native JSON parser first\n" \
"		if ( window.JSON && window.JSON.parse ) {\n" \
"			return window.JSON.parse( data );\n" \
"		}\n" \
"\n" \
"		// Make sure the incoming data is actual JSON\n" \
"		// Logic borrowed from http://json.org/json2.js\n" \
"		if ( rvalidchars.test( data.replace( rvalidescape, \"@\" )\n" \
"			.replace( rvalidtokens, \"]\" )\n" \
"			.replace( rvalidbraces, \"\")) ) {\n" \
"\n" \
"			return ( new Function( \"return \" + data ) )();\n" \
"\n" \
"		}\n" \
"		jQuery.error( \"Invalid JSON: \" + data );\n" \
"	},\n" \
"\n" \
"	// Cross-browser xml parsing\n" \
"	parseXML: function( data ) {\n" \
"		var xml, tmp;\n" \
"		if ( !data || typeof data !== \"string\" ) {\n" \
"			return null;\n" \
"		}\n" \
"		try {\n" \
"			if ( window.DOMParser ) { // Standard\n" \
"				tmp = new DOMParser();\n" \
"				xml = tmp.parseFromString( data , \"text/xml\" );\n" \
"			} else { // IE\n" \
"				xml = new ActiveXObject( \"Microsoft.XMLDOM\" );\n" \
"				xml.async = \"false\";\n" \
"				xml.loadXML( data );\n" \
"			}\n" \
"		} catch( e ) {\n" \
"			xml = undefined;\n" \
"		}\n" \
"		if ( !xml || !xml.documentElement || xml.getElementsByTagName( \"parsererror\" ).length ) {\n" \
"			jQuery.error( \"Invalid XML: \" + data );\n" \
"		}\n" \
"		return xml;\n" \
"	},\n" \
"\n" \
"	noop: function() {},\n" \
"\n" \
"	// Evaluates a script in a global context\n" \
"	// Workarounds based on findings by Jim Driscoll\n" \
"	// http://weblogs.java.net/blog/driscoll/archive/2009/09/08/eval-javascript-global-context\n" \
"	globalEval: function( data ) {\n" \
"		if ( data && core_rnotwhite.test( data ) ) {\n" \
"			// We use execScript on Internet Explorer\n" \
"			// We use an anonymous function so that context is window\n" \
"			// rather than jQuery in Firefox\n" \
"			( window.execScript || function( data ) {\n" \
"				window[ \"eval\" ].call( window, data );\n" \
"			} )( data );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Convert dashed to camelCase; used by the css and data modules\n" \
"	// Microsoft forgot to hump their vendor prefix (#9572)\n" \
"	camelCase: function( string ) {\n" \
"		return string.replace( rmsPrefix, \"ms-\" ).replace( rdashAlpha, fcamelCase );\n" \
"	},\n" \
"\n" \
"	nodeName: function( elem, name ) {\n" \
"		return elem.nodeName && elem.nodeName.toLowerCase() === name.toLowerCase();\n" \
"	},\n" \
"\n" \
"	// args is for internal usage only\n" \
"	each: function( obj, callback, args ) {\n" \
"		var name,\n" \
"			i = 0,\n" \
"			length = obj.length,\n" \
"			isObj = length === undefined || jQuery.isFunction( obj );\n" \
"\n" \
"		if ( args ) {\n" \
"			if ( isObj ) {\n" \
"				for ( name in obj ) {\n" \
"					if ( callback.apply( obj[ name ], args ) === false ) {\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"			} else {\n" \
"				for ( ; i < length; ) {\n" \
"					if ( callback.apply( obj[ i++ ], args ) === false ) {\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"		// A special, fast, case for the most common use of each\n" \
"		} else {\n" \
"			if ( isObj ) {\n" \
"				for ( name in obj ) {\n" \
"					if ( callback.call( obj[ name ], name, obj[ name ] ) === false ) {\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"			} else {\n" \
"				for ( ; i < length; ) {\n" \
"					if ( callback.call( obj[ i ], i, obj[ i++ ] ) === false ) {\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return obj;\n" \
"	},\n" \
"\n" \
"	// Use native String.trim function wherever possible\n" \
"	trim: core_trim && !core_trim.call(\"\\uFEFF\\xA0\") ?\n" \
"		function( text ) {\n" \
"			return text == null ?\n" \
"				\"\" :\n" \
"				core_trim.call( text );\n" \
"		} :\n" \
"\n" \
"		// Otherwise use our own trimming functionality\n" \
"		function( text ) {\n" \
"			return text == null ?\n" \
"				\"\" :\n" \
"				( text + \"\" ).replace( rtrim, \"\" );\n" \
"		},\n" \
"\n" \
"	// results is for internal usage only\n" \
"	makeArray: function( arr, results ) {\n" \
"		var type,\n" \
"			ret = results || [];\n" \
"\n" \
"		if ( arr != null ) {\n" \
"			// The window, strings (and functions) also have 'length'\n" \
"			// Tweaked logic slightly to handle Blackberry 4.7 RegExp issues #6930\n" \
"			type = jQuery.type( arr );\n" \
"\n" \
"			if ( arr.length == null || type === \"string\" || type === \"function\" || type === \"regexp\" || jQuery.isWindow( arr ) ) {\n" \
"				core_push.call( ret, arr );\n" \
"			} else {\n" \
"				jQuery.merge( ret, arr );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	inArray: function( elem, arr, i ) {\n" \
"		var len;\n" \
"\n" \
"		if ( arr ) {\n" \
"			if ( core_indexOf ) {\n" \
"				return core_indexOf.call( arr, elem, i );\n" \
"			}\n" \
"\n" \
"			len = arr.length;\n" \
"			i = i ? i < 0 ? Math.max( 0, len + i ) : i : 0;\n" \
"\n" \
"			for ( ; i < len; i++ ) {\n" \
"				// Skip accessing in sparse arrays\n" \
"				if ( i in arr && arr[ i ] === elem ) {\n" \
"					return i;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return -1;\n" \
"	},\n" \
"\n" \
"	merge: function( first, second ) {\n" \
"		var l = second.length,\n" \
"			i = first.length,\n" \
"			j = 0;\n" \
"\n" \
"		if ( typeof l === \"number\" ) {\n" \
"			for ( ; j < l; j++ ) {\n" \
"				first[ i++ ] = second[ j ];\n" \
"			}\n" \
"\n" \
"		} else {\n" \
"			while ( second[j] !== undefined ) {\n" \
"				first[ i++ ] = second[ j++ ];\n" \
"			}\n" \
"		}\n" \
"\n" \
"		first.length = i;\n" \
"\n" \
"		return first;\n" \
"	},\n" \
"\n" \
"	grep: function( elems, callback, inv ) {\n" \
"		var retVal,\n" \
"			ret = [],\n" \
"			i = 0,\n" \
"			length = elems.length;\n" \
"		inv = !!inv;\n" \
"\n" \
"		// Go through the array, only saving the items\n" \
"		// that pass the validator function\n" \
"		for ( ; i < length; i++ ) {\n" \
"			retVal = !!callback( elems[ i ], i );\n" \
"			if ( inv !== retVal ) {\n" \
"				ret.push( elems[ i ] );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	// arg is for internal usage only\n" \
"	map: function( elems, callback, arg ) {\n" \
"		var value, key,\n" \
"			ret = [],\n" \
"			i = 0,\n" \
"			length = elems.length,\n" \
"			// jquery objects are treated as arrays\n" \
"			isArray = elems instanceof jQuery || length !== undefined && typeof length === \"number\" && ( ( length > 0 && elems[ 0 ] && elems[ length -1 ] ) || length === 0 || jQuery.isArray( elems ) ) ;\n" \
"\n" \
"		// Go through the array, translating each of the items to their\n" \
"		if ( isArray ) {\n" \
"			for ( ; i < length; i++ ) {\n" \
"				value = callback( elems[ i ], i, arg );\n" \
"\n" \
"				if ( value != null ) {\n" \
"					ret[ ret.length ] = value;\n" \
"				}\n" \
"			}\n" \
"\n" \
"		// Go through every key on the object,\n" \
"		} else {\n" \
"			for ( key in elems ) {\n" \
"				value = callback( elems[ key ], key, arg );\n" \
"\n" \
"				if ( value != null ) {\n" \
"					ret[ ret.length ] = value;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Flatten any nested arrays\n" \
"		return ret.concat.apply( [], ret );\n" \
"	},\n" \
"\n" \
"	// A global GUID counter for objects\n" \
"	guid: 1,\n" \
"\n" \
"	// Bind a function to a context, optionally partially applying any\n" \
"	// arguments.\n" \
"	proxy: function( fn, context ) {\n" \
"		var tmp, args, proxy;\n" \
"\n" \
"		if ( typeof context === \"string\" ) {\n" \
"			tmp = fn[ context ];\n" \
"			context = fn;\n" \
"			fn = tmp;\n" \
"		}\n" \
"\n" \
"		// Quick check to determine if target is callable, in the spec\n" \
"		// this throws a TypeError, but we will just return undefined.\n" \
"		if ( !jQuery.isFunction( fn ) ) {\n" \
"			return undefined;\n" \
"		}\n" \
"\n" \
"		// Simulated bind\n" \
"		args = core_slice.call( arguments, 2 );\n" \
"		proxy = function() {\n" \
"			return fn.apply( context, args.concat( core_slice.call( arguments ) ) );\n" \
"		};\n" \
"\n" \
"		// Set the guid of unique handler to the same of original handler, so it can be removed\n" \
"		proxy.guid = fn.guid = fn.guid || jQuery.guid++;\n" \
"\n" \
"		return proxy;\n" \
"	},\n" \
"\n" \
"	// Multifunctional method to get and set values of a collection\n" \
"	// The value/s can optionally be executed if it's a function\n" \
"	access: function( elems, fn, key, value, chainable, emptyGet, pass ) {\n" \
"		var exec,\n" \
"			bulk = key == null,\n" \
"			i = 0,\n" \
"			length = elems.length;\n" \
"\n" \
"		// Sets many values\n" \
"		if ( key && typeof key === \"object\" ) {\n" \
"			for ( i in key ) {\n" \
"				jQuery.access( elems, fn, i, key[i], 1, emptyGet, value );\n" \
"			}\n" \
"			chainable = 1;\n" \
"\n" \
"		// Sets one value\n" \
"		} else if ( value !== undefined ) {\n" \
"			// Optionally, function values get executed if exec is true\n" \
"			exec = pass === undefined && jQuery.isFunction( value );\n" \
"\n" \
"			if ( bulk ) {\n" \
"				// Bulk operations only iterate when executing function values\n" \
"				if ( exec ) {\n" \
"					exec = fn;\n" \
"					fn = function( elem, key, value ) {\n" \
"						return exec.call( jQuery( elem ), value );\n" \
"					};\n" \
"\n" \
"				// Otherwise they run against the entire set\n" \
"				} else {\n" \
"					fn.call( elems, value );\n" \
"					fn = null;\n" \
"				}\n" \
"			}\n" \
"\n" \
"			if ( fn ) {\n" \
"				for (; i < length; i++ ) {\n" \
"					fn( elems[i], key, exec ? value.call( elems[i], i, fn( elems[i], key ) ) : value, pass );\n" \
"				}\n" \
"			}\n" \
"\n" \
"			chainable = 1;\n" \
"		}\n" \
"\n" \
"		return chainable ?\n" \
"			elems :\n" \
"\n" \
"			// Gets\n" \
"			bulk ?\n" \
"				fn.call( elems ) :\n" \
"				length ? fn( elems[0], key ) : emptyGet;\n" \
"	},\n" \
"\n" \
"	now: function() {\n" \
"		return ( new Date() ).getTime();\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.ready.promise = function( obj ) {\n" \
"	if ( !readyList ) {\n" \
"\n" \
"		readyList = jQuery.Deferred();\n" \
"\n" \
"		// Catch cases where $(document).ready() is called after the browser event has already occurred.\n" \
"		// we once tried to use readyState \"interactive\" here, but it caused issues like the one\n" \
"		// discovered by ChrisS here: http://bugs.jquery.com/ticket/12282#comment:15\n" \
"		if ( document.readyState === \"complete\" ) {\n" \
"			// Handle it asynchronously to allow scripts the opportunity to delay ready\n" \
"			setTimeout( jQuery.ready, 1 );\n" \
"\n" \
"		// Standards-based browsers support DOMContentLoaded\n" \
"		} else if ( document.addEventListener ) {\n" \
"			// Use the handy event callback\n" \
"			document.addEventListener( \"DOMContentLoaded\", DOMContentLoaded, false );\n" \
"\n" \
"			// A fallback to window.onload, that will always work\n" \
"			window.addEventListener( \"load\", jQuery.ready, false );\n" \
"\n" \
"		// If IE event model is used\n" \
"		} else {\n" \
"			// Ensure firing before onload, maybe late but safe also for iframes\n" \
"			document.attachEvent( \"onreadystatechange\", DOMContentLoaded );\n" \
"\n" \
"			// A fallback to window.onload, that will always work\n" \
"			window.attachEvent( \"onload\", jQuery.ready );\n" \
"\n" \
"			// If IE and not a frame\n" \
"			// continually check to see if the document is ready\n" \
"			var top = false;\n" \
"\n" \
"			try {\n" \
"				top = window.frameElement == null && document.documentElement;\n" \
"			} catch(e) {}\n" \
"\n" \
"			if ( top && top.doScroll ) {\n" \
"				(function doScrollCheck() {\n" \
"					if ( !jQuery.isReady ) {\n" \
"\n" \
"						try {\n" \
"							// Use the trick by Diego Perini\n" \
"							// http://javascript.nwbox.com/IEContentLoaded/\n" \
"							top.doScroll(\"left\");\n" \
"						} catch(e) {\n" \
"							return setTimeout( doScrollCheck, 50 );\n" \
"						}\n" \
"\n" \
"						// and execute any waiting functions\n" \
"						jQuery.ready();\n" \
"					}\n" \
"				})();\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"	return readyList.promise( obj );\n" \
"};\n" \
"\n" \
"// Populate the class2type map\n" \
"jQuery.each(\"Boolean Number String Function Array Date RegExp Object\".split(\" \"), function(i, name) {\n" \
"	class2type[ \"[object \" + name + \"]\" ] = name.toLowerCase();\n" \
"});\n" \
"\n" \
"// All jQuery objects should point back to these\n" \
"rootjQuery = jQuery(document);\n" \
"// String to Object options format cache\n" \
"var optionsCache = {};\n" \
"\n" \
"// Convert String-formatted options into Object-formatted ones and store in cache\n" \
"function createOptions( options ) {\n" \
"	var object = optionsCache[ options ] = {};\n" \
"	jQuery.each( options.split( core_rspace ), function( _, flag ) {\n" \
"		object[ flag ] = true;\n" \
"	});\n" \
"	return object;\n" \
"}\n" \
"\n" \
"/*\n" \
" * Create a callback list using the following parameters:\n" \
" *\n" \
" *	options: an optional list of space-separated options that will change how\n" \
" *			the callback list behaves or a more traditional option object\n" \
" *\n" \
" * By default a callback list will act like an event callback list and can be\n" \
" * \"fired\" multiple times.\n" \
" *\n" \
" * Possible options:\n" \
" *\n" \
" *	once:			will ensure the callback list can only be fired once (like a Deferred)\n" \
" *\n" \
" *	memory:			will keep track of previous values and will call any callback added\n" \
" *					after the list has been fired right away with the latest \"memorized\"\n" \
" *					values (like a Deferred)\n" \
" *\n" \
" *	unique:			will ensure a callback can only be added once (no duplicate in the list)\n" \
" *\n" \
" *	stopOnFalse:	interrupt callings when a callback returns false\n" \
" *\n" \
" */\n" \
"jQuery.Callbacks = function( options ) {\n" \
"\n" \
"	// Convert options from String-formatted to Object-formatted if needed\n" \
"	// (we check in cache first)\n" \
"	options = typeof options === \"string\" ?\n" \
"		( optionsCache[ options ] || createOptions( options ) ) :\n" \
"		jQuery.extend( {}, options );\n" \
"\n" \
"	var // Last fire value (for non-forgettable lists)\n" \
"		memory,\n" \
"		// Flag to know if list was already fired\n" \
"		fired,\n" \
"		// Flag to know if list is currently firing\n" \
"		firing,\n" \
"		// First callback to fire (used internally by add and fireWith)\n" \
"		firingStart,\n" \
"		// End of the loop when firing\n" \
"		firingLength,\n" \
"		// Index of currently firing callback (modified by remove if needed)\n" \
"		firingIndex,\n" \
"		// Actual callback list\n" \
"		list = [],\n" \
"		// Stack of fire calls for repeatable lists\n" \
"		stack = !options.once && [],\n" \
"		// Fire callbacks\n" \
"		fire = function( data ) {\n" \
"			memory = options.memory && data;\n" \
"			fired = true;\n" \
"			firingIndex = firingStart || 0;\n" \
"			firingStart = 0;\n" \
"			firingLength = list.length;\n" \
"			firing = true;\n" \
"			for ( ; list && firingIndex < firingLength; firingIndex++ ) {\n" \
"				if ( list[ firingIndex ].apply( data[ 0 ], data[ 1 ] ) === false && options.stopOnFalse ) {\n" \
"					memory = false; // To prevent further calls using add\n" \
"					break;\n" \
"				}\n" \
"			}\n" \
"			firing = false;\n" \
"			if ( list ) {\n" \
"				if ( stack ) {\n" \
"					if ( stack.length ) {\n" \
"						fire( stack.shift() );\n" \
"					}\n" \
"				} else if ( memory ) {\n" \
"					list = [];\n" \
"				} else {\n" \
"					self.disable();\n" \
"				}\n" \
"			}\n" \
"		},\n" \
"		// Actual Callbacks object\n" \
"		self = {\n" \
"			// Add a callback or a collection of callbacks to the list\n" \
"			add: function() {\n" \
"				if ( list ) {\n" \
"					// First, we save the current length\n" \
"					var start = list.length;\n" \
"					(function add( args ) {\n" \
"						jQuery.each( args, function( _, arg ) {\n" \
"							var type = jQuery.type( arg );\n" \
"							if ( type === \"function\" ) {\n" \
"								if ( !options.unique || !self.has( arg ) ) {\n" \
"									list.push( arg );\n" \
"								}\n" \
"							} else if ( arg && arg.length && type !== \"string\" ) {\n" \
"								// Inspect recursively\n" \
"								add( arg );\n" \
"							}\n" \
"						});\n" \
"					})( arguments );\n" \
"					// Do we need to add the callbacks to the\n" \
"					// current firing batch?\n" \
"					if ( firing ) {\n" \
"						firingLength = list.length;\n" \
"					// With memory, if we're not firing then\n" \
"					// we should call right away\n" \
"					} else if ( memory ) {\n" \
"						firingStart = start;\n" \
"						fire( memory );\n" \
"					}\n" \
"				}\n" \
"				return this;\n" \
"			},\n" \
"			// Remove a callback from the list\n" \
"			remove: function() {\n" \
"				if ( list ) {\n" \
"					jQuery.each( arguments, function( _, arg ) {\n" \
"						var index;\n" \
"						while( ( index = jQuery.inArray( arg, list, index ) ) > -1 ) {\n" \
"							list.splice( index, 1 );\n" \
"							// Handle firing indexes\n" \
"							if ( firing ) {\n" \
"								if ( index <= firingLength ) {\n" \
"									firingLength--;\n" \
"								}\n" \
"								if ( index <= firingIndex ) {\n" \
"									firingIndex--;\n" \
"								}\n" \
"							}\n" \
"						}\n" \
"					});\n" \
"				}\n" \
"				return this;\n" \
"			},\n" \
"			// Control if a given callback is in the list\n" \
"			has: function( fn ) {\n" \
"				return jQuery.inArray( fn, list ) > -1;\n" \
"			},\n" \
"			// Remove all callbacks from the list\n" \
"			empty: function() {\n" \
"				list = [];\n" \
"				return this;\n" \
"			},\n" \
"			// Have the list do nothing anymore\n" \
"			disable: function() {\n" \
"				list = stack = memory = undefined;\n" \
"				return this;\n" \
"			},\n" \
"			// Is it disabled?\n" \
"			disabled: function() {\n" \
"				return !list;\n" \
"			},\n" \
"			// Lock the list in its current state\n" \
"			lock: function() {\n" \
"				stack = undefined;\n" \
"				if ( !memory ) {\n" \
"					self.disable();\n" \
"				}\n" \
"				return this;\n" \
"			},\n" \
"			// Is it locked?\n" \
"			locked: function() {\n" \
"				return !stack;\n" \
"			},\n" \
"			// Call all callbacks with the given context and arguments\n" \
"			fireWith: function( context, args ) {\n" \
"				args = args || [];\n" \
"				args = [ context, args.slice ? args.slice() : args ];\n" \
"				if ( list && ( !fired || stack ) ) {\n" \
"					if ( firing ) {\n" \
"						stack.push( args );\n" \
"					} else {\n" \
"						fire( args );\n" \
"					}\n" \
"				}\n" \
"				return this;\n" \
"			},\n" \
"			// Call all the callbacks with the given arguments\n" \
"			fire: function() {\n" \
"				self.fireWith( this, arguments );\n" \
"				return this;\n" \
"			},\n" \
"			// To know if the callbacks have already been called at least once\n" \
"			fired: function() {\n" \
"				return !!fired;\n" \
"			}\n" \
"		};\n" \
"\n" \
"	return self;\n" \
"};\n" \
"jQuery.extend({\n" \
"\n" \
"	Deferred: function( func ) {\n" \
"		var tuples = [\n" \
"				// action, add listener, listener list, final state\n" \
"				[ \"resolve\", \"done\", jQuery.Callbacks(\"once memory\"), \"resolved\" ],\n" \
"				[ \"reject\", \"fail\", jQuery.Callbacks(\"once memory\"), \"rejected\" ],\n" \
"				[ \"notify\", \"progress\", jQuery.Callbacks(\"memory\") ]\n" \
"			],\n" \
"			state = \"pending\",\n" \
"			promise = {\n" \
"				state: function() {\n" \
"					return state;\n" \
"				},\n" \
"				always: function() {\n" \
"					deferred.done( arguments ).fail( arguments );\n" \
"					return this;\n" \
"				},\n" \
"				then: function( /* fnDone, fnFail, fnProgress */ ) {\n" \
"					var fns = arguments;\n" \
"					return jQuery.Deferred(function( newDefer ) {\n" \
"						jQuery.each( tuples, function( i, tuple ) {\n" \
"							var action = tuple[ 0 ],\n" \
"								fn = fns[ i ];\n" \
"							// deferred[ done | fail | progress ] for forwarding actions to newDefer\n" \
"							deferred[ tuple[1] ]( jQuery.isFunction( fn ) ?\n" \
"								function() {\n" \
"									var returned = fn.apply( this, arguments );\n" \
"									if ( returned && jQuery.isFunction( returned.promise ) ) {\n" \
"										returned.promise()\n" \
"											.done( newDefer.resolve )\n" \
"											.fail( newDefer.reject )\n" \
"											.progress( newDefer.notify );\n" \
"									} else {\n" \
"										newDefer[ action + \"With\" ]( this === deferred ? newDefer : this, [ returned ] );\n" \
"									}\n" \
"								} :\n" \
"								newDefer[ action ]\n" \
"							);\n" \
"						});\n" \
"						fns = null;\n" \
"					}).promise();\n" \
"				},\n" \
"				// Get a promise for this deferred\n" \
"				// If obj is provided, the promise aspect is added to the object\n" \
"				promise: function( obj ) {\n" \
"					return obj != null ? jQuery.extend( obj, promise ) : promise;\n" \
"				}\n" \
"			},\n" \
"			deferred = {};\n" \
"\n" \
"		// Keep pipe for back-compat\n" \
"		promise.pipe = promise.then;\n" \
"\n" \
"		// Add list-specific methods\n" \
"		jQuery.each( tuples, function( i, tuple ) {\n" \
"			var list = tuple[ 2 ],\n" \
"				stateString = tuple[ 3 ];\n" \
"\n" \
"			// promise[ done | fail | progress ] = list.add\n" \
"			promise[ tuple[1] ] = list.add;\n" \
"\n" \
"			// Handle state\n" \
"			if ( stateString ) {\n" \
"				list.add(function() {\n" \
"					// state = [ resolved | rejected ]\n" \
"					state = stateString;\n" \
"\n" \
"				// [ reject_list | resolve_list ].disable; progress_list.lock\n" \
"				}, tuples[ i ^ 1 ][ 2 ].disable, tuples[ 2 ][ 2 ].lock );\n" \
"			}\n" \
"\n" \
"			// deferred[ resolve | reject | notify ] = list.fire\n" \
"			deferred[ tuple[0] ] = list.fire;\n" \
"			deferred[ tuple[0] + \"With\" ] = list.fireWith;\n" \
"		});\n" \
"\n" \
"		// Make the deferred a promise\n" \
"		promise.promise( deferred );\n" \
"\n" \
"		// Call given func if any\n" \
"		if ( func ) {\n" \
"			func.call( deferred, deferred );\n" \
"		}\n" \
"\n" \
"		// All done!\n" \
"		return deferred;\n" \
"	},\n" \
"\n" \
"	// Deferred helper\n" \
"	when: function( subordinate /* , ..., subordinateN */ ) {\n" \
"		var i = 0,\n" \
"			resolveValues = core_slice.call( arguments ),\n" \
"			length = resolveValues.length,\n" \
"\n" \
"			// the count of uncompleted subordinates\n" \
"			remaining = length !== 1 || ( subordinate && jQuery.isFunction( subordinate.promise ) ) ? length : 0,\n" \
"\n" \
"			// the master Deferred. If resolveValues consist of only a single Deferred, just use that.\n" \
"			deferred = remaining === 1 ? subordinate : jQuery.Deferred(),\n" \
"\n" \
"			// Update function for both resolve and progress values\n" \
"			updateFunc = function( i, contexts, values ) {\n" \
"				return function( value ) {\n" \
"					contexts[ i ] = this;\n" \
"					values[ i ] = arguments.length > 1 ? core_slice.call( arguments ) : value;\n" \
"					if( values === progressValues ) {\n" \
"						deferred.notifyWith( contexts, values );\n" \
"					} else if ( !( --remaining ) ) {\n" \
"						deferred.resolveWith( contexts, values );\n" \
"					}\n" \
"				};\n" \
"			},\n" \
"\n" \
"			progressValues, progressContexts, resolveContexts;\n" \
"\n" \
"		// add listeners to Deferred subordinates; treat others as resolved\n" \
"		if ( length > 1 ) {\n" \
"			progressValues = new Array( length );\n" \
"			progressContexts = new Array( length );\n" \
"			resolveContexts = new Array( length );\n" \
"			for ( ; i < length; i++ ) {\n" \
"				if ( resolveValues[ i ] && jQuery.isFunction( resolveValues[ i ].promise ) ) {\n" \
"					resolveValues[ i ].promise()\n" \
"						.done( updateFunc( i, resolveContexts, resolveValues ) )\n" \
"						.fail( deferred.reject )\n" \
"						.progress( updateFunc( i, progressContexts, progressValues ) );\n" \
"				} else {\n" \
"					--remaining;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// if we're not waiting on anything, resolve the master\n" \
"		if ( !remaining ) {\n" \
"			deferred.resolveWith( resolveContexts, resolveValues );\n" \
"		}\n" \
"\n" \
"		return deferred.promise();\n" \
"	}\n" \
"});\n" \
"jQuery.support = (function() {\n" \
"\n" \
"	var support,\n" \
"		all,\n" \
"		a,\n" \
"		select,\n" \
"		opt,\n" \
"		input,\n" \
"		fragment,\n" \
"		eventName,\n" \
"		i,\n" \
"		isSupported,\n" \
"		clickFn,\n" \
"		div = document.createElement(\"div\");\n" \
"\n" \
"	// Setup\n" \
"	div.setAttribute( \"className\", \"t\" );\n" \
"	div.innerHTML = \"  <link/><table></table><a href='/a'>a</a><input type='checkbox'/>\";\n" \
"\n" \
"	// Support tests won't run in some limited or non-browser environments\n" \
"	all = div.getElementsByTagName(\"*\");\n" \
"	a = div.getElementsByTagName(\"a\")[ 0 ];\n" \
"	if ( !all || !a || !all.length ) {\n" \
"		return {};\n" \
"	}\n" \
"\n" \
"	// First batch of tests\n" \
"	select = document.createElement(\"select\");\n" \
"	opt = select.appendChild( document.createElement(\"option\") );\n" \
"	input = div.getElementsByTagName(\"input\")[ 0 ];\n" \
"\n" \
"	a.style.cssText = \"top:1px;float:left;opacity:.5\";\n" \
"	support = {\n" \
"		// IE strips leading whitespace when .innerHTML is used\n" \
"		leadingWhitespace: ( div.firstChild.nodeType === 3 ),\n" \
"\n" \
"		// Make sure that tbody elements aren't automatically inserted\n" \
"		// IE will insert them into empty tables\n" \
"		tbody: !div.getElementsByTagName(\"tbody\").length,\n" \
"\n" \
"		// Make sure that link elements get serialized correctly by innerHTML\n" \
"		// This requires a wrapper element in IE\n" \
"		htmlSerialize: !!div.getElementsByTagName(\"link\").length,\n" \
"\n" \
"		// Get the style information from getAttribute\n" \
"		// (IE uses .cssText instead)\n" \
"		style: /top/.test( a.getAttribute(\"style\") ),\n" \
"\n" \
"		// Make sure that URLs aren't manipulated\n" \
"		// (IE normalizes it by default)\n" \
"		hrefNormalized: ( a.getAttribute(\"href\") === \"/a\" ),\n" \
"\n" \
"		// Make sure that element opacity exists\n" \
"		// (IE uses filter instead)\n" \
"		// Use a regex to work around a WebKit issue. See #5145\n" \
"		opacity: /^0.5/.test( a.style.opacity ),\n" \
"\n" \
"		// Verify style float existence\n" \
"		// (IE uses styleFloat instead of cssFloat)\n" \
"		cssFloat: !!a.style.cssFloat,\n" \
"\n" \
"		// Make sure that if no value is specified for a checkbox\n" \
"		// that it defaults to \"on\".\n" \
"		// (WebKit defaults to \"\" instead)\n" \
"		checkOn: ( input.value === \"on\" ),\n" \
"\n" \
"		// Make sure that a selected-by-default option has a working selected property.\n" \
"		// (WebKit defaults to false instead of true, IE too, if it's in an optgroup)\n" \
"		optSelected: opt.selected,\n" \
"\n" \
"		// Test setAttribute on camelCase class. If it works, we need attrFixes when doing get/setAttribute (ie6/7)\n" \
"		getSetAttribute: div.className !== \"t\",\n" \
"\n" \
"		// Tests for enctype support on a form (#6743)\n" \
"		enctype: !!document.createElement(\"form\").enctype,\n" \
"\n" \
"		// Makes sure cloning an html5 element does not cause problems\n" \
"		// Where outerHTML is undefined, this still works\n" \
"		html5Clone: document.createElement(\"nav\").cloneNode( true ).outerHTML !== \"<:nav></:nav>\",\n" \
"\n" \
"		// jQuery.support.boxModel DEPRECATED in 1.8 since we don't support Quirks Mode\n" \
"		boxModel: ( document.compatMode === \"CSS1Compat\" ),\n" \
"\n" \
"		// Will be defined later\n" \
"		submitBubbles: true,\n" \
"		changeBubbles: true,\n" \
"		focusinBubbles: false,\n" \
"		deleteExpando: true,\n" \
"		noCloneEvent: true,\n" \
"		inlineBlockNeedsLayout: false,\n" \
"		shrinkWrapBlocks: false,\n" \
"		reliableMarginRight: true,\n" \
"		boxSizingReliable: true,\n" \
"		pixelPosition: false\n" \
"	};\n" \
"\n" \
"	// Make sure checked status is properly cloned\n" \
"	input.checked = true;\n" \
"	support.noCloneChecked = input.cloneNode( true ).checked;\n" \
"\n" \
"	// Make sure that the options inside disabled selects aren't marked as disabled\n" \
"	// (WebKit marks them as disabled)\n" \
"	select.disabled = true;\n" \
"	support.optDisabled = !opt.disabled;\n" \
"\n" \
"	// Test to see if it's possible to delete an expando from an element\n" \
"	// Fails in Internet Explorer\n" \
"	try {\n" \
"		delete div.test;\n" \
"	} catch( e ) {\n" \
"		support.deleteExpando = false;\n" \
"	}\n" \
"\n" \
"	if ( !div.addEventListener && div.attachEvent && div.fireEvent ) {\n" \
"		div.attachEvent( \"onclick\", clickFn = function() {\n" \
"			// Cloning a node shouldn't copy over any\n" \
"			// bound event handlers (IE does this)\n" \
"			support.noCloneEvent = false;\n" \
"		});\n" \
"		div.cloneNode( true ).fireEvent(\"onclick\");\n" \
"		div.detachEvent( \"onclick\", clickFn );\n" \
"	}\n" \
"\n" \
"	// Check if a radio maintains its value\n" \
"	// after being appended to the DOM\n" \
"	input = document.createElement(\"input\");\n" \
"	input.value = \"t\";\n" \
"	input.setAttribute( \"type\", \"radio\" );\n" \
"	support.radioValue = input.value === \"t\";\n" \
"\n" \
"	input.setAttribute( \"checked\", \"checked\" );\n" \
"\n" \
"	// #11217 - WebKit loses check when the name is after the checked attribute\n" \
"	input.setAttribute( \"name\", \"t\" );\n" \
"\n" \
"	div.appendChild( input );\n" \
"	fragment = document.createDocumentFragment();\n" \
"	fragment.appendChild( div.lastChild );\n" \
"\n" \
"	// WebKit doesn't clone checked state correctly in fragments\n" \
"	support.checkClone = fragment.cloneNode( true ).cloneNode( true ).lastChild.checked;\n" \
"\n" \
"	// Check if a disconnected checkbox will retain its checked\n" \
"	// value of true after appended to the DOM (IE6/7)\n" \
"	support.appendChecked = input.checked;\n" \
"\n" \
"	fragment.removeChild( input );\n" \
"	fragment.appendChild( div );\n" \
"\n" \
"	// Technique from Juriy Zaytsev\n" \
"	// http://perfectionkills.com/detecting-event-support-without-browser-sniffing/\n" \
"	// We only care about the case where non-standard event systems\n" \
"	// are used, namely in IE. Short-circuiting here helps us to\n" \
"	// avoid an eval call (in setAttribute) which can cause CSP\n" \
"	// to go haywire. See: https://developer.mozilla.org/en/Security/CSP\n" \
"	if ( div.attachEvent ) {\n" \
"		for ( i in {\n" \
"			submit: true,\n" \
"			change: true,\n" \
"			focusin: true\n" \
"		}) {\n" \
"			eventName = \"on\" + i;\n" \
"			isSupported = ( eventName in div );\n" \
"			if ( !isSupported ) {\n" \
"				div.setAttribute( eventName, \"return;\" );\n" \
"				isSupported = ( typeof div[ eventName ] === \"function\" );\n" \
"			}\n" \
"			support[ i + \"Bubbles\" ] = isSupported;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Run tests that need a body at doc ready\n" \
"	jQuery(function() {\n" \
"		var container, div, tds, marginDiv,\n" \
"			divReset = \"padding:0;margin:0;border:0;display:block;overflow:hidden;\",\n" \
"			body = document.getElementsByTagName(\"body\")[0];\n" \
"\n" \
"		if ( !body ) {\n" \
"			// Return for frameset docs that don't have a body\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		container = document.createElement(\"div\");\n" \
"		container.style.cssText = \"visibility:hidden;border:0;width:0;height:0;position:static;top:0;margin-top:1px\";\n" \
"		body.insertBefore( container, body.firstChild );\n" \
"\n" \
"		// Construct the test element\n" \
"		div = document.createElement(\"div\");\n" \
"		container.appendChild( div );\n" \
"\n" \
"		// Check if table cells still have offsetWidth/Height when they are set\n" \
"		// to display:none and there are still other visible table cells in a\n" \
"		// table row; if so, offsetWidth/Height are not reliable for use when\n" \
"		// determining if an element has been hidden directly using\n" \
"		// display:none (it is still safe to use offsets if a parent element is\n" \
"		// hidden; don safety goggles and see bug #4512 for more information).\n" \
"		// (only IE 8 fails this test)\n" \
"		div.innerHTML = \"<table><tr><td></td><td>t</td></tr></table>\";\n" \
"		tds = div.getElementsByTagName(\"td\");\n" \
"		tds[ 0 ].style.cssText = \"padding:0;margin:0;border:0;display:none\";\n" \
"		isSupported = ( tds[ 0 ].offsetHeight === 0 );\n" \
"\n" \
"		tds[ 0 ].style.display = \"\";\n" \
"		tds[ 1 ].style.display = \"none\";\n" \
"\n" \
"		// Check if empty table cells still have offsetWidth/Height\n" \
"		// (IE <= 8 fail this test)\n" \
"		support.reliableHiddenOffsets = isSupported && ( tds[ 0 ].offsetHeight === 0 );\n" \
"\n" \
"		// Check box-sizing and margin behavior\n" \
"		div.innerHTML = \"\";\n" \
"		div.style.cssText = \"box-sizing:border-box;-moz-box-sizing:border-box;-webkit-box-sizing:border-box;padding:1px;border:1px;display:block;width:4px;margin-top:1%;position:absolute;top:1%;\";\n" \
"		support.boxSizing = ( div.offsetWidth === 4 );\n" \
"		support.doesNotIncludeMarginInBodyOffset = ( body.offsetTop !== 1 );\n" \
"\n" \
"		// NOTE: To any future maintainer, we've window.getComputedStyle\n" \
"		// because jsdom on node.js will break without it.\n" \
"		if ( window.getComputedStyle ) {\n" \
"			support.pixelPosition = ( window.getComputedStyle( div, null ) || {} ).top !== \"1%\";\n" \
"			support.boxSizingReliable = ( window.getComputedStyle( div, null ) || { width: \"4px\" } ).width === \"4px\";\n" \
"\n" \
"			// Check if div with explicit width and no margin-right incorrectly\n" \
"			// gets computed margin-right based on width of container. For more\n" \
"			// info see bug #3333\n" \
"			// Fails in WebKit before Feb 2011 nightlies\n" \
"			// WebKit Bug 13343 - getComputedStyle returns wrong value for margin-right\n" \
"			marginDiv = document.createElement(\"div\");\n" \
"			marginDiv.style.cssText = div.style.cssText = divReset;\n" \
"			marginDiv.style.marginRight = marginDiv.style.width = \"0\";\n" \
"			div.style.width = \"1px\";\n" \
"			div.appendChild( marginDiv );\n" \
"			support.reliableMarginRight =\n" \
"				!parseFloat( ( window.getComputedStyle( marginDiv, null ) || {} ).marginRight );\n" \
"		}\n" \
"\n" \
"		if ( typeof div.style.zoom !== \"undefined\" ) {\n" \
"			// Check if natively block-level elements act like inline-block\n" \
"			// elements when setting their display to 'inline' and giving\n" \
"			// them layout\n" \
"			// (IE < 8 does this)\n" \
"			div.innerHTML = \"\";\n" \
"			div.style.cssText = divReset + \"width:1px;padding:1px;display:inline;zoom:1\";\n" \
"			support.inlineBlockNeedsLayout = ( div.offsetWidth === 3 );\n" \
"\n" \
"			// Check if elements with layout shrink-wrap their children\n" \
"			// (IE 6 does this)\n" \
"			div.style.display = \"block\";\n" \
"			div.style.overflow = \"visible\";\n" \
"			div.innerHTML = \"<div></div>\";\n" \
"			div.firstChild.style.width = \"5px\";\n" \
"			support.shrinkWrapBlocks = ( div.offsetWidth !== 3 );\n" \
"\n" \
"			container.style.zoom = 1;\n" \
"		}\n" \
"\n" \
"		// Null elements to avoid leaks in IE\n" \
"		body.removeChild( container );\n" \
"		container = div = tds = marginDiv = null;\n" \
"	});\n" \
"\n" \
"	// Null elements to avoid leaks in IE\n" \
"	fragment.removeChild( div );\n" \
"	all = a = select = opt = input = fragment = div = null;\n" \
"\n" \
"	return support;\n" \
"})();\n" \
"var rbrace = /(?:\\{[\\s\\S]*\\}|\\[[\\s\\S]*\\])$/,\n" \
"	rmultiDash = /([A-Z])/g;\n" \
"\n" \
"jQuery.extend({\n" \
"	cache: {},\n" \
"\n" \
"	deletedIds: [],\n" \
"\n" \
"	// Remove at next major release (1.9/2.0)\n" \
"	uuid: 0,\n" \
"\n" \
"	// Unique for each copy of jQuery on the page\n" \
"	// Non-digits removed to match rinlinejQuery\n" \
"	expando: \"jQuery\" + ( jQuery.fn.jquery + Math.random() ).replace( /\\D/g, \"\" ),\n" \
"\n" \
"	// The following elements throw uncatchable exceptions if you\n" \
"	// attempt to add expando properties to them.\n" \
"	noData: {\n" \
"		\"embed\": true,\n" \
"		// Ban all objects except for Flash (which handle expandos)\n" \
"		\"object\": \"clsid:D27CDB6E-AE6D-11cf-96B8-444553540000\",\n" \
"		\"applet\": true\n" \
"	},\n" \
"\n" \
"	hasData: function( elem ) {\n" \
"		elem = elem.nodeType ? jQuery.cache[ elem[jQuery.expando] ] : elem[ jQuery.expando ];\n" \
"		return !!elem && !isEmptyDataObject( elem );\n" \
"	},\n" \
"\n" \
"	data: function( elem, name, data, pvt /* Internal Use Only */ ) {\n" \
"		if ( !jQuery.acceptData( elem ) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		var thisCache, ret,\n" \
"			internalKey = jQuery.expando,\n" \
"			getByName = typeof name === \"string\",\n" \
"\n" \
"			// We have to handle DOM nodes and JS objects differently because IE6-7\n" \
"			// can't GC object references properly across the DOM-JS boundary\n" \
"			isNode = elem.nodeType,\n" \
"\n" \
"			// Only DOM nodes need the global jQuery cache; JS object data is\n" \
"			// attached directly to the object so GC can occur automatically\n" \
"			cache = isNode ? jQuery.cache : elem,\n" \
"\n" \
"			// Only defining an ID for JS objects if its cache already exists allows\n" \
"			// the code to shortcut on the same path as a DOM node with no cache\n" \
"			id = isNode ? elem[ internalKey ] : elem[ internalKey ] && internalKey;\n" \
"\n" \
"		// Avoid doing any more work than we need to when trying to get data on an\n" \
"		// object that has no data at all\n" \
"		if ( (!id || !cache[id] || (!pvt && !cache[id].data)) && getByName && data === undefined ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		if ( !id ) {\n" \
"			// Only DOM nodes need a new unique ID for each element since their data\n" \
"			// ends up in the global cache\n" \
"			if ( isNode ) {\n" \
"				elem[ internalKey ] = id = jQuery.deletedIds.pop() || jQuery.guid++;\n" \
"			} else {\n" \
"				id = internalKey;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		if ( !cache[ id ] ) {\n" \
"			cache[ id ] = {};\n" \
"\n" \
"			// Avoids exposing jQuery metadata on plain JS objects when the object\n" \
"			// is serialized using JSON.stringify\n" \
"			if ( !isNode ) {\n" \
"				cache[ id ].toJSON = jQuery.noop;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// An object can be passed to jQuery.data instead of a key/value pair; this gets\n" \
"		// shallow copied over onto the existing cache\n" \
"		if ( typeof name === \"object\" || typeof name === \"function\" ) {\n" \
"			if ( pvt ) {\n" \
"				cache[ id ] = jQuery.extend( cache[ id ], name );\n" \
"			} else {\n" \
"				cache[ id ].data = jQuery.extend( cache[ id ].data, name );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		thisCache = cache[ id ];\n" \
"\n" \
"		// jQuery data() is stored in a separate object inside the object's internal data\n" \
"		// cache in order to avoid key collisions between internal data and user-defined\n" \
"		// data.\n" \
"		if ( !pvt ) {\n" \
"			if ( !thisCache.data ) {\n" \
"				thisCache.data = {};\n" \
"			}\n" \
"\n" \
"			thisCache = thisCache.data;\n" \
"		}\n" \
"\n" \
"		if ( data !== undefined ) {\n" \
"			thisCache[ jQuery.camelCase( name ) ] = data;\n" \
"		}\n" \
"\n" \
"		// Check for both converted-to-camel and non-converted data property names\n" \
"		// If a data property was specified\n" \
"		if ( getByName ) {\n" \
"\n" \
"			// First Try to find as-is property data\n" \
"			ret = thisCache[ name ];\n" \
"\n" \
"			// Test for null|undefined property data\n" \
"			if ( ret == null ) {\n" \
"\n" \
"				// Try to find the camelCased property\n" \
"				ret = thisCache[ jQuery.camelCase( name ) ];\n" \
"			}\n" \
"		} else {\n" \
"			ret = thisCache;\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	removeData: function( elem, name, pvt /* Internal Use Only */ ) {\n" \
"		if ( !jQuery.acceptData( elem ) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		var thisCache, i, l,\n" \
"\n" \
"			isNode = elem.nodeType,\n" \
"\n" \
"			// See jQuery.data for more information\n" \
"			cache = isNode ? jQuery.cache : elem,\n" \
"			id = isNode ? elem[ jQuery.expando ] : jQuery.expando;\n" \
"\n" \
"		// If there is already no cache entry for this object, there is no\n" \
"		// purpose in continuing\n" \
"		if ( !cache[ id ] ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		if ( name ) {\n" \
"\n" \
"			thisCache = pvt ? cache[ id ] : cache[ id ].data;\n" \
"\n" \
"			if ( thisCache ) {\n" \
"\n" \
"				// Support array or space separated string names for data keys\n" \
"				if ( !jQuery.isArray( name ) ) {\n" \
"\n" \
"					// try the string as a key before any manipulation\n" \
"					if ( name in thisCache ) {\n" \
"						name = [ name ];\n" \
"					} else {\n" \
"\n" \
"						// split the camel cased version by spaces unless a key with the spaces exists\n" \
"						name = jQuery.camelCase( name );\n" \
"						if ( name in thisCache ) {\n" \
"							name = [ name ];\n" \
"						} else {\n" \
"							name = name.split(\" \");\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"\n" \
"				for ( i = 0, l = name.length; i < l; i++ ) {\n" \
"					delete thisCache[ name[i] ];\n" \
"				}\n" \
"\n" \
"				// If there is no data left in the cache, we want to continue\n" \
"				// and let the cache object itself get destroyed\n" \
"				if ( !( pvt ? isEmptyDataObject : jQuery.isEmptyObject )( thisCache ) ) {\n" \
"					return;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// See jQuery.data for more information\n" \
"		if ( !pvt ) {\n" \
"			delete cache[ id ].data;\n" \
"\n" \
"			// Don't destroy the parent cache unless the internal data object\n" \
"			// had been the only thing left in it\n" \
"			if ( !isEmptyDataObject( cache[ id ] ) ) {\n" \
"				return;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Destroy the cache\n" \
"		if ( isNode ) {\n" \
"			jQuery.cleanData( [ elem ], true );\n" \
"\n" \
"		// Use delete when supported for expandos or `cache` is not a window per isWindow (#10080)\n" \
"		} else if ( jQuery.support.deleteExpando || cache != cache.window ) {\n" \
"			delete cache[ id ];\n" \
"\n" \
"		// When all else fails, null\n" \
"		} else {\n" \
"			cache[ id ] = null;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// For internal use only.\n" \
"	_data: function( elem, name, data ) {\n" \
"		return jQuery.data( elem, name, data, true );\n" \
"	},\n" \
"\n" \
"	// A method for determining if a DOM node can handle the data expando\n" \
"	acceptData: function( elem ) {\n" \
"		var noData = elem.nodeName && jQuery.noData[ elem.nodeName.toLowerCase() ];\n" \
"\n" \
"		// nodes accept data unless otherwise specified; rejection can be conditional\n" \
"		return !noData || noData !== true && elem.getAttribute(\"classid\") === noData;\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	data: function( key, value ) {\n" \
"		var parts, part, attr, name, l,\n" \
"			elem = this[0],\n" \
"			i = 0,\n" \
"			data = null;\n" \
"\n" \
"		// Gets all values\n" \
"		if ( key === undefined ) {\n" \
"			if ( this.length ) {\n" \
"				data = jQuery.data( elem );\n" \
"\n" \
"				if ( elem.nodeType === 1 && !jQuery._data( elem, \"parsedAttrs\" ) ) {\n" \
"					attr = elem.attributes;\n" \
"					for ( l = attr.length; i < l; i++ ) {\n" \
"						name = attr[i].name;\n" \
"\n" \
"						if ( !name.indexOf( \"data-\" ) ) {\n" \
"							name = jQuery.camelCase( name.substring(5) );\n" \
"\n" \
"							dataAttr( elem, name, data[ name ] );\n" \
"						}\n" \
"					}\n" \
"					jQuery._data( elem, \"parsedAttrs\", true );\n" \
"				}\n" \
"			}\n" \
"\n" \
"			return data;\n" \
"		}\n" \
"\n" \
"		// Sets multiple values\n" \
"		if ( typeof key === \"object\" ) {\n" \
"			return this.each(function() {\n" \
"				jQuery.data( this, key );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		parts = key.split( \".\", 2 );\n" \
"		parts[1] = parts[1] ? \".\" + parts[1] : \"\";\n" \
"		part = parts[1] + \"!\";\n" \
"\n" \
"		return jQuery.access( this, function( value ) {\n" \
"\n" \
"			if ( value === undefined ) {\n" \
"				data = this.triggerHandler( \"getData\" + part, [ parts[0] ] );\n" \
"\n" \
"				// Try to fetch any internally stored data first\n" \
"				if ( data === undefined && elem ) {\n" \
"					data = jQuery.data( elem, key );\n" \
"					data = dataAttr( elem, key, data );\n" \
"				}\n" \
"\n" \
"				return data === undefined && parts[1] ?\n" \
"					this.data( parts[0] ) :\n" \
"					data;\n" \
"			}\n" \
"\n" \
"			parts[1] = value;\n" \
"			this.each(function() {\n" \
"				var self = jQuery( this );\n" \
"\n" \
"				self.triggerHandler( \"setData\" + part, parts );\n" \
"				jQuery.data( this, key, value );\n" \
"				self.triggerHandler( \"changeData\" + part, parts );\n" \
"			});\n" \
"		}, null, value, arguments.length > 1, null, false );\n" \
"	},\n" \
"\n" \
"	removeData: function( key ) {\n" \
"		return this.each(function() {\n" \
"			jQuery.removeData( this, key );\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"function dataAttr( elem, key, data ) {\n" \
"	// If nothing was found internally, try to fetch any\n" \
"	// data from the HTML5 data-* attribute\n" \
"	if ( data === undefined && elem.nodeType === 1 ) {\n" \
"\n" \
"		var name = \"data-\" + key.replace( rmultiDash, \"-$1\" ).toLowerCase();\n" \
"\n" \
"		data = elem.getAttribute( name );\n" \
"\n" \
"		if ( typeof data === \"string\" ) {\n" \
"			try {\n" \
"				data = data === \"true\" ? true :\n" \
"				data === \"false\" ? false :\n" \
"				data === \"null\" ? null :\n" \
"				// Only convert to a number if it doesn't change the string\n" \
"				+data + \"\" === data ? +data :\n" \
"				rbrace.test( data ) ? jQuery.parseJSON( data ) :\n" \
"					data;\n" \
"			} catch( e ) {}\n" \
"\n" \
"			// Make sure we set the data so it isn't changed later\n" \
"			jQuery.data( elem, key, data );\n" \
"\n" \
"		} else {\n" \
"			data = undefined;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return data;\n" \
"}\n" \
"\n" \
"// checks a cache object for emptiness\n" \
"function isEmptyDataObject( obj ) {\n" \
"	var name;\n" \
"	for ( name in obj ) {\n" \
"\n" \
"		// if the public data object is empty, the private is still empty\n" \
"		if ( name === \"data\" && jQuery.isEmptyObject( obj[name] ) ) {\n" \
"			continue;\n" \
"		}\n" \
"		if ( name !== \"toJSON\" ) {\n" \
"			return false;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return true;\n" \
"}\n" \
"jQuery.extend({\n" \
"	queue: function( elem, type, data ) {\n" \
"		var queue;\n" \
"\n" \
"		if ( elem ) {\n" \
"			type = ( type || \"fx\" ) + \"queue\";\n" \
"			queue = jQuery._data( elem, type );\n" \
"\n" \
"			// Speed up dequeue by getting out quickly if this is just a lookup\n" \
"			if ( data ) {\n" \
"				if ( !queue || jQuery.isArray(data) ) {\n" \
"					queue = jQuery._data( elem, type, jQuery.makeArray(data) );\n" \
"				} else {\n" \
"					queue.push( data );\n" \
"				}\n" \
"			}\n" \
"			return queue || [];\n" \
"		}\n" \
"	},\n" \
"\n" \
"	dequeue: function( elem, type ) {\n" \
"		type = type || \"fx\";\n" \
"\n" \
"		var queue = jQuery.queue( elem, type ),\n" \
"			startLength = queue.length,\n" \
"			fn = queue.shift(),\n" \
"			hooks = jQuery._queueHooks( elem, type ),\n" \
"			next = function() {\n" \
"				jQuery.dequeue( elem, type );\n" \
"			};\n" \
"\n" \
"		// If the fx queue is dequeued, always remove the progress sentinel\n" \
"		if ( fn === \"inprogress\" ) {\n" \
"			fn = queue.shift();\n" \
"			startLength--;\n" \
"		}\n" \
"\n" \
"		if ( fn ) {\n" \
"\n" \
"			// Add a progress sentinel to prevent the fx queue from being\n" \
"			// automatically dequeued\n" \
"			if ( type === \"fx\" ) {\n" \
"				queue.unshift( \"inprogress\" );\n" \
"			}\n" \
"\n" \
"			// clear up the last queue stop function\n" \
"			delete hooks.stop;\n" \
"			fn.call( elem, next, hooks );\n" \
"		}\n" \
"\n" \
"		if ( !startLength && hooks ) {\n" \
"			hooks.empty.fire();\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// not intended for public consumption - generates a queueHooks object, or returns the current one\n" \
"	_queueHooks: function( elem, type ) {\n" \
"		var key = type + \"queueHooks\";\n" \
"		return jQuery._data( elem, key ) || jQuery._data( elem, key, {\n" \
"			empty: jQuery.Callbacks(\"once memory\").add(function() {\n" \
"				jQuery.removeData( elem, type + \"queue\", true );\n" \
"				jQuery.removeData( elem, key, true );\n" \
"			})\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	queue: function( type, data ) {\n" \
"		var setter = 2;\n" \
"\n" \
"		if ( typeof type !== \"string\" ) {\n" \
"			data = type;\n" \
"			type = \"fx\";\n" \
"			setter--;\n" \
"		}\n" \
"\n" \
"		if ( arguments.length < setter ) {\n" \
"			return jQuery.queue( this[0], type );\n" \
"		}\n" \
"\n" \
"		return data === undefined ?\n" \
"			this :\n" \
"			this.each(function() {\n" \
"				var queue = jQuery.queue( this, type, data );\n" \
"\n" \
"				// ensure a hooks for this queue\n" \
"				jQuery._queueHooks( this, type );\n" \
"\n" \
"				if ( type === \"fx\" && queue[0] !== \"inprogress\" ) {\n" \
"					jQuery.dequeue( this, type );\n" \
"				}\n" \
"			});\n" \
"	},\n" \
"	dequeue: function( type ) {\n" \
"		return this.each(function() {\n" \
"			jQuery.dequeue( this, type );\n" \
"		});\n" \
"	},\n" \
"	// Based off of the plugin by Clint Helfers, with permission.\n" \
"	// http://blindsignals.com/index.php/2009/07/jquery-delay/\n" \
"	delay: function( time, type ) {\n" \
"		time = jQuery.fx ? jQuery.fx.speeds[ time ] || time : time;\n" \
"		type = type || \"fx\";\n" \
"\n" \
"		return this.queue( type, function( next, hooks ) {\n" \
"			var timeout = setTimeout( next, time );\n" \
"			hooks.stop = function() {\n" \
"				clearTimeout( timeout );\n" \
"			};\n" \
"		});\n" \
"	},\n" \
"	clearQueue: function( type ) {\n" \
"		return this.queue( type || \"fx\", [] );\n" \
"	},\n" \
"	// Get a promise resolved when queues of a certain type\n" \
"	// are emptied (fx is the type by default)\n" \
"	promise: function( type, obj ) {\n" \
"		var tmp,\n" \
"			count = 1,\n" \
"			defer = jQuery.Deferred(),\n" \
"			elements = this,\n" \
"			i = this.length,\n" \
"			resolve = function() {\n" \
"				if ( !( --count ) ) {\n" \
"					defer.resolveWith( elements, [ elements ] );\n" \
"				}\n" \
"			};\n" \
"\n" \
"		if ( typeof type !== \"string\" ) {\n" \
"			obj = type;\n" \
"			type = undefined;\n" \
"		}\n" \
"		type = type || \"fx\";\n" \
"\n" \
"		while( i-- ) {\n" \
"			tmp = jQuery._data( elements[ i ], type + \"queueHooks\" );\n" \
"			if ( tmp && tmp.empty ) {\n" \
"				count++;\n" \
"				tmp.empty.add( resolve );\n" \
"			}\n" \
"		}\n" \
"		resolve();\n" \
"		return defer.promise( obj );\n" \
"	}\n" \
"});\n" \
"var nodeHook, boolHook, fixSpecified,\n" \
"	rclass = /[\\t\\r\\n]/g,\n" \
"	rreturn = /\\r/g,\n" \
"	rtype = /^(?:button|input)$/i,\n" \
"	rfocusable = /^(?:button|input|object|select|textarea)$/i,\n" \
"	rclickable = /^a(?:rea|)$/i,\n" \
"	rboolean = /^(?:autofocus|autoplay|async|checked|controls|defer|disabled|hidden|loop|multiple|open|readonly|required|scoped|selected)$/i,\n" \
"	getSetAttribute = jQuery.support.getSetAttribute;\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	attr: function( name, value ) {\n" \
"		return jQuery.access( this, jQuery.attr, name, value, arguments.length > 1 );\n" \
"	},\n" \
"\n" \
"	removeAttr: function( name ) {\n" \
"		return this.each(function() {\n" \
"			jQuery.removeAttr( this, name );\n" \
"		});\n" \
"	},\n" \
"\n" \
"	prop: function( name, value ) {\n" \
"		return jQuery.access( this, jQuery.prop, name, value, arguments.length > 1 );\n" \
"	},\n" \
"\n" \
"	removeProp: function( name ) {\n" \
"		name = jQuery.propFix[ name ] || name;\n" \
"		return this.each(function() {\n" \
"			// try/catch handles cases where IE balks (such as removing a property on window)\n" \
"			try {\n" \
"				this[ name ] = undefined;\n" \
"				delete this[ name ];\n" \
"			} catch( e ) {}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	addClass: function( value ) {\n" \
"		var classNames, i, l, elem,\n" \
"			setClass, c, cl;\n" \
"\n" \
"		if ( jQuery.isFunction( value ) ) {\n" \
"			return this.each(function( j ) {\n" \
"				jQuery( this ).addClass( value.call(this, j, this.className) );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( value && typeof value === \"string\" ) {\n" \
"			classNames = value.split( core_rspace );\n" \
"\n" \
"			for ( i = 0, l = this.length; i < l; i++ ) {\n" \
"				elem = this[ i ];\n" \
"\n" \
"				if ( elem.nodeType === 1 ) {\n" \
"					if ( !elem.className && classNames.length === 1 ) {\n" \
"						elem.className = value;\n" \
"\n" \
"					} else {\n" \
"						setClass = \" \" + elem.className + \" \";\n" \
"\n" \
"						for ( c = 0, cl = classNames.length; c < cl; c++ ) {\n" \
"							if ( setClass.indexOf( \" \" + classNames[ c ] + \" \" ) < 0 ) {\n" \
"								setClass += classNames[ c ] + \" \";\n" \
"							}\n" \
"						}\n" \
"						elem.className = jQuery.trim( setClass );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	removeClass: function( value ) {\n" \
"		var removes, className, elem, c, cl, i, l;\n" \
"\n" \
"		if ( jQuery.isFunction( value ) ) {\n" \
"			return this.each(function( j ) {\n" \
"				jQuery( this ).removeClass( value.call(this, j, this.className) );\n" \
"			});\n" \
"		}\n" \
"		if ( (value && typeof value === \"string\") || value === undefined ) {\n" \
"			removes = ( value || \"\" ).split( core_rspace );\n" \
"\n" \
"			for ( i = 0, l = this.length; i < l; i++ ) {\n" \
"				elem = this[ i ];\n" \
"				if ( elem.nodeType === 1 && elem.className ) {\n" \
"\n" \
"					className = (\" \" + elem.className + \" \").replace( rclass, \" \" );\n" \
"\n" \
"					// loop over each item in the removal list\n" \
"					for ( c = 0, cl = removes.length; c < cl; c++ ) {\n" \
"						// Remove until there is nothing to remove,\n" \
"						while ( className.indexOf(\" \" + removes[ c ] + \" \") >= 0 ) {\n" \
"							className = className.replace( \" \" + removes[ c ] + \" \" , \" \" );\n" \
"						}\n" \
"					}\n" \
"					elem.className = value ? jQuery.trim( className ) : \"\";\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	toggleClass: function( value, stateVal ) {\n" \
"		var type = typeof value,\n" \
"			isBool = typeof stateVal === \"boolean\";\n" \
"\n" \
"		if ( jQuery.isFunction( value ) ) {\n" \
"			return this.each(function( i ) {\n" \
"				jQuery( this ).toggleClass( value.call(this, i, this.className, stateVal), stateVal );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		return this.each(function() {\n" \
"			if ( type === \"string\" ) {\n" \
"				// toggle individual class names\n" \
"				var className,\n" \
"					i = 0,\n" \
"					self = jQuery( this ),\n" \
"					state = stateVal,\n" \
"					classNames = value.split( core_rspace );\n" \
"\n" \
"				while ( (className = classNames[ i++ ]) ) {\n" \
"					// check each className given, space separated list\n" \
"					state = isBool ? state : !self.hasClass( className );\n" \
"					self[ state ? \"addClass\" : \"removeClass\" ]( className );\n" \
"				}\n" \
"\n" \
"			} else if ( type === \"undefined\" || type === \"boolean\" ) {\n" \
"				if ( this.className ) {\n" \
"					// store className if set\n" \
"					jQuery._data( this, \"__className__\", this.className );\n" \
"				}\n" \
"\n" \
"				// toggle whole className\n" \
"				this.className = this.className || value === false ? \"\" : jQuery._data( this, \"__className__\" ) || \"\";\n" \
"			}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	hasClass: function( selector ) {\n" \
"		var className = \" \" + selector + \" \",\n" \
"			i = 0,\n" \
"			l = this.length;\n" \
"		for ( ; i < l; i++ ) {\n" \
"			if ( this[i].nodeType === 1 && (\" \" + this[i].className + \" \").replace(rclass, \" \").indexOf( className ) >= 0 ) {\n" \
"				return true;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return false;\n" \
"	},\n" \
"\n" \
"	val: function( value ) {\n" \
"		var hooks, ret, isFunction,\n" \
"			elem = this[0];\n" \
"\n" \
"		if ( !arguments.length ) {\n" \
"			if ( elem ) {\n" \
"				hooks = jQuery.valHooks[ elem.type ] || jQuery.valHooks[ elem.nodeName.toLowerCase() ];\n" \
"\n" \
"				if ( hooks && \"get\" in hooks && (ret = hooks.get( elem, \"value\" )) !== undefined ) {\n" \
"					return ret;\n" \
"				}\n" \
"\n" \
"				ret = elem.value;\n" \
"\n" \
"				return typeof ret === \"string\" ?\n" \
"					// handle most common string cases\n" \
"					ret.replace(rreturn, \"\") :\n" \
"					// handle cases where value is null/undef or number\n" \
"					ret == null ? \"\" : ret;\n" \
"			}\n" \
"\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		isFunction = jQuery.isFunction( value );\n" \
"\n" \
"		return this.each(function( i ) {\n" \
"			var val,\n" \
"				self = jQuery(this);\n" \
"\n" \
"			if ( this.nodeType !== 1 ) {\n" \
"				return;\n" \
"			}\n" \
"\n" \
"			if ( isFunction ) {\n" \
"				val = value.call( this, i, self.val() );\n" \
"			} else {\n" \
"				val = value;\n" \
"			}\n" \
"\n" \
"			// Treat null/undefined as \"\"; convert numbers to string\n" \
"			if ( val == null ) {\n" \
"				val = \"\";\n" \
"			} else if ( typeof val === \"number\" ) {\n" \
"				val += \"\";\n" \
"			} else if ( jQuery.isArray( val ) ) {\n" \
"				val = jQuery.map(val, function ( value ) {\n" \
"					return value == null ? \"\" : value + \"\";\n" \
"				});\n" \
"			}\n" \
"\n" \
"			hooks = jQuery.valHooks[ this.type ] || jQuery.valHooks[ this.nodeName.toLowerCase() ];\n" \
"\n" \
"			// If set returns undefined, fall back to normal setting\n" \
"			if ( !hooks || !(\"set\" in hooks) || hooks.set( this, val, \"value\" ) === undefined ) {\n" \
"				this.value = val;\n" \
"			}\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.extend({\n" \
"	valHooks: {\n" \
"		option: {\n" \
"			get: function( elem ) {\n" \
"				// attributes.value is undefined in Blackberry 4.7 but\n" \
"				// uses .value. See #6932\n" \
"				var val = elem.attributes.value;\n" \
"				return !val || val.specified ? elem.value : elem.text;\n" \
"			}\n" \
"		},\n" \
"		select: {\n" \
"			get: function( elem ) {\n" \
"				var value, option,\n" \
"					options = elem.options,\n" \
"					index = elem.selectedIndex,\n" \
"					one = elem.type === \"select-one\" || index < 0,\n" \
"					values = one ? null : [],\n" \
"					max = one ? index + 1 : options.length,\n" \
"					i = index < 0 ?\n" \
"						max :\n" \
"						one ? index : 0;\n" \
"\n" \
"				// Loop through all the selected options\n" \
"				for ( ; i < max; i++ ) {\n" \
"					option = options[ i ];\n" \
"\n" \
"					// oldIE doesn't update selected after form reset (#2551)\n" \
"					if ( ( option.selected || i === index ) &&\n" \
"							// Don't return options that are disabled or in a disabled optgroup\n" \
"							( jQuery.support.optDisabled ? !option.disabled : option.getAttribute(\"disabled\") === null ) &&\n" \
"							( !option.parentNode.disabled || !jQuery.nodeName( option.parentNode, \"optgroup\" ) ) ) {\n" \
"\n" \
"						// Get the specific value for the option\n" \
"						value = jQuery( option ).val();\n" \
"\n" \
"						// We don't need an array for one selects\n" \
"						if ( one ) {\n" \
"							return value;\n" \
"						}\n" \
"\n" \
"						// Multi-Selects return an array\n" \
"						values.push( value );\n" \
"					}\n" \
"				}\n" \
"\n" \
"				return values;\n" \
"			},\n" \
"\n" \
"			set: function( elem, value ) {\n" \
"				var values = jQuery.makeArray( value );\n" \
"\n" \
"				jQuery(elem).find(\"option\").each(function() {\n" \
"					this.selected = jQuery.inArray( jQuery(this).val(), values ) >= 0;\n" \
"				});\n" \
"\n" \
"				if ( !values.length ) {\n" \
"					elem.selectedIndex = -1;\n" \
"				}\n" \
"				return values;\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Unused in 1.8, left in so attrFn-stabbers won't die; remove in 1.9\n" \
"	attrFn: {},\n" \
"\n" \
"	attr: function( elem, name, value, pass ) {\n" \
"		var ret, hooks, notxml,\n" \
"			nType = elem.nodeType;\n" \
"\n" \
"		// don't get/set attributes on text, comment and attribute nodes\n" \
"		if ( !elem || nType === 3 || nType === 8 || nType === 2 ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		if ( pass && jQuery.isFunction( jQuery.fn[ name ] ) ) {\n" \
"			return jQuery( elem )[ name ]( value );\n" \
"		}\n" \
"\n" \
"		// Fallback to prop when attributes are not supported\n" \
"		if ( typeof elem.getAttribute === \"undefined\" ) {\n" \
"			return jQuery.prop( elem, name, value );\n" \
"		}\n" \
"\n" \
"		notxml = nType !== 1 || !jQuery.isXMLDoc( elem );\n" \
"\n" \
"		// All attributes are lowercase\n" \
"		// Grab necessary hook if one is defined\n" \
"		if ( notxml ) {\n" \
"			name = name.toLowerCase();\n" \
"			hooks = jQuery.attrHooks[ name ] || ( rboolean.test( name ) ? boolHook : nodeHook );\n" \
"		}\n" \
"\n" \
"		if ( value !== undefined ) {\n" \
"\n" \
"			if ( value === null ) {\n" \
"				jQuery.removeAttr( elem, name );\n" \
"				return;\n" \
"\n" \
"			} else if ( hooks && \"set\" in hooks && notxml && (ret = hooks.set( elem, value, name )) !== undefined ) {\n" \
"				return ret;\n" \
"\n" \
"			} else {\n" \
"				elem.setAttribute( name, value + \"\" );\n" \
"				return value;\n" \
"			}\n" \
"\n" \
"		} else if ( hooks && \"get\" in hooks && notxml && (ret = hooks.get( elem, name )) !== null ) {\n" \
"			return ret;\n" \
"\n" \
"		} else {\n" \
"\n" \
"			ret = elem.getAttribute( name );\n" \
"\n" \
"			// Non-existent attributes return null, we normalize to undefined\n" \
"			return ret === null ?\n" \
"				undefined :\n" \
"				ret;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	removeAttr: function( elem, value ) {\n" \
"		var propName, attrNames, name, isBool,\n" \
"			i = 0;\n" \
"\n" \
"		if ( value && elem.nodeType === 1 ) {\n" \
"\n" \
"			attrNames = value.split( core_rspace );\n" \
"\n" \
"			for ( ; i < attrNames.length; i++ ) {\n" \
"				name = attrNames[ i ];\n" \
"\n" \
"				if ( name ) {\n" \
"					propName = jQuery.propFix[ name ] || name;\n" \
"					isBool = rboolean.test( name );\n" \
"\n" \
"					// See #9699 for explanation of this approach (setting first, then removal)\n" \
"					// Do not do this for boolean attributes (see #10870)\n" \
"					if ( !isBool ) {\n" \
"						jQuery.attr( elem, name, \"\" );\n" \
"					}\n" \
"					elem.removeAttribute( getSetAttribute ? name : propName );\n" \
"\n" \
"					// Set corresponding property to false for boolean attributes\n" \
"					if ( isBool && propName in elem ) {\n" \
"						elem[ propName ] = false;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	attrHooks: {\n" \
"		type: {\n" \
"			set: function( elem, value ) {\n" \
"				// We can't allow the type property to be changed (since it causes problems in IE)\n" \
"				if ( rtype.test( elem.nodeName ) && elem.parentNode ) {\n" \
"					jQuery.error( \"type property can't be changed\" );\n" \
"				} else if ( !jQuery.support.radioValue && value === \"radio\" && jQuery.nodeName(elem, \"input\") ) {\n" \
"					// Setting the type on a radio button after the value resets the value in IE6-9\n" \
"					// Reset value to it's default in case type is set after value\n" \
"					// This is for element creation\n" \
"					var val = elem.value;\n" \
"					elem.setAttribute( \"type\", value );\n" \
"					if ( val ) {\n" \
"						elem.value = val;\n" \
"					}\n" \
"					return value;\n" \
"				}\n" \
"			}\n" \
"		},\n" \
"		// Use the value property for back compat\n" \
"		// Use the nodeHook for button elements in IE6/7 (#1954)\n" \
"		value: {\n" \
"			get: function( elem, name ) {\n" \
"				if ( nodeHook && jQuery.nodeName( elem, \"button\" ) ) {\n" \
"					return nodeHook.get( elem, name );\n" \
"				}\n" \
"				return name in elem ?\n" \
"					elem.value :\n" \
"					null;\n" \
"			},\n" \
"			set: function( elem, value, name ) {\n" \
"				if ( nodeHook && jQuery.nodeName( elem, \"button\" ) ) {\n" \
"					return nodeHook.set( elem, value, name );\n" \
"				}\n" \
"				// Does not return so that setAttribute is also used\n" \
"				elem.value = value;\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	propFix: {\n" \
"		tabindex: \"tabIndex\",\n" \
"		readonly: \"readOnly\",\n" \
"		\"for\": \"htmlFor\",\n" \
"		\"class\": \"className\",\n" \
"		maxlength: \"maxLength\",\n" \
"		cellspacing: \"cellSpacing\",\n" \
"		cellpadding: \"cellPadding\",\n" \
"		rowspan: \"rowSpan\",\n" \
"		colspan: \"colSpan\",\n" \
"		usemap: \"useMap\",\n" \
"		frameborder: \"frameBorder\",\n" \
"		contenteditable: \"contentEditable\"\n" \
"	},\n" \
"\n" \
"	prop: function( elem, name, value ) {\n" \
"		var ret, hooks, notxml,\n" \
"			nType = elem.nodeType;\n" \
"\n" \
"		// don't get/set properties on text, comment and attribute nodes\n" \
"		if ( !elem || nType === 3 || nType === 8 || nType === 2 ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		notxml = nType !== 1 || !jQuery.isXMLDoc( elem );\n" \
"\n" \
"		if ( notxml ) {\n" \
"			// Fix name and attach hooks\n" \
"			name = jQuery.propFix[ name ] || name;\n" \
"			hooks = jQuery.propHooks[ name ];\n" \
"		}\n" \
"\n" \
"		if ( value !== undefined ) {\n" \
"			if ( hooks && \"set\" in hooks && (ret = hooks.set( elem, value, name )) !== undefined ) {\n" \
"				return ret;\n" \
"\n" \
"			} else {\n" \
"				return ( elem[ name ] = value );\n" \
"			}\n" \
"\n" \
"		} else {\n" \
"			if ( hooks && \"get\" in hooks && (ret = hooks.get( elem, name )) !== null ) {\n" \
"				return ret;\n" \
"\n" \
"			} else {\n" \
"				return elem[ name ];\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	propHooks: {\n" \
"		tabIndex: {\n" \
"			get: function( elem ) {\n" \
"				// elem.tabIndex doesn't always return the correct value when it hasn't been explicitly set\n" \
"				// http://fluidproject.org/blog/2008/01/09/getting-setting-and-removing-tabindex-values-with-javascript/\n" \
"				var attributeNode = elem.getAttributeNode(\"tabindex\");\n" \
"\n" \
"				return attributeNode && attributeNode.specified ?\n" \
"					parseInt( attributeNode.value, 10 ) :\n" \
"					rfocusable.test( elem.nodeName ) || rclickable.test( elem.nodeName ) && elem.href ?\n" \
"						0 :\n" \
"						undefined;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"});\n" \
"\n" \
"// Hook for boolean attributes\n" \
"boolHook = {\n" \
"	get: function( elem, name ) {\n" \
"		// Align boolean attributes with corresponding properties\n" \
"		// Fall back to attribute presence where some booleans are not supported\n" \
"		var attrNode,\n" \
"			property = jQuery.prop( elem, name );\n" \
"		return property === true || typeof property !== \"boolean\" && ( attrNode = elem.getAttributeNode(name) ) && attrNode.nodeValue !== false ?\n" \
"			name.toLowerCase() :\n" \
"			undefined;\n" \
"	},\n" \
"	set: function( elem, value, name ) {\n" \
"		var propName;\n" \
"		if ( value === false ) {\n" \
"			// Remove boolean attributes when set to false\n" \
"			jQuery.removeAttr( elem, name );\n" \
"		} else {\n" \
"			// value is true since we know at this point it's type boolean and not false\n" \
"			// Set boolean attributes to the same name and set the DOM property\n" \
"			propName = jQuery.propFix[ name ] || name;\n" \
"			if ( propName in elem ) {\n" \
"				// Only set the IDL specifically if it already exists on the element\n" \
"				elem[ propName ] = true;\n" \
"			}\n" \
"\n" \
"			elem.setAttribute( name, name.toLowerCase() );\n" \
"		}\n" \
"		return name;\n" \
"	}\n" \
"};\n" \
"\n" \
"// IE6/7 do not support getting/setting some attributes with get/setAttribute\n" \
"if ( !getSetAttribute ) {\n" \
"\n" \
"	fixSpecified = {\n" \
"		name: true,\n" \
"		id: true,\n" \
"		coords: true\n" \
"	};\n" \
"\n" \
"	// Use this for any attribute in IE6/7\n" \
"	// This fixes almost every IE6/7 issue\n" \
"	nodeHook = jQuery.valHooks.button = {\n" \
"		get: function( elem, name ) {\n" \
"			var ret;\n" \
"			ret = elem.getAttributeNode( name );\n" \
"			return ret && ( fixSpecified[ name ] ? ret.value !== \"\" : ret.specified ) ?\n" \
"				ret.value :\n" \
"				undefined;\n" \
"		},\n" \
"		set: function( elem, value, name ) {\n" \
"			// Set the existing or create a new attribute node\n" \
"			var ret = elem.getAttributeNode( name );\n" \
"			if ( !ret ) {\n" \
"				ret = document.createAttribute( name );\n" \
"				elem.setAttributeNode( ret );\n" \
"			}\n" \
"			return ( ret.value = value + \"\" );\n" \
"		}\n" \
"	};\n" \
"\n" \
"	// Set width and height to auto instead of 0 on empty string( Bug #8150 )\n" \
"	// This is for removals\n" \
"	jQuery.each([ \"width\", \"height\" ], function( i, name ) {\n" \
"		jQuery.attrHooks[ name ] = jQuery.extend( jQuery.attrHooks[ name ], {\n" \
"			set: function( elem, value ) {\n" \
"				if ( value === \"\" ) {\n" \
"					elem.setAttribute( name, \"auto\" );\n" \
"					return value;\n" \
"				}\n" \
"			}\n" \
"		});\n" \
"	});\n" \
"\n" \
"	// Set contenteditable to false on removals(#10429)\n" \
"	// Setting to empty string throws an error as an invalid value\n" \
"	jQuery.attrHooks.contenteditable = {\n" \
"		get: nodeHook.get,\n" \
"		set: function( elem, value, name ) {\n" \
"			if ( value === \"\" ) {\n" \
"				value = \"false\";\n" \
"			}\n" \
"			nodeHook.set( elem, value, name );\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"\n" \
"// Some attributes require a special call on IE\n" \
"if ( !jQuery.support.hrefNormalized ) {\n" \
"	jQuery.each([ \"href\", \"src\", \"width\", \"height\" ], function( i, name ) {\n" \
"		jQuery.attrHooks[ name ] = jQuery.extend( jQuery.attrHooks[ name ], {\n" \
"			get: function( elem ) {\n" \
"				var ret = elem.getAttribute( name, 2 );\n" \
"				return ret === null ? undefined : ret;\n" \
"			}\n" \
"		});\n" \
"	});\n" \
"}\n" \
"\n" \
"if ( !jQuery.support.style ) {\n" \
"	jQuery.attrHooks.style = {\n" \
"		get: function( elem ) {\n" \
"			// Return undefined in the case of empty string\n" \
"			// Normalize to lowercase since IE uppercases css property names\n" \
"			return elem.style.cssText.toLowerCase() || undefined;\n" \
"		},\n" \
"		set: function( elem, value ) {\n" \
"			return ( elem.style.cssText = value + \"\" );\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"// Safari mis-reports the default selected property of an option\n" \
"// Accessing the parent's selectedIndex property fixes it\n" \
"if ( !jQuery.support.optSelected ) {\n" \
"	jQuery.propHooks.selected = jQuery.extend( jQuery.propHooks.selected, {\n" \
"		get: function( elem ) {\n" \
"			var parent = elem.parentNode;\n" \
"\n" \
"			if ( parent ) {\n" \
"				parent.selectedIndex;\n" \
"\n" \
"				// Make sure that it also works with optgroups, see #5701\n" \
"				if ( parent.parentNode ) {\n" \
"					parent.parentNode.selectedIndex;\n" \
"				}\n" \
"			}\n" \
"			return null;\n" \
"		}\n" \
"	});\n" \
"}\n" \
"\n" \
"// IE6/7 call enctype encoding\n" \
"if ( !jQuery.support.enctype ) {\n" \
"	jQuery.propFix.enctype = \"encoding\";\n" \
"}\n" \
"\n" \
"// Radios and checkboxes getter/setter\n" \
"if ( !jQuery.support.checkOn ) {\n" \
"	jQuery.each([ \"radio\", \"checkbox\" ], function() {\n" \
"		jQuery.valHooks[ this ] = {\n" \
"			get: function( elem ) {\n" \
"				// Handle the case where in Webkit \"\" is returned instead of \"on\" if a value isn't specified\n" \
"				return elem.getAttribute(\"value\") === null ? \"on\" : elem.value;\n" \
"			}\n" \
"		};\n" \
"	});\n" \
"}\n" \
"jQuery.each([ \"radio\", \"checkbox\" ], function() {\n" \
"	jQuery.valHooks[ this ] = jQuery.extend( jQuery.valHooks[ this ], {\n" \
"		set: function( elem, value ) {\n" \
"			if ( jQuery.isArray( value ) ) {\n" \
"				return ( elem.checked = jQuery.inArray( jQuery(elem).val(), value ) >= 0 );\n" \
"			}\n" \
"		}\n" \
"	});\n" \
"});\n" \
"var rformElems = /^(?:textarea|input|select)$/i,\n" \
"	rtypenamespace = /^([^\\.]*|)(?:\\.(.+)|)$/,\n" \
"	rhoverHack = /(?:^|\\s)hover(\\.\\S+|)\\b/,\n" \
"	rkeyEvent = /^key/,\n" \
"	rmouseEvent = /^(?:mouse|contextmenu)|click/,\n" \
"	rfocusMorph = /^(?:focusinfocus|focusoutblur)$/,\n" \
"	hoverHack = function( events ) {\n" \
"		return jQuery.event.special.hover ? events : events.replace( rhoverHack, \"mouseenter$1 mouseleave$1\" );\n" \
"	};\n" \
"\n" \
"/*\n" \
" * Helper functions for managing events -- not part of the public interface.\n" \
" * Props to Dean Edwards' addEvent library for many of the ideas.\n" \
" */\n" \
"jQuery.event = {\n" \
"\n" \
"	add: function( elem, types, handler, data, selector ) {\n" \
"\n" \
"		var elemData, eventHandle, events,\n" \
"			t, tns, type, namespaces, handleObj,\n" \
"			handleObjIn, handlers, special;\n" \
"\n" \
"		// Don't attach events to noData or text/comment nodes (allow plain objects tho)\n" \
"		if ( elem.nodeType === 3 || elem.nodeType === 8 || !types || !handler || !(elemData = jQuery._data( elem )) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Caller can pass in an object of custom data in lieu of the handler\n" \
"		if ( handler.handler ) {\n" \
"			handleObjIn = handler;\n" \
"			handler = handleObjIn.handler;\n" \
"			selector = handleObjIn.selector;\n" \
"		}\n" \
"\n" \
"		// Make sure that the handler has a unique ID, used to find/remove it later\n" \
"		if ( !handler.guid ) {\n" \
"			handler.guid = jQuery.guid++;\n" \
"		}\n" \
"\n" \
"		// Init the element's event structure and main handler, if this is the first\n" \
"		events = elemData.events;\n" \
"		if ( !events ) {\n" \
"			elemData.events = events = {};\n" \
"		}\n" \
"		eventHandle = elemData.handle;\n" \
"		if ( !eventHandle ) {\n" \
"			elemData.handle = eventHandle = function( e ) {\n" \
"				// Discard the second event of a jQuery.event.trigger() and\n" \
"				// when an event is called after a page has unloaded\n" \
"				return typeof jQuery !== \"undefined\" && (!e || jQuery.event.triggered !== e.type) ?\n" \
"					jQuery.event.dispatch.apply( eventHandle.elem, arguments ) :\n" \
"					undefined;\n" \
"			};\n" \
"			// Add elem as a property of the handle fn to prevent a memory leak with IE non-native events\n" \
"			eventHandle.elem = elem;\n" \
"		}\n" \
"\n" \
"		// Handle multiple events separated by a space\n" \
"		// jQuery(...).bind(\"mouseover mouseout\", fn);\n" \
"		types = jQuery.trim( hoverHack(types) ).split( \" \" );\n" \
"		for ( t = 0; t < types.length; t++ ) {\n" \
"\n" \
"			tns = rtypenamespace.exec( types[t] ) || [];\n" \
"			type = tns[1];\n" \
"			namespaces = ( tns[2] || \"\" ).split( \".\" ).sort();\n" \
"\n" \
"			// If event changes its type, use the special event handlers for the changed type\n" \
"			special = jQuery.event.special[ type ] || {};\n" \
"\n" \
"			// If selector defined, determine special event api type, otherwise given type\n" \
"			type = ( selector ? special.delegateType : special.bindType ) || type;\n" \
"\n" \
"			// Update special based on newly reset type\n" \
"			special = jQuery.event.special[ type ] || {};\n" \
"\n" \
"			// handleObj is passed to all event handlers\n" \
"			handleObj = jQuery.extend({\n" \
"				type: type,\n" \
"				origType: tns[1],\n" \
"				data: data,\n" \
"				handler: handler,\n" \
"				guid: handler.guid,\n" \
"				selector: selector,\n" \
"				needsContext: selector && jQuery.expr.match.needsContext.test( selector ),\n" \
"				namespace: namespaces.join(\".\")\n" \
"			}, handleObjIn );\n" \
"\n" \
"			// Init the event handler queue if we're the first\n" \
"			handlers = events[ type ];\n" \
"			if ( !handlers ) {\n" \
"				handlers = events[ type ] = [];\n" \
"				handlers.delegateCount = 0;\n" \
"\n" \
"				// Only use addEventListener/attachEvent if the special events handler returns false\n" \
"				if ( !special.setup || special.setup.call( elem, data, namespaces, eventHandle ) === false ) {\n" \
"					// Bind the global event handler to the element\n" \
"					if ( elem.addEventListener ) {\n" \
"						elem.addEventListener( type, eventHandle, false );\n" \
"\n" \
"					} else if ( elem.attachEvent ) {\n" \
"						elem.attachEvent( \"on\" + type, eventHandle );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			if ( special.add ) {\n" \
"				special.add.call( elem, handleObj );\n" \
"\n" \
"				if ( !handleObj.handler.guid ) {\n" \
"					handleObj.handler.guid = handler.guid;\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Add to the element's handler list, delegates in front\n" \
"			if ( selector ) {\n" \
"				handlers.splice( handlers.delegateCount++, 0, handleObj );\n" \
"			} else {\n" \
"				handlers.push( handleObj );\n" \
"			}\n" \
"\n" \
"			// Keep track of which events have ever been used, for event optimization\n" \
"			jQuery.event.global[ type ] = true;\n" \
"		}\n" \
"\n" \
"		// Nullify elem to prevent memory leaks in IE\n" \
"		elem = null;\n" \
"	},\n" \
"\n" \
"	global: {},\n" \
"\n" \
"	// Detach an event or set of events from an element\n" \
"	remove: function( elem, types, handler, selector, mappedTypes ) {\n" \
"\n" \
"		var t, tns, type, origType, namespaces, origCount,\n" \
"			j, events, special, eventType, handleObj,\n" \
"			elemData = jQuery.hasData( elem ) && jQuery._data( elem );\n" \
"\n" \
"		if ( !elemData || !(events = elemData.events) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Once for each type.namespace in types; type may be omitted\n" \
"		types = jQuery.trim( hoverHack( types || \"\" ) ).split(\" \");\n" \
"		for ( t = 0; t < types.length; t++ ) {\n" \
"			tns = rtypenamespace.exec( types[t] ) || [];\n" \
"			type = origType = tns[1];\n" \
"			namespaces = tns[2];\n" \
"\n" \
"			// Unbind all events (on this namespace, if provided) for the element\n" \
"			if ( !type ) {\n" \
"				for ( type in events ) {\n" \
"					jQuery.event.remove( elem, type + types[ t ], handler, selector, true );\n" \
"				}\n" \
"				continue;\n" \
"			}\n" \
"\n" \
"			special = jQuery.event.special[ type ] || {};\n" \
"			type = ( selector? special.delegateType : special.bindType ) || type;\n" \
"			eventType = events[ type ] || [];\n" \
"			origCount = eventType.length;\n" \
"			namespaces = namespaces ? new RegExp(\"(^|\\\\.)\" + namespaces.split(\".\").sort().join(\"\\\\.(?:.*\\\\.|)\") + \"(\\\\.|$)\") : null;\n" \
"\n" \
"			// Remove matching events\n" \
"			for ( j = 0; j < eventType.length; j++ ) {\n" \
"				handleObj = eventType[ j ];\n" \
"\n" \
"				if ( ( mappedTypes || origType === handleObj.origType ) &&\n" \
"					 ( !handler || handler.guid === handleObj.guid ) &&\n" \
"					 ( !namespaces || namespaces.test( handleObj.namespace ) ) &&\n" \
"					 ( !selector || selector === handleObj.selector || selector === \"**\" && handleObj.selector ) ) {\n" \
"					eventType.splice( j--, 1 );\n" \
"\n" \
"					if ( handleObj.selector ) {\n" \
"						eventType.delegateCount--;\n" \
"					}\n" \
"					if ( special.remove ) {\n" \
"						special.remove.call( elem, handleObj );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Remove generic event handler if we removed something and no more handlers exist\n" \
"			// (avoids potential for endless recursion during removal of special event handlers)\n" \
"			if ( eventType.length === 0 && origCount !== eventType.length ) {\n" \
"				if ( !special.teardown || special.teardown.call( elem, namespaces, elemData.handle ) === false ) {\n" \
"					jQuery.removeEvent( elem, type, elemData.handle );\n" \
"				}\n" \
"\n" \
"				delete events[ type ];\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Remove the expando if it's no longer used\n" \
"		if ( jQuery.isEmptyObject( events ) ) {\n" \
"			delete elemData.handle;\n" \
"\n" \
"			// removeData also checks for emptiness and clears the expando if empty\n" \
"			// so use it instead of delete\n" \
"			jQuery.removeData( elem, \"events\", true );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Events that are safe to short-circuit if no handlers are attached.\n" \
"	// Native DOM events should not be added, they may have inline handlers.\n" \
"	customEvent: {\n" \
"		\"getData\": true,\n" \
"		\"setData\": true,\n" \
"		\"changeData\": true\n" \
"	},\n" \
"\n" \
"	trigger: function( event, data, elem, onlyHandlers ) {\n" \
"		// Don't do events on text and comment nodes\n" \
"		if ( elem && (elem.nodeType === 3 || elem.nodeType === 8) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Event object or event type\n" \
"		var cache, exclusive, i, cur, old, ontype, special, handle, eventPath, bubbleType,\n" \
"			type = event.type || event,\n" \
"			namespaces = [];\n" \
"\n" \
"		// focus/blur morphs to focusin/out; ensure we're not firing them right now\n" \
"		if ( rfocusMorph.test( type + jQuery.event.triggered ) ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		if ( type.indexOf( \"!\" ) >= 0 ) {\n" \
"			// Exclusive events trigger only for the exact event (no namespaces)\n" \
"			type = type.slice(0, -1);\n" \
"			exclusive = true;\n" \
"		}\n" \
"\n" \
"		if ( type.indexOf( \".\" ) >= 0 ) {\n" \
"			// Namespaced trigger; create a regexp to match event type in handle()\n" \
"			namespaces = type.split(\".\");\n" \
"			type = namespaces.shift();\n" \
"			namespaces.sort();\n" \
"		}\n" \
"\n" \
"		if ( (!elem || jQuery.event.customEvent[ type ]) && !jQuery.event.global[ type ] ) {\n" \
"			// No jQuery handlers for this event type, and it can't have inline handlers\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Caller can pass in an Event, Object, or just an event type string\n" \
"		event = typeof event === \"object\" ?\n" \
"			// jQuery.Event object\n" \
"			event[ jQuery.expando ] ? event :\n" \
"			// Object literal\n" \
"			new jQuery.Event( type, event ) :\n" \
"			// Just the event type (string)\n" \
"			new jQuery.Event( type );\n" \
"\n" \
"		event.type = type;\n" \
"		event.isTrigger = true;\n" \
"		event.exclusive = exclusive;\n" \
"		event.namespace = namespaces.join( \".\" );\n" \
"		event.namespace_re = event.namespace? new RegExp(\"(^|\\\\.)\" + namespaces.join(\"\\\\.(?:.*\\\\.|)\") + \"(\\\\.|$)\") : null;\n" \
"		ontype = type.indexOf( \":\" ) < 0 ? \"on\" + type : \"\";\n" \
"\n" \
"		// Handle a global trigger\n" \
"		if ( !elem ) {\n" \
"\n" \
"			// TODO: Stop taunting the data cache; remove global events and always attach to document\n" \
"			cache = jQuery.cache;\n" \
"			for ( i in cache ) {\n" \
"				if ( cache[ i ].events && cache[ i ].events[ type ] ) {\n" \
"					jQuery.event.trigger( event, data, cache[ i ].handle.elem, true );\n" \
"				}\n" \
"			}\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Clean up the event in case it is being reused\n" \
"		event.result = undefined;\n" \
"		if ( !event.target ) {\n" \
"			event.target = elem;\n" \
"		}\n" \
"\n" \
"		// Clone any incoming data and prepend the event, creating the handler arg list\n" \
"		data = data != null ? jQuery.makeArray( data ) : [];\n" \
"		data.unshift( event );\n" \
"\n" \
"		// Allow special events to draw outside the lines\n" \
"		special = jQuery.event.special[ type ] || {};\n" \
"		if ( special.trigger && special.trigger.apply( elem, data ) === false ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Determine event propagation path in advance, per W3C events spec (#9951)\n" \
"		// Bubble up to document, then to window; watch for a global ownerDocument var (#9724)\n" \
"		eventPath = [[ elem, special.bindType || type ]];\n" \
"		if ( !onlyHandlers && !special.noBubble && !jQuery.isWindow( elem ) ) {\n" \
"\n" \
"			bubbleType = special.delegateType || type;\n" \
"			cur = rfocusMorph.test( bubbleType + type ) ? elem : elem.parentNode;\n" \
"			for ( old = elem; cur; cur = cur.parentNode ) {\n" \
"				eventPath.push([ cur, bubbleType ]);\n" \
"				old = cur;\n" \
"			}\n" \
"\n" \
"			// Only add window if we got to document (e.g., not plain obj or detached DOM)\n" \
"			if ( old === (elem.ownerDocument || document) ) {\n" \
"				eventPath.push([ old.defaultView || old.parentWindow || window, bubbleType ]);\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Fire handlers on the event path\n" \
"		for ( i = 0; i < eventPath.length && !event.isPropagationStopped(); i++ ) {\n" \
"\n" \
"			cur = eventPath[i][0];\n" \
"			event.type = eventPath[i][1];\n" \
"\n" \
"			handle = ( jQuery._data( cur, \"events\" ) || {} )[ event.type ] && jQuery._data( cur, \"handle\" );\n" \
"			if ( handle ) {\n" \
"				handle.apply( cur, data );\n" \
"			}\n" \
"			// Note that this is a bare JS function and not a jQuery handler\n" \
"			handle = ontype && cur[ ontype ];\n" \
"			if ( handle && jQuery.acceptData( cur ) && handle.apply && handle.apply( cur, data ) === false ) {\n" \
"				event.preventDefault();\n" \
"			}\n" \
"		}\n" \
"		event.type = type;\n" \
"\n" \
"		// If nobody prevented the default action, do it now\n" \
"		if ( !onlyHandlers && !event.isDefaultPrevented() ) {\n" \
"\n" \
"			if ( (!special._default || special._default.apply( elem.ownerDocument, data ) === false) &&\n" \
"				!(type === \"click\" && jQuery.nodeName( elem, \"a\" )) && jQuery.acceptData( elem ) ) {\n" \
"\n" \
"				// Call a native DOM method on the target with the same name name as the event.\n" \
"				// Can't use an .isFunction() check here because IE6/7 fails that test.\n" \
"				// Don't do default actions on window, that's where global variables be (#6170)\n" \
"				// IE<9 dies on focus/blur to hidden element (#1486)\n" \
"				if ( ontype && elem[ type ] && ((type !== \"focus\" && type !== \"blur\") || event.target.offsetWidth !== 0) && !jQuery.isWindow( elem ) ) {\n" \
"\n" \
"					// Don't re-trigger an onFOO event when we call its FOO() method\n" \
"					old = elem[ ontype ];\n" \
"\n" \
"					if ( old ) {\n" \
"						elem[ ontype ] = null;\n" \
"					}\n" \
"\n" \
"					// Prevent re-triggering of the same event, since we already bubbled it above\n" \
"					jQuery.event.triggered = type;\n" \
"					elem[ type ]();\n" \
"					jQuery.event.triggered = undefined;\n" \
"\n" \
"					if ( old ) {\n" \
"						elem[ ontype ] = old;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return event.result;\n" \
"	},\n" \
"\n" \
"	dispatch: function( event ) {\n" \
"\n" \
"		// Make a writable jQuery.Event from the native event object\n" \
"		event = jQuery.event.fix( event || window.event );\n" \
"\n" \
"		var i, j, cur, ret, selMatch, matched, matches, handleObj, sel, related,\n" \
"			handlers = ( (jQuery._data( this, \"events\" ) || {} )[ event.type ] || []),\n" \
"			delegateCount = handlers.delegateCount,\n" \
"			args = core_slice.call( arguments ),\n" \
"			run_all = !event.exclusive && !event.namespace,\n" \
"			special = jQuery.event.special[ event.type ] || {},\n" \
"			handlerQueue = [];\n" \
"\n" \
"		// Use the fix-ed jQuery.Event rather than the (read-only) native event\n" \
"		args[0] = event;\n" \
"		event.delegateTarget = this;\n" \
"\n" \
"		// Call the preDispatch hook for the mapped type, and let it bail if desired\n" \
"		if ( special.preDispatch && special.preDispatch.call( this, event ) === false ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Determine handlers that should run if there are delegated events\n" \
"		// Avoid non-left-click bubbling in Firefox (#3861)\n" \
"		if ( delegateCount && !(event.button && event.type === \"click\") ) {\n" \
"\n" \
"			for ( cur = event.target; cur != this; cur = cur.parentNode || this ) {\n" \
"\n" \
"				// Don't process clicks (ONLY) on disabled elements (#6911, #8165, #11382, #11764)\n" \
"				if ( cur.disabled !== true || event.type !== \"click\" ) {\n" \
"					selMatch = {};\n" \
"					matches = [];\n" \
"					for ( i = 0; i < delegateCount; i++ ) {\n" \
"						handleObj = handlers[ i ];\n" \
"						sel = handleObj.selector;\n" \
"\n" \
"						if ( selMatch[ sel ] === undefined ) {\n" \
"							selMatch[ sel ] = handleObj.needsContext ?\n" \
"								jQuery( sel, this ).index( cur ) >= 0 :\n" \
"								jQuery.find( sel, this, null, [ cur ] ).length;\n" \
"						}\n" \
"						if ( selMatch[ sel ] ) {\n" \
"							matches.push( handleObj );\n" \
"						}\n" \
"					}\n" \
"					if ( matches.length ) {\n" \
"						handlerQueue.push({ elem: cur, matches: matches });\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Add the remaining (directly-bound) handlers\n" \
"		if ( handlers.length > delegateCount ) {\n" \
"			handlerQueue.push({ elem: this, matches: handlers.slice( delegateCount ) });\n" \
"		}\n" \
"\n" \
"		// Run delegates first; they may want to stop propagation beneath us\n" \
"		for ( i = 0; i < handlerQueue.length && !event.isPropagationStopped(); i++ ) {\n" \
"			matched = handlerQueue[ i ];\n" \
"			event.currentTarget = matched.elem;\n" \
"\n" \
"			for ( j = 0; j < matched.matches.length && !event.isImmediatePropagationStopped(); j++ ) {\n" \
"				handleObj = matched.matches[ j ];\n" \
"\n" \
"				// Triggered event must either 1) be non-exclusive and have no namespace, or\n" \
"				// 2) have namespace(s) a subset or equal to those in the bound event (both can have no namespace).\n" \
"				if ( run_all || (!event.namespace && !handleObj.namespace) || event.namespace_re && event.namespace_re.test( handleObj.namespace ) ) {\n" \
"\n" \
"					event.data = handleObj.data;\n" \
"					event.handleObj = handleObj;\n" \
"\n" \
"					ret = ( (jQuery.event.special[ handleObj.origType ] || {}).handle || handleObj.handler )\n" \
"							.apply( matched.elem, args );\n" \
"\n" \
"					if ( ret !== undefined ) {\n" \
"						event.result = ret;\n" \
"						if ( ret === false ) {\n" \
"							event.preventDefault();\n" \
"							event.stopPropagation();\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Call the postDispatch hook for the mapped type\n" \
"		if ( special.postDispatch ) {\n" \
"			special.postDispatch.call( this, event );\n" \
"		}\n" \
"\n" \
"		return event.result;\n" \
"	},\n" \
"\n" \
"	// Includes some event props shared by KeyEvent and MouseEvent\n" \
"	// *** attrChange attrName relatedNode srcElement  are not normalized, non-W3C, deprecated, will be removed in 1.8 ***\n" \
"	props: \"attrChange attrName relatedNode srcElement altKey bubbles cancelable ctrlKey currentTarget eventPhase metaKey relatedTarget shiftKey target timeStamp view which\".split(\" \"),\n" \
"\n" \
"	fixHooks: {},\n" \
"\n" \
"	keyHooks: {\n" \
"		props: \"char charCode key keyCode\".split(\" \"),\n" \
"		filter: function( event, original ) {\n" \
"\n" \
"			// Add which for key events\n" \
"			if ( event.which == null ) {\n" \
"				event.which = original.charCode != null ? original.charCode : original.keyCode;\n" \
"			}\n" \
"\n" \
"			return event;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	mouseHooks: {\n" \
"		props: \"button buttons clientX clientY fromElement offsetX offsetY pageX pageY screenX screenY toElement\".split(\" \"),\n" \
"		filter: function( event, original ) {\n" \
"			var eventDoc, doc, body,\n" \
"				button = original.button,\n" \
"				fromElement = original.fromElement;\n" \
"\n" \
"			// Calculate pageX/Y if missing and clientX/Y available\n" \
"			if ( event.pageX == null && original.clientX != null ) {\n" \
"				eventDoc = event.target.ownerDocument || document;\n" \
"				doc = eventDoc.documentElement;\n" \
"				body = eventDoc.body;\n" \
"\n" \
"				event.pageX = original.clientX + ( doc && doc.scrollLeft || body && body.scrollLeft || 0 ) - ( doc && doc.clientLeft || body && body.clientLeft || 0 );\n" \
"				event.pageY = original.clientY + ( doc && doc.scrollTop  || body && body.scrollTop  || 0 ) - ( doc && doc.clientTop  || body && body.clientTop  || 0 );\n" \
"			}\n" \
"\n" \
"			// Add relatedTarget, if necessary\n" \
"			if ( !event.relatedTarget && fromElement ) {\n" \
"				event.relatedTarget = fromElement === event.target ? original.toElement : fromElement;\n" \
"			}\n" \
"\n" \
"			// Add which for click: 1 === left; 2 === middle; 3 === right\n" \
"			// Note: button is not normalized, so don't use it\n" \
"			if ( !event.which && button !== undefined ) {\n" \
"				event.which = ( button & 1 ? 1 : ( button & 2 ? 3 : ( button & 4 ? 2 : 0 ) ) );\n" \
"			}\n" \
"\n" \
"			return event;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	fix: function( event ) {\n" \
"		if ( event[ jQuery.expando ] ) {\n" \
"			return event;\n" \
"		}\n" \
"\n" \
"		// Create a writable copy of the event object and normalize some properties\n" \
"		var i, prop,\n" \
"			originalEvent = event,\n" \
"			fixHook = jQuery.event.fixHooks[ event.type ] || {},\n" \
"			copy = fixHook.props ? this.props.concat( fixHook.props ) : this.props;\n" \
"\n" \
"		event = jQuery.Event( originalEvent );\n" \
"\n" \
"		for ( i = copy.length; i; ) {\n" \
"			prop = copy[ --i ];\n" \
"			event[ prop ] = originalEvent[ prop ];\n" \
"		}\n" \
"\n" \
"		// Fix target property, if necessary (#1925, IE 6/7/8 & Safari2)\n" \
"		if ( !event.target ) {\n" \
"			event.target = originalEvent.srcElement || document;\n" \
"		}\n" \
"\n" \
"		// Target should not be a text node (#504, Safari)\n" \
"		if ( event.target.nodeType === 3 ) {\n" \
"			event.target = event.target.parentNode;\n" \
"		}\n" \
"\n" \
"		// For mouse/key events, metaKey==false if it's undefined (#3368, #11328; IE6/7/8)\n" \
"		event.metaKey = !!event.metaKey;\n" \
"\n" \
"		return fixHook.filter? fixHook.filter( event, originalEvent ) : event;\n" \
"	},\n" \
"\n" \
"	special: {\n" \
"		load: {\n" \
"			// Prevent triggered image.load events from bubbling to window.load\n" \
"			noBubble: true\n" \
"		},\n" \
"\n" \
"		focus: {\n" \
"			delegateType: \"focusin\"\n" \
"		},\n" \
"		blur: {\n" \
"			delegateType: \"focusout\"\n" \
"		},\n" \
"\n" \
"		beforeunload: {\n" \
"			setup: function( data, namespaces, eventHandle ) {\n" \
"				// We only want to do this special case on windows\n" \
"				if ( jQuery.isWindow( this ) ) {\n" \
"					this.onbeforeunload = eventHandle;\n" \
"				}\n" \
"			},\n" \
"\n" \
"			teardown: function( namespaces, eventHandle ) {\n" \
"				if ( this.onbeforeunload === eventHandle ) {\n" \
"					this.onbeforeunload = null;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	simulate: function( type, elem, event, bubble ) {\n" \
"		// Piggyback on a donor event to simulate a different one.\n" \
"		// Fake originalEvent to avoid donor's stopPropagation, but if the\n" \
"		// simulated event prevents default then we do the same on the donor.\n" \
"		var e = jQuery.extend(\n" \
"			new jQuery.Event(),\n" \
"			event,\n" \
"			{ type: type,\n" \
"				isSimulated: true,\n" \
"				originalEvent: {}\n" \
"			}\n" \
"		);\n" \
"		if ( bubble ) {\n" \
"			jQuery.event.trigger( e, null, elem );\n" \
"		} else {\n" \
"			jQuery.event.dispatch.call( elem, e );\n" \
"		}\n" \
"		if ( e.isDefaultPrevented() ) {\n" \
"			event.preventDefault();\n" \
"		}\n" \
"	}\n" \
"};\n" \
"\n" \
"// Some plugins are using, but it's undocumented/deprecated and will be removed.\n" \
"// The 1.7 special event interface should provide all the hooks needed now.\n" \
"jQuery.event.handle = jQuery.event.dispatch;\n" \
"\n" \
"jQuery.removeEvent = document.removeEventListener ?\n" \
"	function( elem, type, handle ) {\n" \
"		if ( elem.removeEventListener ) {\n" \
"			elem.removeEventListener( type, handle, false );\n" \
"		}\n" \
"	} :\n" \
"	function( elem, type, handle ) {\n" \
"		var name = \"on\" + type;\n" \
"\n" \
"		if ( elem.detachEvent ) {\n" \
"\n" \
"			// #8545, #7054, preventing memory leaks for custom events in IE6-8\n" \
"			// detachEvent needed property on element, by name of that event, to properly expose it to GC\n" \
"			if ( typeof elem[ name ] === \"undefined\" ) {\n" \
"				elem[ name ] = null;\n" \
"			}\n" \
"\n" \
"			elem.detachEvent( name, handle );\n" \
"		}\n" \
"	};\n" \
"\n" \
"jQuery.Event = function( src, props ) {\n" \
"	// Allow instantiation without the 'new' keyword\n" \
"	if ( !(this instanceof jQuery.Event) ) {\n" \
"		return new jQuery.Event( src, props );\n" \
"	}\n" \
"\n" \
"	// Event object\n" \
"	if ( src && src.type ) {\n" \
"		this.originalEvent = src;\n" \
"		this.type = src.type;\n" \
"\n" \
"		// Events bubbling up the document may have been marked as prevented\n" \
"		// by a handler lower down the tree; reflect the correct value.\n" \
"		this.isDefaultPrevented = ( src.defaultPrevented || src.returnValue === false ||\n" \
"			src.getPreventDefault && src.getPreventDefault() ) ? returnTrue : returnFalse;\n" \
"\n" \
"	// Event type\n" \
"	} else {\n" \
"		this.type = src;\n" \
"	}\n" \
"\n" \
"	// Put explicitly provided properties onto the event object\n" \
"	if ( props ) {\n" \
"		jQuery.extend( this, props );\n" \
"	}\n" \
"\n" \
"	// Create a timestamp if incoming event doesn't have one\n" \
"	this.timeStamp = src && src.timeStamp || jQuery.now();\n" \
"\n" \
"	// Mark it as fixed\n" \
"	this[ jQuery.expando ] = true;\n" \
"};\n" \
"\n" \
"function returnFalse() {\n" \
"	return false;\n" \
"}\n" \
"function returnTrue() {\n" \
"	return true;\n" \
"}\n" \
"\n" \
"// jQuery.Event is based on DOM3 Events as specified by the ECMAScript Language Binding\n" \
"// http://www.w3.org/TR/2003/WD-DOM-Level-3-Events-20030331/ecma-script-binding.html\n" \
"jQuery.Event.prototype = {\n" \
"	preventDefault: function() {\n" \
"		this.isDefaultPrevented = returnTrue;\n" \
"\n" \
"		var e = this.originalEvent;\n" \
"		if ( !e ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// if preventDefault exists run it on the original event\n" \
"		if ( e.preventDefault ) {\n" \
"			e.preventDefault();\n" \
"\n" \
"		// otherwise set the returnValue property of the original event to false (IE)\n" \
"		} else {\n" \
"			e.returnValue = false;\n" \
"		}\n" \
"	},\n" \
"	stopPropagation: function() {\n" \
"		this.isPropagationStopped = returnTrue;\n" \
"\n" \
"		var e = this.originalEvent;\n" \
"		if ( !e ) {\n" \
"			return;\n" \
"		}\n" \
"		// if stopPropagation exists run it on the original event\n" \
"		if ( e.stopPropagation ) {\n" \
"			e.stopPropagation();\n" \
"		}\n" \
"		// otherwise set the cancelBubble property of the original event to true (IE)\n" \
"		e.cancelBubble = true;\n" \
"	},\n" \
"	stopImmediatePropagation: function() {\n" \
"		this.isImmediatePropagationStopped = returnTrue;\n" \
"		this.stopPropagation();\n" \
"	},\n" \
"	isDefaultPrevented: returnFalse,\n" \
"	isPropagationStopped: returnFalse,\n" \
"	isImmediatePropagationStopped: returnFalse\n" \
"};\n" \
"\n" \
"// Create mouseenter/leave events using mouseover/out and event-time checks\n" \
"jQuery.each({\n" \
"	mouseenter: \"mouseover\",\n" \
"	mouseleave: \"mouseout\"\n" \
"}, function( orig, fix ) {\n" \
"	jQuery.event.special[ orig ] = {\n" \
"		delegateType: fix,\n" \
"		bindType: fix,\n" \
"\n" \
"		handle: function( event ) {\n" \
"			var ret,\n" \
"				target = this,\n" \
"				related = event.relatedTarget,\n" \
"				handleObj = event.handleObj,\n" \
"				selector = handleObj.selector;\n" \
"\n" \
"			// For mousenter/leave call the handler if related is outside the target.\n" \
"			// NB: No relatedTarget if the mouse left/entered the browser window\n" \
"			if ( !related || (related !== target && !jQuery.contains( target, related )) ) {\n" \
"				event.type = handleObj.origType;\n" \
"				ret = handleObj.handler.apply( this, arguments );\n" \
"				event.type = fix;\n" \
"			}\n" \
"			return ret;\n" \
"		}\n" \
"	};\n" \
"});\n" \
"\n" \
"// IE submit delegation\n" \
"if ( !jQuery.support.submitBubbles ) {\n" \
"\n" \
"	jQuery.event.special.submit = {\n" \
"		setup: function() {\n" \
"			// Only need this for delegated form submit events\n" \
"			if ( jQuery.nodeName( this, \"form\" ) ) {\n" \
"				return false;\n" \
"			}\n" \
"\n" \
"			// Lazy-add a submit handler when a descendant form may potentially be submitted\n" \
"			jQuery.event.add( this, \"click._submit keypress._submit\", function( e ) {\n" \
"				// Node name check avoids a VML-related crash in IE (#9807)\n" \
"				var elem = e.target,\n" \
"					form = jQuery.nodeName( elem, \"input\" ) || jQuery.nodeName( elem, \"button\" ) ? elem.form : undefined;\n" \
"				if ( form && !jQuery._data( form, \"_submit_attached\" ) ) {\n" \
"					jQuery.event.add( form, \"submit._submit\", function( event ) {\n" \
"						event._submit_bubble = true;\n" \
"					});\n" \
"					jQuery._data( form, \"_submit_attached\", true );\n" \
"				}\n" \
"			});\n" \
"			// return undefined since we don't need an event listener\n" \
"		},\n" \
"\n" \
"		postDispatch: function( event ) {\n" \
"			// If form was submitted by the user, bubble the event up the tree\n" \
"			if ( event._submit_bubble ) {\n" \
"				delete event._submit_bubble;\n" \
"				if ( this.parentNode && !event.isTrigger ) {\n" \
"					jQuery.event.simulate( \"submit\", this.parentNode, event, true );\n" \
"				}\n" \
"			}\n" \
"		},\n" \
"\n" \
"		teardown: function() {\n" \
"			// Only need this for delegated form submit events\n" \
"			if ( jQuery.nodeName( this, \"form\" ) ) {\n" \
"				return false;\n" \
"			}\n" \
"\n" \
"			// Remove delegated handlers; cleanData eventually reaps submit handlers attached above\n" \
"			jQuery.event.remove( this, \"._submit\" );\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"// IE change delegation and checkbox/radio fix\n" \
"if ( !jQuery.support.changeBubbles ) {\n" \
"\n" \
"	jQuery.event.special.change = {\n" \
"\n" \
"		setup: function() {\n" \
"\n" \
"			if ( rformElems.test( this.nodeName ) ) {\n" \
"				// IE doesn't fire change on a check/radio until blur; trigger it on click\n" \
"				// after a propertychange. Eat the blur-change in special.change.handle.\n" \
"				// This still fires onchange a second time for check/radio after blur.\n" \
"				if ( this.type === \"checkbox\" || this.type === \"radio\" ) {\n" \
"					jQuery.event.add( this, \"propertychange._change\", function( event ) {\n" \
"						if ( event.originalEvent.propertyName === \"checked\" ) {\n" \
"							this._just_changed = true;\n" \
"						}\n" \
"					});\n" \
"					jQuery.event.add( this, \"click._change\", function( event ) {\n" \
"						if ( this._just_changed && !event.isTrigger ) {\n" \
"							this._just_changed = false;\n" \
"						}\n" \
"						// Allow triggered, simulated change events (#11500)\n" \
"						jQuery.event.simulate( \"change\", this, event, true );\n" \
"					});\n" \
"				}\n" \
"				return false;\n" \
"			}\n" \
"			// Delegated event; lazy-add a change handler on descendant inputs\n" \
"			jQuery.event.add( this, \"beforeactivate._change\", function( e ) {\n" \
"				var elem = e.target;\n" \
"\n" \
"				if ( rformElems.test( elem.nodeName ) && !jQuery._data( elem, \"_change_attached\" ) ) {\n" \
"					jQuery.event.add( elem, \"change._change\", function( event ) {\n" \
"						if ( this.parentNode && !event.isSimulated && !event.isTrigger ) {\n" \
"							jQuery.event.simulate( \"change\", this.parentNode, event, true );\n" \
"						}\n" \
"					});\n" \
"					jQuery._data( elem, \"_change_attached\", true );\n" \
"				}\n" \
"			});\n" \
"		},\n" \
"\n" \
"		handle: function( event ) {\n" \
"			var elem = event.target;\n" \
"\n" \
"			// Swallow native change events from checkbox/radio, we already triggered them above\n" \
"			if ( this !== elem || event.isSimulated || event.isTrigger || (elem.type !== \"radio\" && elem.type !== \"checkbox\") ) {\n" \
"				return event.handleObj.handler.apply( this, arguments );\n" \
"			}\n" \
"		},\n" \
"\n" \
"		teardown: function() {\n" \
"			jQuery.event.remove( this, \"._change\" );\n" \
"\n" \
"			return !rformElems.test( this.nodeName );\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"// Create \"bubbling\" focus and blur events\n" \
"if ( !jQuery.support.focusinBubbles ) {\n" \
"	jQuery.each({ focus: \"focusin\", blur: \"focusout\" }, function( orig, fix ) {\n" \
"\n" \
"		// Attach a single capturing handler while someone wants focusin/focusout\n" \
"		var attaches = 0,\n" \
"			handler = function( event ) {\n" \
"				jQuery.event.simulate( fix, event.target, jQuery.event.fix( event ), true );\n" \
"			};\n" \
"\n" \
"		jQuery.event.special[ fix ] = {\n" \
"			setup: function() {\n" \
"				if ( attaches++ === 0 ) {\n" \
"					document.addEventListener( orig, handler, true );\n" \
"				}\n" \
"			},\n" \
"			teardown: function() {\n" \
"				if ( --attaches === 0 ) {\n" \
"					document.removeEventListener( orig, handler, true );\n" \
"				}\n" \
"			}\n" \
"		};\n" \
"	});\n" \
"}\n" \
"\n" \
"jQuery.fn.extend({\n" \
"\n" \
"	on: function( types, selector, data, fn, /*INTERNAL*/ one ) {\n" \
"		var origFn, type;\n" \
"\n" \
"		// Types can be a map of types/handlers\n" \
"		if ( typeof types === \"object\" ) {\n" \
"			// ( types-Object, selector, data )\n" \
"			if ( typeof selector !== \"string\" ) { // && selector != null\n" \
"				// ( types-Object, data )\n" \
"				data = data || selector;\n" \
"				selector = undefined;\n" \
"			}\n" \
"			for ( type in types ) {\n" \
"				this.on( type, selector, data, types[ type ], one );\n" \
"			}\n" \
"			return this;\n" \
"		}\n" \
"\n" \
"		if ( data == null && fn == null ) {\n" \
"			// ( types, fn )\n" \
"			fn = selector;\n" \
"			data = selector = undefined;\n" \
"		} else if ( fn == null ) {\n" \
"			if ( typeof selector === \"string\" ) {\n" \
"				// ( types, selector, fn )\n" \
"				fn = data;\n" \
"				data = undefined;\n" \
"			} else {\n" \
"				// ( types, data, fn )\n" \
"				fn = data;\n" \
"				data = selector;\n" \
"				selector = undefined;\n" \
"			}\n" \
"		}\n" \
"		if ( fn === false ) {\n" \
"			fn = returnFalse;\n" \
"		} else if ( !fn ) {\n" \
"			return this;\n" \
"		}\n" \
"\n" \
"		if ( one === 1 ) {\n" \
"			origFn = fn;\n" \
"			fn = function( event ) {\n" \
"				// Can use an empty set, since event contains the info\n" \
"				jQuery().off( event );\n" \
"				return origFn.apply( this, arguments );\n" \
"			};\n" \
"			// Use same guid so caller can remove using origFn\n" \
"			fn.guid = origFn.guid || ( origFn.guid = jQuery.guid++ );\n" \
"		}\n" \
"		return this.each( function() {\n" \
"			jQuery.event.add( this, types, fn, data, selector );\n" \
"		});\n" \
"	},\n" \
"	one: function( types, selector, data, fn ) {\n" \
"		return this.on( types, selector, data, fn, 1 );\n" \
"	},\n" \
"	off: function( types, selector, fn ) {\n" \
"		var handleObj, type;\n" \
"		if ( types && types.preventDefault && types.handleObj ) {\n" \
"			// ( event )  dispatched jQuery.Event\n" \
"			handleObj = types.handleObj;\n" \
"			jQuery( types.delegateTarget ).off(\n" \
"				handleObj.namespace ? handleObj.origType + \".\" + handleObj.namespace : handleObj.origType,\n" \
"				handleObj.selector,\n" \
"				handleObj.handler\n" \
"			);\n" \
"			return this;\n" \
"		}\n" \
"		if ( typeof types === \"object\" ) {\n" \
"			// ( types-object [, selector] )\n" \
"			for ( type in types ) {\n" \
"				this.off( type, selector, types[ type ] );\n" \
"			}\n" \
"			return this;\n" \
"		}\n" \
"		if ( selector === false || typeof selector === \"function\" ) {\n" \
"			// ( types [, fn] )\n" \
"			fn = selector;\n" \
"			selector = undefined;\n" \
"		}\n" \
"		if ( fn === false ) {\n" \
"			fn = returnFalse;\n" \
"		}\n" \
"		return this.each(function() {\n" \
"			jQuery.event.remove( this, types, fn, selector );\n" \
"		});\n" \
"	},\n" \
"\n" \
"	bind: function( types, data, fn ) {\n" \
"		return this.on( types, null, data, fn );\n" \
"	},\n" \
"	unbind: function( types, fn ) {\n" \
"		return this.off( types, null, fn );\n" \
"	},\n" \
"\n" \
"	live: function( types, data, fn ) {\n" \
"		jQuery( this.context ).on( types, this.selector, data, fn );\n" \
"		return this;\n" \
"	},\n" \
"	die: function( types, fn ) {\n" \
"		jQuery( this.context ).off( types, this.selector || \"**\", fn );\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	delegate: function( selector, types, data, fn ) {\n" \
"		return this.on( types, selector, data, fn );\n" \
"	},\n" \
"	undelegate: function( selector, types, fn ) {\n" \
"		// ( namespace ) or ( selector, types [, fn] )\n" \
"		return arguments.length === 1 ? this.off( selector, \"**\" ) : this.off( types, selector || \"**\", fn );\n" \
"	},\n" \
"\n" \
"	trigger: function( type, data ) {\n" \
"		return this.each(function() {\n" \
"			jQuery.event.trigger( type, data, this );\n" \
"		});\n" \
"	},\n" \
"	triggerHandler: function( type, data ) {\n" \
"		if ( this[0] ) {\n" \
"			return jQuery.event.trigger( type, data, this[0], true );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	toggle: function( fn ) {\n" \
"		// Save reference to arguments for access in closure\n" \
"		var args = arguments,\n" \
"			guid = fn.guid || jQuery.guid++,\n" \
"			i = 0,\n" \
"			toggler = function( event ) {\n" \
"				// Figure out which function to execute\n" \
"				var lastToggle = ( jQuery._data( this, \"lastToggle\" + fn.guid ) || 0 ) % i;\n" \
"				jQuery._data( this, \"lastToggle\" + fn.guid, lastToggle + 1 );\n" \
"\n" \
"				// Make sure that clicks stop\n" \
"				event.preventDefault();\n" \
"\n" \
"				// and execute the function\n" \
"				return args[ lastToggle ].apply( this, arguments ) || false;\n" \
"			};\n" \
"\n" \
"		// link all the functions, so any of them can unbind this click handler\n" \
"		toggler.guid = guid;\n" \
"		while ( i < args.length ) {\n" \
"			args[ i++ ].guid = guid;\n" \
"		}\n" \
"\n" \
"		return this.click( toggler );\n" \
"	},\n" \
"\n" \
"	hover: function( fnOver, fnOut ) {\n" \
"		return this.mouseenter( fnOver ).mouseleave( fnOut || fnOver );\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.each( (\"blur focus focusin focusout load resize scroll unload click dblclick \" +\n" \
"	\"mousedown mouseup mousemove mouseover mouseout mouseenter mouseleave \" +\n" \
"	\"change select submit keydown keypress keyup error contextmenu\").split(\" \"), function( i, name ) {\n" \
"\n" \
"	// Handle event binding\n" \
"	jQuery.fn[ name ] = function( data, fn ) {\n" \
"		if ( fn == null ) {\n" \
"			fn = data;\n" \
"			data = null;\n" \
"		}\n" \
"\n" \
"		return arguments.length > 0 ?\n" \
"			this.on( name, null, data, fn ) :\n" \
"			this.trigger( name );\n" \
"	};\n" \
"\n" \
"	if ( rkeyEvent.test( name ) ) {\n" \
"		jQuery.event.fixHooks[ name ] = jQuery.event.keyHooks;\n" \
"	}\n" \
"\n" \
"	if ( rmouseEvent.test( name ) ) {\n" \
"		jQuery.event.fixHooks[ name ] = jQuery.event.mouseHooks;\n" \
"	}\n" \
"});\n" \
"/*!\n" \
" * Sizzle CSS Selector Engine\n" \
" * Copyright 2012 jQuery Foundation and other contributors\n" \
" * Released under the MIT license\n" \
" * http://sizzlejs.com/\n" \
" */\n" \
"(function( window, undefined ) {\n" \
"\n" \
"var cachedruns,\n" \
"	assertGetIdNotName,\n" \
"	Expr,\n" \
"	getText,\n" \
"	isXML,\n" \
"	contains,\n" \
"	compile,\n" \
"	sortOrder,\n" \
"	hasDuplicate,\n" \
"	outermostContext,\n" \
"\n" \
"	baseHasDuplicate = true,\n" \
"	strundefined = \"undefined\",\n" \
"\n" \
"	expando = ( \"sizcache\" + Math.random() ).replace( \".\", \"\" ),\n" \
"\n" \
"	Token = String,\n" \
"	document = window.document,\n" \
"	docElem = document.documentElement,\n" \
"	dirruns = 0,\n" \
"	done = 0,\n" \
"	pop = [].pop,\n" \
"	push = [].push,\n" \
"	slice = [].slice,\n" \
"	// Use a stripped-down indexOf if a native one is unavailable\n" \
"	indexOf = [].indexOf || function( elem ) {\n" \
"		var i = 0,\n" \
"			len = this.length;\n" \
"		for ( ; i < len; i++ ) {\n" \
"			if ( this[i] === elem ) {\n" \
"				return i;\n" \
"			}\n" \
"		}\n" \
"		return -1;\n" \
"	},\n" \
"\n" \
"	// Augment a function for special use by Sizzle\n" \
"	markFunction = function( fn, value ) {\n" \
"		fn[ expando ] = value == null || value;\n" \
"		return fn;\n" \
"	},\n" \
"\n" \
"	createCache = function() {\n" \
"		var cache = {},\n" \
"			keys = [];\n" \
"\n" \
"		return markFunction(function( key, value ) {\n" \
"			// Only keep the most recent entries\n" \
"			if ( keys.push( key ) > Expr.cacheLength ) {\n" \
"				delete cache[ keys.shift() ];\n" \
"			}\n" \
"\n" \
"			// Retrieve with (key + \" \") to avoid collision with native Object.prototype properties (see Issue #157)\n" \
"			return (cache[ key + \" \" ] = value);\n" \
"		}, cache );\n" \
"	},\n" \
"\n" \
"	classCache = createCache(),\n" \
"	tokenCache = createCache(),\n" \
"	compilerCache = createCache(),\n" \
"\n" \
"	// Regex\n" \
"\n" \
"	// Whitespace characters http://www.w3.org/TR/css3-selectors/#whitespace\n" \
"	whitespace = \"[\\\\x20\\\\t\\\\r\\\\n\\\\f]\",\n" \
"	// http://www.w3.org/TR/css3-syntax/#characters\n" \
"	characterEncoding = \"(?:\\\\\\\\.|[-\\\\w]|[^\\\\x00-\\\\xa0])+\",\n" \
"\n" \
"	// Loosely modeled on CSS identifier characters\n" \
"	// An unquoted value should be a CSS identifier (http://www.w3.org/TR/css3-selectors/#attribute-selectors)\n" \
"	// Proper syntax: http://www.w3.org/TR/CSS21/syndata.html#value-def-identifier\n" \
"	identifier = characterEncoding.replace( \"w\", \"w#\" ),\n" \
"\n" \
"	// Acceptable operators http://www.w3.org/TR/selectors/#attribute-selectors\n" \
"	operators = \"([*^$|!~]?=)\",\n" \
"	attributes = \"\\\\[\" + whitespace + \"*(\" + characterEncoding + \")\" + whitespace +\n" \
"		\"*(?:\" + operators + whitespace + \"*(?:(['\\\"])((?:\\\\\\\\.|[^\\\\\\\\])*?)\\\\3|(\" + identifier + \")|)|)\" + whitespace + \"*\\\\]\",\n" \
"\n" \
"	// Prefer arguments not in parens/brackets,\n" \
"	//   then attribute selectors and non-pseudos (denoted by :),\n" \
"	//   then anything else\n" \
"	// These preferences are here to reduce the number of selectors\n" \
"	//   needing tokenize in the PSEUDO preFilter\n" \
"	pseudos = \":(\" + characterEncoding + \")(?:\\\\((?:(['\\\"])((?:\\\\\\\\.|[^\\\\\\\\])*?)\\\\2|([^()[\\\\]]*|(?:(?:\" + attributes + \")|[^:]|\\\\\\\\.)*|.*))\\\\)|)\",\n" \
"\n" \
"	// For matchExpr.POS and matchExpr.needsContext\n" \
"	pos = \":(even|odd|eq|gt|lt|nth|first|last)(?:\\\\(\" + whitespace +\n" \
"		\"*((?:-\\\\d)?\\\\d*)\" + whitespace + \"*\\\\)|)(?=[^-]|$)\",\n" \
"\n" \
"	// Leading and non-escaped trailing whitespace, capturing some non-whitespace characters preceding the latter\n" \
"	rtrim = new RegExp( \"^\" + whitespace + \"+|((?:^|[^\\\\\\\\])(?:\\\\\\\\.)*)\" + whitespace + \"+$\", \"g\" ),\n" \
"\n" \
"	rcomma = new RegExp( \"^\" + whitespace + \"*,\" + whitespace + \"*\" ),\n" \
"	rcombinators = new RegExp( \"^\" + whitespace + \"*([\\\\x20\\\\t\\\\r\\\\n\\\\f>+~])\" + whitespace + \"*\" ),\n" \
"	rpseudo = new RegExp( pseudos ),\n" \
"\n" \
"	// Easily-parseable/retrievable ID or TAG or CLASS selectors\n" \
"	rquickExpr = /^(?:#([\\w\\-]+)|(\\w+)|\\.([\\w\\-]+))$/,\n" \
"\n" \
"	rnot = /^:not/,\n" \
"	rsibling = /[\\x20\\t\\r\\n\\f]*[+~]/,\n" \
"	rendsWithNot = /:not\\($/,\n" \
"\n" \
"	rheader = /h\\d/i,\n" \
"	rinputs = /input|select|textarea|button/i,\n" \
"\n" \
"	rbackslash = /\\\\(?!\\\\)/g,\n" \
"\n" \
"	matchExpr = {\n" \
"		\"ID\": new RegExp( \"^#(\" + characterEncoding + \")\" ),\n" \
"		\"CLASS\": new RegExp( \"^\\\\.(\" + characterEncoding + \")\" ),\n" \
"		\"NAME\": new RegExp( \"^\\\\[name=['\\\"]?(\" + characterEncoding + \")['\\\"]?\\\\]\" ),\n" \
"		\"TAG\": new RegExp( \"^(\" + characterEncoding.replace( \"w\", \"w*\" ) + \")\" ),\n" \
"		\"ATTR\": new RegExp( \"^\" + attributes ),\n" \
"		\"PSEUDO\": new RegExp( \"^\" + pseudos ),\n" \
"		\"POS\": new RegExp( pos, \"i\" ),\n" \
"		\"CHILD\": new RegExp( \"^:(only|nth|first|last)-child(?:\\\\(\" + whitespace +\n" \
"			\"*(even|odd|(([+-]|)(\\\\d*)n|)\" + whitespace + \"*(?:([+-]|)\" + whitespace +\n" \
"			\"*(\\\\d+)|))\" + whitespace + \"*\\\\)|)\", \"i\" ),\n" \
"		// For use in libraries implementing .is()\n" \
"		\"needsContext\": new RegExp( \"^\" + whitespace + \"*[>+~]|\" + pos, \"i\" )\n" \
"	},\n" \
"\n" \
"	// Support\n" \
"\n" \
"	// Used for testing something on an element\n" \
"	assert = function( fn ) {\n" \
"		var div = document.createElement(\"div\");\n" \
"\n" \
"		try {\n" \
"			return fn( div );\n" \
"		} catch (e) {\n" \
"			return false;\n" \
"		} finally {\n" \
"			// release memory in IE\n" \
"			div = null;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Check if getElementsByTagName(\"*\") returns only elements\n" \
"	assertTagNameNoComments = assert(function( div ) {\n" \
"		div.appendChild( document.createComment(\"\") );\n" \
"		return !div.getElementsByTagName(\"*\").length;\n" \
"	}),\n" \
"\n" \
"	// Check if getAttribute returns normalized href attributes\n" \
"	assertHrefNotNormalized = assert(function( div ) {\n" \
"		div.innerHTML = \"<a href='#'></a>\";\n" \
"		return div.firstChild && typeof div.firstChild.getAttribute !== strundefined &&\n" \
"			div.firstChild.getAttribute(\"href\") === \"#\";\n" \
"	}),\n" \
"\n" \
"	// Check if attributes should be retrieved by attribute nodes\n" \
"	assertAttributes = assert(function( div ) {\n" \
"		div.innerHTML = \"<select></select>\";\n" \
"		var type = typeof div.lastChild.getAttribute(\"multiple\");\n" \
"		// IE8 returns a string for some attributes even when not present\n" \
"		return type !== \"boolean\" && type !== \"string\";\n" \
"	}),\n" \
"\n" \
"	// Check if getElementsByClassName can be trusted\n" \
"	assertUsableClassName = assert(function( div ) {\n" \
"		// Opera can't find a second classname (in 9.6)\n" \
"		div.innerHTML = \"<div class='hidden e'></div><div class='hidden'></div>\";\n" \
"		if ( !div.getElementsByClassName || !div.getElementsByClassName(\"e\").length ) {\n" \
"			return false;\n" \
"		}\n" \
"\n" \
"		// Safari 3.2 caches class attributes and doesn't catch changes\n" \
"		div.lastChild.className = \"e\";\n" \
"		return div.getElementsByClassName(\"e\").length === 2;\n" \
"	}),\n" \
"\n" \
"	// Check if getElementById returns elements by name\n" \
"	// Check if getElementsByName privileges form controls or returns elements by ID\n" \
"	assertUsableName = assert(function( div ) {\n" \
"		// Inject content\n" \
"		div.id = expando + 0;\n" \
"		div.innerHTML = \"<a name='\" + expando + \"'></a><div name='\" + expando + \"'></div>\";\n" \
"		docElem.insertBefore( div, docElem.firstChild );\n" \
"\n" \
"		// Test\n" \
"		var pass = document.getElementsByName &&\n" \
"			// buggy browsers will return fewer than the correct 2\n" \
"			document.getElementsByName( expando ).length === 2 +\n" \
"			// buggy browsers will return more than the correct 0\n" \
"			document.getElementsByName( expando + 0 ).length;\n" \
"		assertGetIdNotName = !document.getElementById( expando );\n" \
"\n" \
"		// Cleanup\n" \
"		docElem.removeChild( div );\n" \
"\n" \
"		return pass;\n" \
"	});\n" \
"\n" \
"// If slice is not available, provide a backup\n" \
"try {\n" \
"	slice.call( docElem.childNodes, 0 )[0].nodeType;\n" \
"} catch ( e ) {\n" \
"	slice = function( i ) {\n" \
"		var elem,\n" \
"			results = [];\n" \
"		for ( ; (elem = this[i]); i++ ) {\n" \
"			results.push( elem );\n" \
"		}\n" \
"		return results;\n" \
"	};\n" \
"}\n" \
"\n" \
"function Sizzle( selector, context, results, seed ) {\n" \
"	results = results || [];\n" \
"	context = context || document;\n" \
"	var match, elem, xml, m,\n" \
"		nodeType = context.nodeType;\n" \
"\n" \
"	if ( !selector || typeof selector !== \"string\" ) {\n" \
"		return results;\n" \
"	}\n" \
"\n" \
"	if ( nodeType !== 1 && nodeType !== 9 ) {\n" \
"		return [];\n" \
"	}\n" \
"\n" \
"	xml = isXML( context );\n" \
"\n" \
"	if ( !xml && !seed ) {\n" \
"		if ( (match = rquickExpr.exec( selector )) ) {\n" \
"			// Speed-up: Sizzle(\"#ID\")\n" \
"			if ( (m = match[1]) ) {\n" \
"				if ( nodeType === 9 ) {\n" \
"					elem = context.getElementById( m );\n" \
"					// Check parentNode to catch when Blackberry 4.6 returns\n" \
"					// nodes that are no longer in the document #6963\n" \
"					if ( elem && elem.parentNode ) {\n" \
"						// Handle the case where IE, Opera, and Webkit return items\n" \
"						// by name instead of ID\n" \
"						if ( elem.id === m ) {\n" \
"							results.push( elem );\n" \
"							return results;\n" \
"						}\n" \
"					} else {\n" \
"						return results;\n" \
"					}\n" \
"				} else {\n" \
"					// Context is not a document\n" \
"					if ( context.ownerDocument && (elem = context.ownerDocument.getElementById( m )) &&\n" \
"						contains( context, elem ) && elem.id === m ) {\n" \
"						results.push( elem );\n" \
"						return results;\n" \
"					}\n" \
"				}\n" \
"\n" \
"			// Speed-up: Sizzle(\"TAG\")\n" \
"			} else if ( match[2] ) {\n" \
"				push.apply( results, slice.call(context.getElementsByTagName( selector ), 0) );\n" \
"				return results;\n" \
"\n" \
"			// Speed-up: Sizzle(\".CLASS\")\n" \
"			} else if ( (m = match[3]) && assertUsableClassName && context.getElementsByClassName ) {\n" \
"				push.apply( results, slice.call(context.getElementsByClassName( m ), 0) );\n" \
"				return results;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// All others\n" \
"	return select( selector.replace( rtrim, \"$1\" ), context, results, seed, xml );\n" \
"}\n" \
"\n" \
"Sizzle.matches = function( expr, elements ) {\n" \
"	return Sizzle( expr, null, null, elements );\n" \
"};\n" \
"\n" \
"Sizzle.matchesSelector = function( elem, expr ) {\n" \
"	return Sizzle( expr, null, null, [ elem ] ).length > 0;\n" \
"};\n" \
"\n" \
"// Returns a function to use in pseudos for input types\n" \
"function createInputPseudo( type ) {\n" \
"	return function( elem ) {\n" \
"		var name = elem.nodeName.toLowerCase();\n" \
"		return name === \"input\" && elem.type === type;\n" \
"	};\n" \
"}\n" \
"\n" \
"// Returns a function to use in pseudos for buttons\n" \
"function createButtonPseudo( type ) {\n" \
"	return function( elem ) {\n" \
"		var name = elem.nodeName.toLowerCase();\n" \
"		return (name === \"input\" || name === \"button\") && elem.type === type;\n" \
"	};\n" \
"}\n" \
"\n" \
"// Returns a function to use in pseudos for positionals\n" \
"function createPositionalPseudo( fn ) {\n" \
"	return markFunction(function( argument ) {\n" \
"		argument = +argument;\n" \
"		return markFunction(function( seed, matches ) {\n" \
"			var j,\n" \
"				matchIndexes = fn( [], seed.length, argument ),\n" \
"				i = matchIndexes.length;\n" \
"\n" \
"			// Match elements found at the specified indexes\n" \
"			while ( i-- ) {\n" \
"				if ( seed[ (j = matchIndexes[i]) ] ) {\n" \
"					seed[j] = !(matches[j] = seed[j]);\n" \
"				}\n" \
"			}\n" \
"		});\n" \
"	});\n" \
"}\n" \
"\n" \
"/**\n" \
" * Utility function for retrieving the text value of an array of DOM nodes\n" \
" * @param {Array|Element} elem\n" \
" */\n" \
"getText = Sizzle.getText = function( elem ) {\n" \
"	var node,\n" \
"		ret = \"\",\n" \
"		i = 0,\n" \
"		nodeType = elem.nodeType;\n" \
"\n" \
"	if ( nodeType ) {\n" \
"		if ( nodeType === 1 || nodeType === 9 || nodeType === 11 ) {\n" \
"			// Use textContent for elements\n" \
"			// innerText usage removed for consistency of new lines (see #11153)\n" \
"			if ( typeof elem.textContent === \"string\" ) {\n" \
"				return elem.textContent;\n" \
"			} else {\n" \
"				// Traverse its children\n" \
"				for ( elem = elem.firstChild; elem; elem = elem.nextSibling ) {\n" \
"					ret += getText( elem );\n" \
"				}\n" \
"			}\n" \
"		} else if ( nodeType === 3 || nodeType === 4 ) {\n" \
"			return elem.nodeValue;\n" \
"		}\n" \
"		// Do not include comment or processing instruction nodes\n" \
"	} else {\n" \
"\n" \
"		// If no nodeType, this is expected to be an array\n" \
"		for ( ; (node = elem[i]); i++ ) {\n" \
"			// Do not traverse comment nodes\n" \
"			ret += getText( node );\n" \
"		}\n" \
"	}\n" \
"	return ret;\n" \
"};\n" \
"\n" \
"isXML = Sizzle.isXML = function( elem ) {\n" \
"	// documentElement is verified for cases where it doesn't yet exist\n" \
"	// (such as loading iframes in IE - #4833)\n" \
"	var documentElement = elem && (elem.ownerDocument || elem).documentElement;\n" \
"	return documentElement ? documentElement.nodeName !== \"HTML\" : false;\n" \
"};\n" \
"\n" \
"// Element contains another\n" \
"contains = Sizzle.contains = docElem.contains ?\n" \
"	function( a, b ) {\n" \
"		var adown = a.nodeType === 9 ? a.documentElement : a,\n" \
"			bup = b && b.parentNode;\n" \
"		return a === bup || !!( bup && bup.nodeType === 1 && adown.contains && adown.contains(bup) );\n" \
"	} :\n" \
"	docElem.compareDocumentPosition ?\n" \
"	function( a, b ) {\n" \
"		return b && !!( a.compareDocumentPosition( b ) & 16 );\n" \
"	} :\n" \
"	function( a, b ) {\n" \
"		while ( (b = b.parentNode) ) {\n" \
"			if ( b === a ) {\n" \
"				return true;\n" \
"			}\n" \
"		}\n" \
"		return false;\n" \
"	};\n" \
"\n" \
"Sizzle.attr = function( elem, name ) {\n" \
"	var val,\n" \
"		xml = isXML( elem );\n" \
"\n" \
"	if ( !xml ) {\n" \
"		name = name.toLowerCase();\n" \
"	}\n" \
"	if ( (val = Expr.attrHandle[ name ]) ) {\n" \
"		return val( elem );\n" \
"	}\n" \
"	if ( xml || assertAttributes ) {\n" \
"		return elem.getAttribute( name );\n" \
"	}\n" \
"	val = elem.getAttributeNode( name );\n" \
"	return val ?\n" \
"		typeof elem[ name ] === \"boolean\" ?\n" \
"			elem[ name ] ? name : null :\n" \
"			val.specified ? val.value : null :\n" \
"		null;\n" \
"};\n" \
"\n" \
"Expr = Sizzle.selectors = {\n" \
"\n" \
"	// Can be adjusted by the user\n" \
"	cacheLength: 50,\n" \
"\n" \
"	createPseudo: markFunction,\n" \
"\n" \
"	match: matchExpr,\n" \
"\n" \
"	// IE6/7 return a modified href\n" \
"	attrHandle: assertHrefNotNormalized ?\n" \
"		{} :\n" \
"		{\n" \
"			\"href\": function( elem ) {\n" \
"				return elem.getAttribute( \"href\", 2 );\n" \
"			},\n" \
"			\"type\": function( elem ) {\n" \
"				return elem.getAttribute(\"type\");\n" \
"			}\n" \
"		},\n" \
"\n" \
"	find: {\n" \
"		\"ID\": assertGetIdNotName ?\n" \
"			function( id, context, xml ) {\n" \
"				if ( typeof context.getElementById !== strundefined && !xml ) {\n" \
"					var m = context.getElementById( id );\n" \
"					// Check parentNode to catch when Blackberry 4.6 returns\n" \
"					// nodes that are no longer in the document #6963\n" \
"					return m && m.parentNode ? [m] : [];\n" \
"				}\n" \
"			} :\n" \
"			function( id, context, xml ) {\n" \
"				if ( typeof context.getElementById !== strundefined && !xml ) {\n" \
"					var m = context.getElementById( id );\n" \
"\n" \
"					return m ?\n" \
"						m.id === id || typeof m.getAttributeNode !== strundefined && m.getAttributeNode(\"id\").value === id ?\n" \
"							[m] :\n" \
"							undefined :\n" \
"						[];\n" \
"				}\n" \
"			},\n" \
"\n" \
"		\"TAG\": assertTagNameNoComments ?\n" \
"			function( tag, context ) {\n" \
"				if ( typeof context.getElementsByTagName !== strundefined ) {\n" \
"					return context.getElementsByTagName( tag );\n" \
"				}\n" \
"			} :\n" \
"			function( tag, context ) {\n" \
"				var results = context.getElementsByTagName( tag );\n" \
"\n" \
"				// Filter out possible comments\n" \
"				if ( tag === \"*\" ) {\n" \
"					var elem,\n" \
"						tmp = [],\n" \
"						i = 0;\n" \
"\n" \
"					for ( ; (elem = results[i]); i++ ) {\n" \
"						if ( elem.nodeType === 1 ) {\n" \
"							tmp.push( elem );\n" \
"						}\n" \
"					}\n" \
"\n" \
"					return tmp;\n" \
"				}\n" \
"				return results;\n" \
"			},\n" \
"\n" \
"		\"NAME\": assertUsableName && function( tag, context ) {\n" \
"			if ( typeof context.getElementsByName !== strundefined ) {\n" \
"				return context.getElementsByName( name );\n" \
"			}\n" \
"		},\n" \
"\n" \
"		\"CLASS\": assertUsableClassName && function( className, context, xml ) {\n" \
"			if ( typeof context.getElementsByClassName !== strundefined && !xml ) {\n" \
"				return context.getElementsByClassName( className );\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	relative: {\n" \
"		\">\": { dir: \"parentNode\", first: true },\n" \
"		\" \": { dir: \"parentNode\" },\n" \
"		\"+\": { dir: \"previousSibling\", first: true },\n" \
"		\"~\": { dir: \"previousSibling\" }\n" \
"	},\n" \
"\n" \
"	preFilter: {\n" \
"		\"ATTR\": function( match ) {\n" \
"			match[1] = match[1].replace( rbackslash, \"\" );\n" \
"\n" \
"			// Move the given value to match[3] whether quoted or unquoted\n" \
"			match[3] = ( match[4] || match[5] || \"\" ).replace( rbackslash, \"\" );\n" \
"\n" \
"			if ( match[2] === \"~=\" ) {\n" \
"				match[3] = \" \" + match[3] + \" \";\n" \
"			}\n" \
"\n" \
"			return match.slice( 0, 4 );\n" \
"		},\n" \
"\n" \
"		\"CHILD\": function( match ) {\n" \
"			/* matches from matchExpr[\"CHILD\"]\n" \
"				1 type (only|nth|...)\n" \
"				2 argument (even|odd|\\d*|\\d*n([+-]\\d+)?|...)\n" \
"				3 xn-component of xn+y argument ([+-]?\\d*n|)\n" \
"				4 sign of xn-component\n" \
"				5 x of xn-component\n" \
"				6 sign of y-component\n" \
"				7 y of y-component\n" \
"			*/\n" \
"			match[1] = match[1].toLowerCase();\n" \
"\n" \
"			if ( match[1] === \"nth\" ) {\n" \
"				// nth-child requires argument\n" \
"				if ( !match[2] ) {\n" \
"					Sizzle.error( match[0] );\n" \
"				}\n" \
"\n" \
"				// numeric x and y parameters for Expr.filter.CHILD\n" \
"				// remember that false/true cast respectively to 0/1\n" \
"				match[3] = +( match[3] ? match[4] + (match[5] || 1) : 2 * ( match[2] === \"even\" || match[2] === \"odd\" ) );\n" \
"				match[4] = +( ( match[6] + match[7] ) || match[2] === \"odd\" );\n" \
"\n" \
"			// other types prohibit arguments\n" \
"			} else if ( match[2] ) {\n" \
"				Sizzle.error( match[0] );\n" \
"			}\n" \
"\n" \
"			return match;\n" \
"		},\n" \
"\n" \
"		\"PSEUDO\": function( match ) {\n" \
"			var unquoted, excess;\n" \
"			if ( matchExpr[\"CHILD\"].test( match[0] ) ) {\n" \
"				return null;\n" \
"			}\n" \
"\n" \
"			if ( match[3] ) {\n" \
"				match[2] = match[3];\n" \
"			} else if ( (unquoted = match[4]) ) {\n" \
"				// Only check arguments that contain a pseudo\n" \
"				if ( rpseudo.test(unquoted) &&\n" \
"					// Get excess from tokenize (recursively)\n" \
"					(excess = tokenize( unquoted, true )) &&\n" \
"					// advance to the next closing parenthesis\n" \
"					(excess = unquoted.indexOf( \")\", unquoted.length - excess ) - unquoted.length) ) {\n" \
"\n" \
"					// excess is a negative index\n" \
"					unquoted = unquoted.slice( 0, excess );\n" \
"					match[0] = match[0].slice( 0, excess );\n" \
"				}\n" \
"				match[2] = unquoted;\n" \
"			}\n" \
"\n" \
"			// Return only captures needed by the pseudo filter method (type and argument)\n" \
"			return match.slice( 0, 3 );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	filter: {\n" \
"		\"ID\": assertGetIdNotName ?\n" \
"			function( id ) {\n" \
"				id = id.replace( rbackslash, \"\" );\n" \
"				return function( elem ) {\n" \
"					return elem.getAttribute(\"id\") === id;\n" \
"				};\n" \
"			} :\n" \
"			function( id ) {\n" \
"				id = id.replace( rbackslash, \"\" );\n" \
"				return function( elem ) {\n" \
"					var node = typeof elem.getAttributeNode !== strundefined && elem.getAttributeNode(\"id\");\n" \
"					return node && node.value === id;\n" \
"				};\n" \
"			},\n" \
"\n" \
"		\"TAG\": function( nodeName ) {\n" \
"			if ( nodeName === \"*\" ) {\n" \
"				return function() { return true; };\n" \
"			}\n" \
"			nodeName = nodeName.replace( rbackslash, \"\" ).toLowerCase();\n" \
"\n" \
"			return function( elem ) {\n" \
"				return elem.nodeName && elem.nodeName.toLowerCase() === nodeName;\n" \
"			};\n" \
"		},\n" \
"\n" \
"		\"CLASS\": function( className ) {\n" \
"			var pattern = classCache[ expando ][ className + \" \" ];\n" \
"\n" \
"			return pattern ||\n" \
"				(pattern = new RegExp( \"(^|\" + whitespace + \")\" + className + \"(\" + whitespace + \"|$)\" )) &&\n" \
"				classCache( className, function( elem ) {\n" \
"					return pattern.test( elem.className || (typeof elem.getAttribute !== strundefined && elem.getAttribute(\"class\")) || \"\" );\n" \
"				});\n" \
"		},\n" \
"\n" \
"		\"ATTR\": function( name, operator, check ) {\n" \
"			return function( elem, context ) {\n" \
"				var result = Sizzle.attr( elem, name );\n" \
"\n" \
"				if ( result == null ) {\n" \
"					return operator === \"!=\";\n" \
"				}\n" \
"				if ( !operator ) {\n" \
"					return true;\n" \
"				}\n" \
"\n" \
"				result += \"\";\n" \
"\n" \
"				return operator === \"=\" ? result === check :\n" \
"					operator === \"!=\" ? result !== check :\n" \
"					operator === \"^=\" ? check && result.indexOf( check ) === 0 :\n" \
"					operator === \"*=\" ? check && result.indexOf( check ) > -1 :\n" \
"					operator === \"$=\" ? check && result.substr( result.length - check.length ) === check :\n" \
"					operator === \"~=\" ? ( \" \" + result + \" \" ).indexOf( check ) > -1 :\n" \
"					operator === \"|=\" ? result === check || result.substr( 0, check.length + 1 ) === check + \"-\" :\n" \
"					false;\n" \
"			};\n" \
"		},\n" \
"\n" \
"		\"CHILD\": function( type, argument, first, last ) {\n" \
"\n" \
"			if ( type === \"nth\" ) {\n" \
"				return function( elem ) {\n" \
"					var node, diff,\n" \
"						parent = elem.parentNode;\n" \
"\n" \
"					if ( first === 1 && last === 0 ) {\n" \
"						return true;\n" \
"					}\n" \
"\n" \
"					if ( parent ) {\n" \
"						diff = 0;\n" \
"						for ( node = parent.firstChild; node; node = node.nextSibling ) {\n" \
"							if ( node.nodeType === 1 ) {\n" \
"								diff++;\n" \
"								if ( elem === node ) {\n" \
"									break;\n" \
"								}\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"\n" \
"					// Incorporate the offset (or cast to NaN), then check against cycle size\n" \
"					diff -= last;\n" \
"					return diff === first || ( diff % first === 0 && diff / first >= 0 );\n" \
"				};\n" \
"			}\n" \
"\n" \
"			return function( elem ) {\n" \
"				var node = elem;\n" \
"\n" \
"				switch ( type ) {\n" \
"					case \"only\":\n" \
"					case \"first\":\n" \
"						while ( (node = node.previousSibling) ) {\n" \
"							if ( node.nodeType === 1 ) {\n" \
"								return false;\n" \
"							}\n" \
"						}\n" \
"\n" \
"						if ( type === \"first\" ) {\n" \
"							return true;\n" \
"						}\n" \
"\n" \
"						node = elem;\n" \
"\n" \
"						/* falls through */\n" \
"					case \"last\":\n" \
"						while ( (node = node.nextSibling) ) {\n" \
"							if ( node.nodeType === 1 ) {\n" \
"								return false;\n" \
"							}\n" \
"						}\n" \
"\n" \
"						return true;\n" \
"				}\n" \
"			};\n" \
"		},\n" \
"\n" \
"		\"PSEUDO\": function( pseudo, argument ) {\n" \
"			// pseudo-class names are case-insensitive\n" \
"			// http://www.w3.org/TR/selectors/#pseudo-classes\n" \
"			// Prioritize by case sensitivity in case custom pseudos are added with uppercase letters\n" \
"			// Remember that setFilters inherits from pseudos\n" \
"			var args,\n" \
"				fn = Expr.pseudos[ pseudo ] || Expr.setFilters[ pseudo.toLowerCase() ] ||\n" \
"					Sizzle.error( \"unsupported pseudo: \" + pseudo );\n" \
"\n" \
"			// The user may use createPseudo to indicate that\n" \
"			// arguments are needed to create the filter function\n" \
"			// just as Sizzle does\n" \
"			if ( fn[ expando ] ) {\n" \
"				return fn( argument );\n" \
"			}\n" \
"\n" \
"			// But maintain support for old signatures\n" \
"			if ( fn.length > 1 ) {\n" \
"				args = [ pseudo, pseudo, \"\", argument ];\n" \
"				return Expr.setFilters.hasOwnProperty( pseudo.toLowerCase() ) ?\n" \
"					markFunction(function( seed, matches ) {\n" \
"						var idx,\n" \
"							matched = fn( seed, argument ),\n" \
"							i = matched.length;\n" \
"						while ( i-- ) {\n" \
"							idx = indexOf.call( seed, matched[i] );\n" \
"							seed[ idx ] = !( matches[ idx ] = matched[i] );\n" \
"						}\n" \
"					}) :\n" \
"					function( elem ) {\n" \
"						return fn( elem, 0, args );\n" \
"					};\n" \
"			}\n" \
"\n" \
"			return fn;\n" \
"		}\n" \
"	},\n" \
"\n" \
"	pseudos: {\n" \
"		\"not\": markFunction(function( selector ) {\n" \
"			// Trim the selector passed to compile\n" \
"			// to avoid treating leading and trailing\n" \
"			// spaces as combinators\n" \
"			var input = [],\n" \
"				results = [],\n" \
"				matcher = compile( selector.replace( rtrim, \"$1\" ) );\n" \
"\n" \
"			return matcher[ expando ] ?\n" \
"				markFunction(function( seed, matches, context, xml ) {\n" \
"					var elem,\n" \
"						unmatched = matcher( seed, null, xml, [] ),\n" \
"						i = seed.length;\n" \
"\n" \
"					// Match elements unmatched by `matcher`\n" \
"					while ( i-- ) {\n" \
"						if ( (elem = unmatched[i]) ) {\n" \
"							seed[i] = !(matches[i] = elem);\n" \
"						}\n" \
"					}\n" \
"				}) :\n" \
"				function( elem, context, xml ) {\n" \
"					input[0] = elem;\n" \
"					matcher( input, null, xml, results );\n" \
"					return !results.pop();\n" \
"				};\n" \
"		}),\n" \
"\n" \
"		\"has\": markFunction(function( selector ) {\n" \
"			return function( elem ) {\n" \
"				return Sizzle( selector, elem ).length > 0;\n" \
"			};\n" \
"		}),\n" \
"\n" \
"		\"contains\": markFunction(function( text ) {\n" \
"			return function( elem ) {\n" \
"				return ( elem.textContent || elem.innerText || getText( elem ) ).indexOf( text ) > -1;\n" \
"			};\n" \
"		}),\n" \
"\n" \
"		\"enabled\": function( elem ) {\n" \
"			return elem.disabled === false;\n" \
"		},\n" \
"\n" \
"		\"disabled\": function( elem ) {\n" \
"			return elem.disabled === true;\n" \
"		},\n" \
"\n" \
"		\"checked\": function( elem ) {\n" \
"			// In CSS3, :checked should return both checked and selected elements\n" \
"			// http://www.w3.org/TR/2011/REC-css3-selectors-20110929/#checked\n" \
"			var nodeName = elem.nodeName.toLowerCase();\n" \
"			return (nodeName === \"input\" && !!elem.checked) || (nodeName === \"option\" && !!elem.selected);\n" \
"		},\n" \
"\n" \
"		\"selected\": function( elem ) {\n" \
"			// Accessing this property makes selected-by-default\n" \
"			// options in Safari work properly\n" \
"			if ( elem.parentNode ) {\n" \
"				elem.parentNode.selectedIndex;\n" \
"			}\n" \
"\n" \
"			return elem.selected === true;\n" \
"		},\n" \
"\n" \
"		\"parent\": function( elem ) {\n" \
"			return !Expr.pseudos[\"empty\"]( elem );\n" \
"		},\n" \
"\n" \
"		\"empty\": function( elem ) {\n" \
"			// http://www.w3.org/TR/selectors/#empty-pseudo\n" \
"			// :empty is only affected by element nodes and content nodes(including text(3), cdata(4)),\n" \
"			//   not comment, processing instructions, or others\n" \
"			// Thanks to Diego Perini for the nodeName shortcut\n" \
"			//   Greater than \"@\" means alpha characters (specifically not starting with \"#\" or \"?\")\n" \
"			var nodeType;\n" \
"			elem = elem.firstChild;\n" \
"			while ( elem ) {\n" \
"				if ( elem.nodeName > \"@\" || (nodeType = elem.nodeType) === 3 || nodeType === 4 ) {\n" \
"					return false;\n" \
"				}\n" \
"				elem = elem.nextSibling;\n" \
"			}\n" \
"			return true;\n" \
"		},\n" \
"\n" \
"		\"header\": function( elem ) {\n" \
"			return rheader.test( elem.nodeName );\n" \
"		},\n" \
"\n" \
"		\"text\": function( elem ) {\n" \
"			var type, attr;\n" \
"			// IE6 and 7 will map elem.type to 'text' for new HTML5 types (search, etc)\n" \
"			// use getAttribute instead to test this case\n" \
"			return elem.nodeName.toLowerCase() === \"input\" &&\n" \
"				(type = elem.type) === \"text\" &&\n" \
"				( (attr = elem.getAttribute(\"type\")) == null || attr.toLowerCase() === type );\n" \
"		},\n" \
"\n" \
"		// Input types\n" \
"		\"radio\": createInputPseudo(\"radio\"),\n" \
"		\"checkbox\": createInputPseudo(\"checkbox\"),\n" \
"		\"file\": createInputPseudo(\"file\"),\n" \
"		\"password\": createInputPseudo(\"password\"),\n" \
"		\"image\": createInputPseudo(\"image\"),\n" \
"\n" \
"		\"submit\": createButtonPseudo(\"submit\"),\n" \
"		\"reset\": createButtonPseudo(\"reset\"),\n" \
"\n" \
"		\"button\": function( elem ) {\n" \
"			var name = elem.nodeName.toLowerCase();\n" \
"			return name === \"input\" && elem.type === \"button\" || name === \"button\";\n" \
"		},\n" \
"\n" \
"		\"input\": function( elem ) {\n" \
"			return rinputs.test( elem.nodeName );\n" \
"		},\n" \
"\n" \
"		\"focus\": function( elem ) {\n" \
"			var doc = elem.ownerDocument;\n" \
"			return elem === doc.activeElement && (!doc.hasFocus || doc.hasFocus()) && !!(elem.type || elem.href || ~elem.tabIndex);\n" \
"		},\n" \
"\n" \
"		\"active\": function( elem ) {\n" \
"			return elem === elem.ownerDocument.activeElement;\n" \
"		},\n" \
"\n" \
"		// Positional types\n" \
"		\"first\": createPositionalPseudo(function() {\n" \
"			return [ 0 ];\n" \
"		}),\n" \
"\n" \
"		\"last\": createPositionalPseudo(function( matchIndexes, length ) {\n" \
"			return [ length - 1 ];\n" \
"		}),\n" \
"\n" \
"		\"eq\": createPositionalPseudo(function( matchIndexes, length, argument ) {\n" \
"			return [ argument < 0 ? argument + length : argument ];\n" \
"		}),\n" \
"\n" \
"		\"even\": createPositionalPseudo(function( matchIndexes, length ) {\n" \
"			for ( var i = 0; i < length; i += 2 ) {\n" \
"				matchIndexes.push( i );\n" \
"			}\n" \
"			return matchIndexes;\n" \
"		}),\n" \
"\n" \
"		\"odd\": createPositionalPseudo(function( matchIndexes, length ) {\n" \
"			for ( var i = 1; i < length; i += 2 ) {\n" \
"				matchIndexes.push( i );\n" \
"			}\n" \
"			return matchIndexes;\n" \
"		}),\n" \
"\n" \
"		\"lt\": createPositionalPseudo(function( matchIndexes, length, argument ) {\n" \
"			for ( var i = argument < 0 ? argument + length : argument; --i >= 0; ) {\n" \
"				matchIndexes.push( i );\n" \
"			}\n" \
"			return matchIndexes;\n" \
"		}),\n" \
"\n" \
"		\"gt\": createPositionalPseudo(function( matchIndexes, length, argument ) {\n" \
"			for ( var i = argument < 0 ? argument + length : argument; ++i < length; ) {\n" \
"				matchIndexes.push( i );\n" \
"			}\n" \
"			return matchIndexes;\n" \
"		})\n" \
"	}\n" \
"};\n" \
"\n" \
"function siblingCheck( a, b, ret ) {\n" \
"	if ( a === b ) {\n" \
"		return ret;\n" \
"	}\n" \
"\n" \
"	var cur = a.nextSibling;\n" \
"\n" \
"	while ( cur ) {\n" \
"		if ( cur === b ) {\n" \
"			return -1;\n" \
"		}\n" \
"\n" \
"		cur = cur.nextSibling;\n" \
"	}\n" \
"\n" \
"	return 1;\n" \
"}\n" \
"\n" \
"sortOrder = docElem.compareDocumentPosition ?\n" \
"	function( a, b ) {\n" \
"		if ( a === b ) {\n" \
"			hasDuplicate = true;\n" \
"			return 0;\n" \
"		}\n" \
"\n" \
"		return ( !a.compareDocumentPosition || !b.compareDocumentPosition ?\n" \
"			a.compareDocumentPosition :\n" \
"			a.compareDocumentPosition(b) & 4\n" \
"		) ? -1 : 1;\n" \
"	} :\n" \
"	function( a, b ) {\n" \
"		// The nodes are identical, we can exit early\n" \
"		if ( a === b ) {\n" \
"			hasDuplicate = true;\n" \
"			return 0;\n" \
"\n" \
"		// Fallback to using sourceIndex (in IE) if it's available on both nodes\n" \
"		} else if ( a.sourceIndex && b.sourceIndex ) {\n" \
"			return a.sourceIndex - b.sourceIndex;\n" \
"		}\n" \
"\n" \
"		var al, bl,\n" \
"			ap = [],\n" \
"			bp = [],\n" \
"			aup = a.parentNode,\n" \
"			bup = b.parentNode,\n" \
"			cur = aup;\n" \
"\n" \
"		// If the nodes are siblings (or identical) we can do a quick check\n" \
"		if ( aup === bup ) {\n" \
"			return siblingCheck( a, b );\n" \
"\n" \
"		// If no parents were found then the nodes are disconnected\n" \
"		} else if ( !aup ) {\n" \
"			return -1;\n" \
"\n" \
"		} else if ( !bup ) {\n" \
"			return 1;\n" \
"		}\n" \
"\n" \
"		// Otherwise they're somewhere else in the tree so we need\n" \
"		// to build up a full list of the parentNodes for comparison\n" \
"		while ( cur ) {\n" \
"			ap.unshift( cur );\n" \
"			cur = cur.parentNode;\n" \
"		}\n" \
"\n" \
"		cur = bup;\n" \
"\n" \
"		while ( cur ) {\n" \
"			bp.unshift( cur );\n" \
"			cur = cur.parentNode;\n" \
"		}\n" \
"\n" \
"		al = ap.length;\n" \
"		bl = bp.length;\n" \
"\n" \
"		// Start walking down the tree looking for a discrepancy\n" \
"		for ( var i = 0; i < al && i < bl; i++ ) {\n" \
"			if ( ap[i] !== bp[i] ) {\n" \
"				return siblingCheck( ap[i], bp[i] );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// We ended someplace up the tree so do a sibling check\n" \
"		return i === al ?\n" \
"			siblingCheck( a, bp[i], -1 ) :\n" \
"			siblingCheck( ap[i], b, 1 );\n" \
"	};\n" \
"\n" \
"// Always assume the presence of duplicates if sort doesn't\n" \
"// pass them to our comparison function (as in Google Chrome).\n" \
"[0, 0].sort( sortOrder );\n" \
"baseHasDuplicate = !hasDuplicate;\n" \
"\n" \
"// Document sorting and removing duplicates\n" \
"Sizzle.uniqueSort = function( results ) {\n" \
"	var elem,\n" \
"		duplicates = [],\n" \
"		i = 1,\n" \
"		j = 0;\n" \
"\n" \
"	hasDuplicate = baseHasDuplicate;\n" \
"	results.sort( sortOrder );\n" \
"\n" \
"	if ( hasDuplicate ) {\n" \
"		for ( ; (elem = results[i]); i++ ) {\n" \
"			if ( elem === results[ i - 1 ] ) {\n" \
"				j = duplicates.push( i );\n" \
"			}\n" \
"		}\n" \
"		while ( j-- ) {\n" \
"			results.splice( duplicates[ j ], 1 );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return results;\n" \
"};\n" \
"\n" \
"Sizzle.error = function( msg ) {\n" \
"	throw new Error( \"Syntax error, unrecognized expression: \" + msg );\n" \
"};\n" \
"\n" \
"function tokenize( selector, parseOnly ) {\n" \
"	var matched, match, tokens, type,\n" \
"		soFar, groups, preFilters,\n" \
"		cached = tokenCache[ expando ][ selector + \" \" ];\n" \
"\n" \
"	if ( cached ) {\n" \
"		return parseOnly ? 0 : cached.slice( 0 );\n" \
"	}\n" \
"\n" \
"	soFar = selector;\n" \
"	groups = [];\n" \
"	preFilters = Expr.preFilter;\n" \
"\n" \
"	while ( soFar ) {\n" \
"\n" \
"		// Comma and first run\n" \
"		if ( !matched || (match = rcomma.exec( soFar )) ) {\n" \
"			if ( match ) {\n" \
"				// Don't consume trailing commas as valid\n" \
"				soFar = soFar.slice( match[0].length ) || soFar;\n" \
"			}\n" \
"			groups.push( tokens = [] );\n" \
"		}\n" \
"\n" \
"		matched = false;\n" \
"\n" \
"		// Combinators\n" \
"		if ( (match = rcombinators.exec( soFar )) ) {\n" \
"			tokens.push( matched = new Token( match.shift() ) );\n" \
"			soFar = soFar.slice( matched.length );\n" \
"\n" \
"			// Cast descendant combinators to space\n" \
"			matched.type = match[0].replace( rtrim, \" \" );\n" \
"		}\n" \
"\n" \
"		// Filters\n" \
"		for ( type in Expr.filter ) {\n" \
"			if ( (match = matchExpr[ type ].exec( soFar )) && (!preFilters[ type ] ||\n" \
"				(match = preFilters[ type ]( match ))) ) {\n" \
"\n" \
"				tokens.push( matched = new Token( match.shift() ) );\n" \
"				soFar = soFar.slice( matched.length );\n" \
"				matched.type = type;\n" \
"				matched.matches = match;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		if ( !matched ) {\n" \
"			break;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Return the length of the invalid excess\n" \
"	// if we're just parsing\n" \
"	// Otherwise, throw an error or return tokens\n" \
"	return parseOnly ?\n" \
"		soFar.length :\n" \
"		soFar ?\n" \
"			Sizzle.error( selector ) :\n" \
"			// Cache the tokens\n" \
"			tokenCache( selector, groups ).slice( 0 );\n" \
"}\n" \
"\n" \
"function addCombinator( matcher, combinator, base ) {\n" \
"	var dir = combinator.dir,\n" \
"		checkNonElements = base && combinator.dir === \"parentNode\",\n" \
"		doneName = done++;\n" \
"\n" \
"	return combinator.first ?\n" \
"		// Check against closest ancestor/preceding element\n" \
"		function( elem, context, xml ) {\n" \
"			while ( (elem = elem[ dir ]) ) {\n" \
"				if ( checkNonElements || elem.nodeType === 1  ) {\n" \
"					return matcher( elem, context, xml );\n" \
"				}\n" \
"			}\n" \
"		} :\n" \
"\n" \
"		// Check against all ancestor/preceding elements\n" \
"		function( elem, context, xml ) {\n" \
"			// We can't set arbitrary data on XML nodes, so they don't benefit from dir caching\n" \
"			if ( !xml ) {\n" \
"				var cache,\n" \
"					dirkey = dirruns + \" \" + doneName + \" \",\n" \
"					cachedkey = dirkey + cachedruns;\n" \
"				while ( (elem = elem[ dir ]) ) {\n" \
"					if ( checkNonElements || elem.nodeType === 1 ) {\n" \
"						if ( (cache = elem[ expando ]) === cachedkey ) {\n" \
"							return elem.sizset;\n" \
"						} else if ( typeof cache === \"string\" && cache.indexOf(dirkey) === 0 ) {\n" \
"							if ( elem.sizset ) {\n" \
"								return elem;\n" \
"							}\n" \
"						} else {\n" \
"							elem[ expando ] = cachedkey;\n" \
"							if ( matcher( elem, context, xml ) ) {\n" \
"								elem.sizset = true;\n" \
"								return elem;\n" \
"							}\n" \
"							elem.sizset = false;\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			} else {\n" \
"				while ( (elem = elem[ dir ]) ) {\n" \
"					if ( checkNonElements || elem.nodeType === 1 ) {\n" \
"						if ( matcher( elem, context, xml ) ) {\n" \
"							return elem;\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		};\n" \
"}\n" \
"\n" \
"function elementMatcher( matchers ) {\n" \
"	return matchers.length > 1 ?\n" \
"		function( elem, context, xml ) {\n" \
"			var i = matchers.length;\n" \
"			while ( i-- ) {\n" \
"				if ( !matchers[i]( elem, context, xml ) ) {\n" \
"					return false;\n" \
"				}\n" \
"			}\n" \
"			return true;\n" \
"		} :\n" \
"		matchers[0];\n" \
"}\n" \
"\n" \
"function condense( unmatched, map, filter, context, xml ) {\n" \
"	var elem,\n" \
"		newUnmatched = [],\n" \
"		i = 0,\n" \
"		len = unmatched.length,\n" \
"		mapped = map != null;\n" \
"\n" \
"	for ( ; i < len; i++ ) {\n" \
"		if ( (elem = unmatched[i]) ) {\n" \
"			if ( !filter || filter( elem, context, xml ) ) {\n" \
"				newUnmatched.push( elem );\n" \
"				if ( mapped ) {\n" \
"					map.push( i );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return newUnmatched;\n" \
"}\n" \
"\n" \
"function setMatcher( preFilter, selector, matcher, postFilter, postFinder, postSelector ) {\n" \
"	if ( postFilter && !postFilter[ expando ] ) {\n" \
"		postFilter = setMatcher( postFilter );\n" \
"	}\n" \
"	if ( postFinder && !postFinder[ expando ] ) {\n" \
"		postFinder = setMatcher( postFinder, postSelector );\n" \
"	}\n" \
"	return markFunction(function( seed, results, context, xml ) {\n" \
"		var temp, i, elem,\n" \
"			preMap = [],\n" \
"			postMap = [],\n" \
"			preexisting = results.length,\n" \
"\n" \
"			// Get initial elements from seed or context\n" \
"			elems = seed || multipleContexts( selector || \"*\", context.nodeType ? [ context ] : context, [] ),\n" \
"\n" \
"			// Prefilter to get matcher input, preserving a map for seed-results synchronization\n" \
"			matcherIn = preFilter && ( seed || !selector ) ?\n" \
"				condense( elems, preMap, preFilter, context, xml ) :\n" \
"				elems,\n" \
"\n" \
"			matcherOut = matcher ?\n" \
"				// If we have a postFinder, or filtered seed, or non-seed postFilter or preexisting results,\n" \
"				postFinder || ( seed ? preFilter : preexisting || postFilter ) ?\n" \
"\n" \
"					// ...intermediate processing is necessary\n" \
"					[] :\n" \
"\n" \
"					// ...otherwise use results directly\n" \
"					results :\n" \
"				matcherIn;\n" \
"\n" \
"		// Find primary matches\n" \
"		if ( matcher ) {\n" \
"			matcher( matcherIn, matcherOut, context, xml );\n" \
"		}\n" \
"\n" \
"		// Apply postFilter\n" \
"		if ( postFilter ) {\n" \
"			temp = condense( matcherOut, postMap );\n" \
"			postFilter( temp, [], context, xml );\n" \
"\n" \
"			// Un-match failing elements by moving them back to matcherIn\n" \
"			i = temp.length;\n" \
"			while ( i-- ) {\n" \
"				if ( (elem = temp[i]) ) {\n" \
"					matcherOut[ postMap[i] ] = !(matcherIn[ postMap[i] ] = elem);\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		if ( seed ) {\n" \
"			if ( postFinder || preFilter ) {\n" \
"				if ( postFinder ) {\n" \
"					// Get the final matcherOut by condensing this intermediate into postFinder contexts\n" \
"					temp = [];\n" \
"					i = matcherOut.length;\n" \
"					while ( i-- ) {\n" \
"						if ( (elem = matcherOut[i]) ) {\n" \
"							// Restore matcherIn since elem is not yet a final match\n" \
"							temp.push( (matcherIn[i] = elem) );\n" \
"						}\n" \
"					}\n" \
"					postFinder( null, (matcherOut = []), temp, xml );\n" \
"				}\n" \
"\n" \
"				// Move matched elements from seed to results to keep them synchronized\n" \
"				i = matcherOut.length;\n" \
"				while ( i-- ) {\n" \
"					if ( (elem = matcherOut[i]) &&\n" \
"						(temp = postFinder ? indexOf.call( seed, elem ) : preMap[i]) > -1 ) {\n" \
"\n" \
"						seed[temp] = !(results[temp] = elem);\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"		// Add elements to results, through postFinder if defined\n" \
"		} else {\n" \
"			matcherOut = condense(\n" \
"				matcherOut === results ?\n" \
"					matcherOut.splice( preexisting, matcherOut.length ) :\n" \
"					matcherOut\n" \
"			);\n" \
"			if ( postFinder ) {\n" \
"				postFinder( null, results, matcherOut, xml );\n" \
"			} else {\n" \
"				push.apply( results, matcherOut );\n" \
"			}\n" \
"		}\n" \
"	});\n" \
"}\n" \
"\n" \
"function matcherFromTokens( tokens ) {\n" \
"	var checkContext, matcher, j,\n" \
"		len = tokens.length,\n" \
"		leadingRelative = Expr.relative[ tokens[0].type ],\n" \
"		implicitRelative = leadingRelative || Expr.relative[\" \"],\n" \
"		i = leadingRelative ? 1 : 0,\n" \
"\n" \
"		// The foundational matcher ensures that elements are reachable from top-level context(s)\n" \
"		matchContext = addCombinator( function( elem ) {\n" \
"			return elem === checkContext;\n" \
"		}, implicitRelative, true ),\n" \
"		matchAnyContext = addCombinator( function( elem ) {\n" \
"			return indexOf.call( checkContext, elem ) > -1;\n" \
"		}, implicitRelative, true ),\n" \
"		matchers = [ function( elem, context, xml ) {\n" \
"			return ( !leadingRelative && ( xml || context !== outermostContext ) ) || (\n" \
"				(checkContext = context).nodeType ?\n" \
"					matchContext( elem, context, xml ) :\n" \
"					matchAnyContext( elem, context, xml ) );\n" \
"		} ];\n" \
"\n" \
"	for ( ; i < len; i++ ) {\n" \
"		if ( (matcher = Expr.relative[ tokens[i].type ]) ) {\n" \
"			matchers = [ addCombinator( elementMatcher( matchers ), matcher ) ];\n" \
"		} else {\n" \
"			matcher = Expr.filter[ tokens[i].type ].apply( null, tokens[i].matches );\n" \
"\n" \
"			// Return special upon seeing a positional matcher\n" \
"			if ( matcher[ expando ] ) {\n" \
"				// Find the next relative operator (if any) for proper handling\n" \
"				j = ++i;\n" \
"				for ( ; j < len; j++ ) {\n" \
"					if ( Expr.relative[ tokens[j].type ] ) {\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"				return setMatcher(\n" \
"					i > 1 && elementMatcher( matchers ),\n" \
"					i > 1 && tokens.slice( 0, i - 1 ).join(\"\").replace( rtrim, \"$1\" ),\n" \
"					matcher,\n" \
"					i < j && matcherFromTokens( tokens.slice( i, j ) ),\n" \
"					j < len && matcherFromTokens( (tokens = tokens.slice( j )) ),\n" \
"					j < len && tokens.join(\"\")\n" \
"				);\n" \
"			}\n" \
"			matchers.push( matcher );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return elementMatcher( matchers );\n" \
"}\n" \
"\n" \
"function matcherFromGroupMatchers( elementMatchers, setMatchers ) {\n" \
"	var bySet = setMatchers.length > 0,\n" \
"		byElement = elementMatchers.length > 0,\n" \
"		superMatcher = function( seed, context, xml, results, expandContext ) {\n" \
"			var elem, j, matcher,\n" \
"				setMatched = [],\n" \
"				matchedCount = 0,\n" \
"				i = \"0\",\n" \
"				unmatched = seed && [],\n" \
"				outermost = expandContext != null,\n" \
"				contextBackup = outermostContext,\n" \
"				// We must always have either seed elements or context\n" \
"				elems = seed || byElement && Expr.find[\"TAG\"]( \"*\", expandContext && context.parentNode || context ),\n" \
"				// Nested matchers should use non-integer dirruns\n" \
"				dirrunsUnique = (dirruns += contextBackup == null ? 1 : Math.E);\n" \
"\n" \
"			if ( outermost ) {\n" \
"				outermostContext = context !== document && context;\n" \
"				cachedruns = superMatcher.el;\n" \
"			}\n" \
"\n" \
"			// Add elements passing elementMatchers directly to results\n" \
"			for ( ; (elem = elems[i]) != null; i++ ) {\n" \
"				if ( byElement && elem ) {\n" \
"					for ( j = 0; (matcher = elementMatchers[j]); j++ ) {\n" \
"						if ( matcher( elem, context, xml ) ) {\n" \
"							results.push( elem );\n" \
"							break;\n" \
"						}\n" \
"					}\n" \
"					if ( outermost ) {\n" \
"						dirruns = dirrunsUnique;\n" \
"						cachedruns = ++superMatcher.el;\n" \
"					}\n" \
"				}\n" \
"\n" \
"				// Track unmatched elements for set filters\n" \
"				if ( bySet ) {\n" \
"					// They will have gone through all possible matchers\n" \
"					if ( (elem = !matcher && elem) ) {\n" \
"						matchedCount--;\n" \
"					}\n" \
"\n" \
"					// Lengthen the array for every element, matched or not\n" \
"					if ( seed ) {\n" \
"						unmatched.push( elem );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Apply set filters to unmatched elements\n" \
"			matchedCount += i;\n" \
"			if ( bySet && i !== matchedCount ) {\n" \
"				for ( j = 0; (matcher = setMatchers[j]); j++ ) {\n" \
"					matcher( unmatched, setMatched, context, xml );\n" \
"				}\n" \
"\n" \
"				if ( seed ) {\n" \
"					// Reintegrate element matches to eliminate the need for sorting\n" \
"					if ( matchedCount > 0 ) {\n" \
"						while ( i-- ) {\n" \
"							if ( !(unmatched[i] || setMatched[i]) ) {\n" \
"								setMatched[i] = pop.call( results );\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"\n" \
"					// Discard index placeholder values to get only actual matches\n" \
"					setMatched = condense( setMatched );\n" \
"				}\n" \
"\n" \
"				// Add matches to results\n" \
"				push.apply( results, setMatched );\n" \
"\n" \
"				// Seedless set matches succeeding multiple successful matchers stipulate sorting\n" \
"				if ( outermost && !seed && setMatched.length > 0 &&\n" \
"					( matchedCount + setMatchers.length ) > 1 ) {\n" \
"\n" \
"					Sizzle.uniqueSort( results );\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Override manipulation of globals by nested matchers\n" \
"			if ( outermost ) {\n" \
"				dirruns = dirrunsUnique;\n" \
"				outermostContext = contextBackup;\n" \
"			}\n" \
"\n" \
"			return unmatched;\n" \
"		};\n" \
"\n" \
"	superMatcher.el = 0;\n" \
"	return bySet ?\n" \
"		markFunction( superMatcher ) :\n" \
"		superMatcher;\n" \
"}\n" \
"\n" \
"compile = Sizzle.compile = function( selector, group /* Internal Use Only */ ) {\n" \
"	var i,\n" \
"		setMatchers = [],\n" \
"		elementMatchers = [],\n" \
"		cached = compilerCache[ expando ][ selector + \" \" ];\n" \
"\n" \
"	if ( !cached ) {\n" \
"		// Generate a function of recursive functions that can be used to check each element\n" \
"		if ( !group ) {\n" \
"			group = tokenize( selector );\n" \
"		}\n" \
"		i = group.length;\n" \
"		while ( i-- ) {\n" \
"			cached = matcherFromTokens( group[i] );\n" \
"			if ( cached[ expando ] ) {\n" \
"				setMatchers.push( cached );\n" \
"			} else {\n" \
"				elementMatchers.push( cached );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Cache the compiled function\n" \
"		cached = compilerCache( selector, matcherFromGroupMatchers( elementMatchers, setMatchers ) );\n" \
"	}\n" \
"	return cached;\n" \
"};\n" \
"\n" \
"function multipleContexts( selector, contexts, results ) {\n" \
"	var i = 0,\n" \
"		len = contexts.length;\n" \
"	for ( ; i < len; i++ ) {\n" \
"		Sizzle( selector, contexts[i], results );\n" \
"	}\n" \
"	return results;\n" \
"}\n" \
"\n" \
"function select( selector, context, results, seed, xml ) {\n" \
"	var i, tokens, token, type, find,\n" \
"		match = tokenize( selector ),\n" \
"		j = match.length;\n" \
"\n" \
"	if ( !seed ) {\n" \
"		// Try to minimize operations if there is only one group\n" \
"		if ( match.length === 1 ) {\n" \
"\n" \
"			// Take a shortcut and set the context if the root selector is an ID\n" \
"			tokens = match[0] = match[0].slice( 0 );\n" \
"			if ( tokens.length > 2 && (token = tokens[0]).type === \"ID\" &&\n" \
"					context.nodeType === 9 && !xml &&\n" \
"					Expr.relative[ tokens[1].type ] ) {\n" \
"\n" \
"				context = Expr.find[\"ID\"]( token.matches[0].replace( rbackslash, \"\" ), context, xml )[0];\n" \
"				if ( !context ) {\n" \
"					return results;\n" \
"				}\n" \
"\n" \
"				selector = selector.slice( tokens.shift().length );\n" \
"			}\n" \
"\n" \
"			// Fetch a seed set for right-to-left matching\n" \
"			for ( i = matchExpr[\"POS\"].test( selector ) ? -1 : tokens.length - 1; i >= 0; i-- ) {\n" \
"				token = tokens[i];\n" \
"\n" \
"				// Abort if we hit a combinator\n" \
"				if ( Expr.relative[ (type = token.type) ] ) {\n" \
"					break;\n" \
"				}\n" \
"				if ( (find = Expr.find[ type ]) ) {\n" \
"					// Search, expanding context for leading sibling combinators\n" \
"					if ( (seed = find(\n" \
"						token.matches[0].replace( rbackslash, \"\" ),\n" \
"						rsibling.test( tokens[0].type ) && context.parentNode || context,\n" \
"						xml\n" \
"					)) ) {\n" \
"\n" \
"						// If seed is empty or no tokens remain, we can return early\n" \
"						tokens.splice( i, 1 );\n" \
"						selector = seed.length && tokens.join(\"\");\n" \
"						if ( !selector ) {\n" \
"							push.apply( results, slice.call( seed, 0 ) );\n" \
"							return results;\n" \
"						}\n" \
"\n" \
"						break;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Compile and execute a filtering function\n" \
"	// Provide `match` to avoid retokenization if we modified the selector above\n" \
"	compile( selector, match )(\n" \
"		seed,\n" \
"		context,\n" \
"		xml,\n" \
"		results,\n" \
"		rsibling.test( selector )\n" \
"	);\n" \
"	return results;\n" \
"}\n" \
"\n" \
"if ( document.querySelectorAll ) {\n" \
"	(function() {\n" \
"		var disconnectedMatch,\n" \
"			oldSelect = select,\n" \
"			rescape = /'|\\\\/g,\n" \
"			rattributeQuotes = /\\=[\\x20\\t\\r\\n\\f]*([^'\"\\]]*)[\\x20\\t\\r\\n\\f]*\\]/g,\n" \
"\n" \
"			// qSa(:focus) reports false when true (Chrome 21), no need to also add to buggyMatches since matches checks buggyQSA\n" \
"			// A support test would require too much code (would include document ready)\n" \
"			rbuggyQSA = [ \":focus\" ],\n" \
"\n" \
"			// matchesSelector(:active) reports false when true (IE9/Opera 11.5)\n" \
"			// A support test would require too much code (would include document ready)\n" \
"			// just skip matchesSelector for :active\n" \
"			rbuggyMatches = [ \":active\" ],\n" \
"			matches = docElem.matchesSelector ||\n" \
"				docElem.mozMatchesSelector ||\n" \
"				docElem.webkitMatchesSelector ||\n" \
"				docElem.oMatchesSelector ||\n" \
"				docElem.msMatchesSelector;\n" \
"\n" \
"		// Build QSA regex\n" \
"		// Regex strategy adopted from Diego Perini\n" \
"		assert(function( div ) {\n" \
"			// Select is set to empty string on purpose\n" \
"			// This is to test IE's treatment of not explictly\n" \
"			// setting a boolean content attribute,\n" \
"			// since its presence should be enough\n" \
"			// http://bugs.jquery.com/ticket/12359\n" \
"			div.innerHTML = \"<select><option selected=''></option></select>\";\n" \
"\n" \
"			// IE8 - Some boolean attributes are not treated correctly\n" \
"			if ( !div.querySelectorAll(\"[selected]\").length ) {\n" \
"				rbuggyQSA.push( \"\\\\[\" + whitespace + \"*(?:checked|disabled|ismap|multiple|readonly|selected|value)\" );\n" \
"			}\n" \
"\n" \
"			// Webkit/Opera - :checked should return selected option elements\n" \
"			// http://www.w3.org/TR/2011/REC-css3-selectors-20110929/#checked\n" \
"			// IE8 throws error here (do not put tests after this one)\n" \
"			if ( !div.querySelectorAll(\":checked\").length ) {\n" \
"				rbuggyQSA.push(\":checked\");\n" \
"			}\n" \
"		});\n" \
"\n" \
"		assert(function( div ) {\n" \
"\n" \
"			// Opera 10-12/IE9 - ^= $= *= and empty values\n" \
"			// Should not select anything\n" \
"			div.innerHTML = \"<p test=''></p>\";\n" \
"			if ( div.querySelectorAll(\"[test^='']\").length ) {\n" \
"				rbuggyQSA.push( \"[*^$]=\" + whitespace + \"*(?:\\\"\\\"|'')\" );\n" \
"			}\n" \
"\n" \
"			// FF 3.5 - :enabled/:disabled and hidden elements (hidden elements are still enabled)\n" \
"			// IE8 throws error here (do not put tests after this one)\n" \
"			div.innerHTML = \"<input type='hidden'/>\";\n" \
"			if ( !div.querySelectorAll(\":enabled\").length ) {\n" \
"				rbuggyQSA.push(\":enabled\", \":disabled\");\n" \
"			}\n" \
"		});\n" \
"\n" \
"		// rbuggyQSA always contains :focus, so no need for a length check\n" \
"		rbuggyQSA = /* rbuggyQSA.length && */ new RegExp( rbuggyQSA.join(\"|\") );\n" \
"\n" \
"		select = function( selector, context, results, seed, xml ) {\n" \
"			// Only use querySelectorAll when not filtering,\n" \
"			// when this is not xml,\n" \
"			// and when no QSA bugs apply\n" \
"			if ( !seed && !xml && !rbuggyQSA.test( selector ) ) {\n" \
"				var groups, i,\n" \
"					old = true,\n" \
"					nid = expando,\n" \
"					newContext = context,\n" \
"					newSelector = context.nodeType === 9 && selector;\n" \
"\n" \
"				// qSA works strangely on Element-rooted queries\n" \
"				// We can work around this by specifying an extra ID on the root\n" \
"				// and working up from there (Thanks to Andrew Dupont for the technique)\n" \
"				// IE 8 doesn't work on object elements\n" \
"				if ( context.nodeType === 1 && context.nodeName.toLowerCase() !== \"object\" ) {\n" \
"					groups = tokenize( selector );\n" \
"\n" \
"					if ( (old = context.getAttribute(\"id\")) ) {\n" \
"						nid = old.replace( rescape, \"\\\\$&\" );\n" \
"					} else {\n" \
"						context.setAttribute( \"id\", nid );\n" \
"					}\n" \
"					nid = \"[id='\" + nid + \"'] \";\n" \
"\n" \
"					i = groups.length;\n" \
"					while ( i-- ) {\n" \
"						groups[i] = nid + groups[i].join(\"\");\n" \
"					}\n" \
"					newContext = rsibling.test( selector ) && context.parentNode || context;\n" \
"					newSelector = groups.join(\",\");\n" \
"				}\n" \
"\n" \
"				if ( newSelector ) {\n" \
"					try {\n" \
"						push.apply( results, slice.call( newContext.querySelectorAll(\n" \
"							newSelector\n" \
"						), 0 ) );\n" \
"						return results;\n" \
"					} catch(qsaError) {\n" \
"					} finally {\n" \
"						if ( !old ) {\n" \
"							context.removeAttribute(\"id\");\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			return oldSelect( selector, context, results, seed, xml );\n" \
"		};\n" \
"\n" \
"		if ( matches ) {\n" \
"			assert(function( div ) {\n" \
"				// Check to see if it's possible to do matchesSelector\n" \
"				// on a disconnected node (IE 9)\n" \
"				disconnectedMatch = matches.call( div, \"div\" );\n" \
"\n" \
"				// This should fail with an exception\n" \
"				// Gecko does not error, returns false instead\n" \
"				try {\n" \
"					matches.call( div, \"[test!='']:sizzle\" );\n" \
"					rbuggyMatches.push( \"!=\", pseudos );\n" \
"				} catch ( e ) {}\n" \
"			});\n" \
"\n" \
"			// rbuggyMatches always contains :active and :focus, so no need for a length check\n" \
"			rbuggyMatches = /* rbuggyMatches.length && */ new RegExp( rbuggyMatches.join(\"|\") );\n" \
"\n" \
"			Sizzle.matchesSelector = function( elem, expr ) {\n" \
"				// Make sure that attribute selectors are quoted\n" \
"				expr = expr.replace( rattributeQuotes, \"='$1']\" );\n" \
"\n" \
"				// rbuggyMatches always contains :active, so no need for an existence check\n" \
"				if ( !isXML( elem ) && !rbuggyMatches.test( expr ) && !rbuggyQSA.test( expr ) ) {\n" \
"					try {\n" \
"						var ret = matches.call( elem, expr );\n" \
"\n" \
"						// IE 9's matchesSelector returns false on disconnected nodes\n" \
"						if ( ret || disconnectedMatch ||\n" \
"								// As well, disconnected nodes are said to be in a document\n" \
"								// fragment in IE 9\n" \
"								elem.document && elem.document.nodeType !== 11 ) {\n" \
"							return ret;\n" \
"						}\n" \
"					} catch(e) {}\n" \
"				}\n" \
"\n" \
"				return Sizzle( expr, null, null, [ elem ] ).length > 0;\n" \
"			};\n" \
"		}\n" \
"	})();\n" \
"}\n" \
"\n" \
"// Deprecated\n" \
"Expr.pseudos[\"nth\"] = Expr.pseudos[\"eq\"];\n" \
"\n" \
"// Back-compat\n" \
"function setFilters() {}\n" \
"Expr.filters = setFilters.prototype = Expr.pseudos;\n" \
"Expr.setFilters = new setFilters();\n" \
"\n" \
"// Override sizzle attribute retrieval\n" \
"Sizzle.attr = jQuery.attr;\n" \
"jQuery.find = Sizzle;\n" \
"jQuery.expr = Sizzle.selectors;\n" \
"jQuery.expr[\":\"] = jQuery.expr.pseudos;\n" \
"jQuery.unique = Sizzle.uniqueSort;\n" \
"jQuery.text = Sizzle.getText;\n" \
"jQuery.isXMLDoc = Sizzle.isXML;\n" \
"jQuery.contains = Sizzle.contains;\n" \
"\n" \
"\n" \
"})( window );\n" \
"var runtil = /Until$/,\n" \
"	rparentsprev = /^(?:parents|prev(?:Until|All))/,\n" \
"	isSimple = /^.[^:#\\[\\.,]*$/,\n" \
"	rneedsContext = jQuery.expr.match.needsContext,\n" \
"	// methods guaranteed to produce a unique set when starting from a unique set\n" \
"	guaranteedUnique = {\n" \
"		children: true,\n" \
"		contents: true,\n" \
"		next: true,\n" \
"		prev: true\n" \
"	};\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	find: function( selector ) {\n" \
"		var i, l, length, n, r, ret,\n" \
"			self = this;\n" \
"\n" \
"		if ( typeof selector !== \"string\" ) {\n" \
"			return jQuery( selector ).filter(function() {\n" \
"				for ( i = 0, l = self.length; i < l; i++ ) {\n" \
"					if ( jQuery.contains( self[ i ], this ) ) {\n" \
"						return true;\n" \
"					}\n" \
"				}\n" \
"			});\n" \
"		}\n" \
"\n" \
"		ret = this.pushStack( \"\", \"find\", selector );\n" \
"\n" \
"		for ( i = 0, l = this.length; i < l; i++ ) {\n" \
"			length = ret.length;\n" \
"			jQuery.find( selector, this[i], ret );\n" \
"\n" \
"			if ( i > 0 ) {\n" \
"				// Make sure that the results are unique\n" \
"				for ( n = length; n < ret.length; n++ ) {\n" \
"					for ( r = 0; r < length; r++ ) {\n" \
"						if ( ret[r] === ret[n] ) {\n" \
"							ret.splice(n--, 1);\n" \
"							break;\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	has: function( target ) {\n" \
"		var i,\n" \
"			targets = jQuery( target, this ),\n" \
"			len = targets.length;\n" \
"\n" \
"		return this.filter(function() {\n" \
"			for ( i = 0; i < len; i++ ) {\n" \
"				if ( jQuery.contains( this, targets[i] ) ) {\n" \
"					return true;\n" \
"				}\n" \
"			}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	not: function( selector ) {\n" \
"		return this.pushStack( winnow(this, selector, false), \"not\", selector);\n" \
"	},\n" \
"\n" \
"	filter: function( selector ) {\n" \
"		return this.pushStack( winnow(this, selector, true), \"filter\", selector );\n" \
"	},\n" \
"\n" \
"	is: function( selector ) {\n" \
"		return !!selector && (\n" \
"			typeof selector === \"string\" ?\n" \
"				// If this is a positional/relative selector, check membership in the returned set\n" \
"				// so $(\"p:first\").is(\"p:last\") won't return true for a doc with two \"p\".\n" \
"				rneedsContext.test( selector ) ?\n" \
"					jQuery( selector, this.context ).index( this[0] ) >= 0 :\n" \
"					jQuery.filter( selector, this ).length > 0 :\n" \
"				this.filter( selector ).length > 0 );\n" \
"	},\n" \
"\n" \
"	closest: function( selectors, context ) {\n" \
"		var cur,\n" \
"			i = 0,\n" \
"			l = this.length,\n" \
"			ret = [],\n" \
"			pos = rneedsContext.test( selectors ) || typeof selectors !== \"string\" ?\n" \
"				jQuery( selectors, context || this.context ) :\n" \
"				0;\n" \
"\n" \
"		for ( ; i < l; i++ ) {\n" \
"			cur = this[i];\n" \
"\n" \
"			while ( cur && cur.ownerDocument && cur !== context && cur.nodeType !== 11 ) {\n" \
"				if ( pos ? pos.index(cur) > -1 : jQuery.find.matchesSelector(cur, selectors) ) {\n" \
"					ret.push( cur );\n" \
"					break;\n" \
"				}\n" \
"				cur = cur.parentNode;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		ret = ret.length > 1 ? jQuery.unique( ret ) : ret;\n" \
"\n" \
"		return this.pushStack( ret, \"closest\", selectors );\n" \
"	},\n" \
"\n" \
"	// Determine the position of an element within\n" \
"	// the matched set of elements\n" \
"	index: function( elem ) {\n" \
"\n" \
"		// No argument, return index in parent\n" \
"		if ( !elem ) {\n" \
"			return ( this[0] && this[0].parentNode ) ? this.prevAll().length : -1;\n" \
"		}\n" \
"\n" \
"		// index in selector\n" \
"		if ( typeof elem === \"string\" ) {\n" \
"			return jQuery.inArray( this[0], jQuery( elem ) );\n" \
"		}\n" \
"\n" \
"		// Locate the position of the desired element\n" \
"		return jQuery.inArray(\n" \
"			// If it receives a jQuery object, the first element is used\n" \
"			elem.jquery ? elem[0] : elem, this );\n" \
"	},\n" \
"\n" \
"	add: function( selector, context ) {\n" \
"		var set = typeof selector === \"string\" ?\n" \
"				jQuery( selector, context ) :\n" \
"				jQuery.makeArray( selector && selector.nodeType ? [ selector ] : selector ),\n" \
"			all = jQuery.merge( this.get(), set );\n" \
"\n" \
"		return this.pushStack( isDisconnected( set[0] ) || isDisconnected( all[0] ) ?\n" \
"			all :\n" \
"			jQuery.unique( all ) );\n" \
"	},\n" \
"\n" \
"	addBack: function( selector ) {\n" \
"		return this.add( selector == null ?\n" \
"			this.prevObject : this.prevObject.filter(selector)\n" \
"		);\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.fn.andSelf = jQuery.fn.addBack;\n" \
"\n" \
"// A painfully simple check to see if an element is disconnected\n" \
"// from a document (should be improved, where feasible).\n" \
"function isDisconnected( node ) {\n" \
"	return !node || !node.parentNode || node.parentNode.nodeType === 11;\n" \
"}\n" \
"\n" \
"function sibling( cur, dir ) {\n" \
"	do {\n" \
"		cur = cur[ dir ];\n" \
"	} while ( cur && cur.nodeType !== 1 );\n" \
"\n" \
"	return cur;\n" \
"}\n" \
"\n" \
"jQuery.each({\n" \
"	parent: function( elem ) {\n" \
"		var parent = elem.parentNode;\n" \
"		return parent && parent.nodeType !== 11 ? parent : null;\n" \
"	},\n" \
"	parents: function( elem ) {\n" \
"		return jQuery.dir( elem, \"parentNode\" );\n" \
"	},\n" \
"	parentsUntil: function( elem, i, until ) {\n" \
"		return jQuery.dir( elem, \"parentNode\", until );\n" \
"	},\n" \
"	next: function( elem ) {\n" \
"		return sibling( elem, \"nextSibling\" );\n" \
"	},\n" \
"	prev: function( elem ) {\n" \
"		return sibling( elem, \"previousSibling\" );\n" \
"	},\n" \
"	nextAll: function( elem ) {\n" \
"		return jQuery.dir( elem, \"nextSibling\" );\n" \
"	},\n" \
"	prevAll: function( elem ) {\n" \
"		return jQuery.dir( elem, \"previousSibling\" );\n" \
"	},\n" \
"	nextUntil: function( elem, i, until ) {\n" \
"		return jQuery.dir( elem, \"nextSibling\", until );\n" \
"	},\n" \
"	prevUntil: function( elem, i, until ) {\n" \
"		return jQuery.dir( elem, \"previousSibling\", until );\n" \
"	},\n" \
"	siblings: function( elem ) {\n" \
"		return jQuery.sibling( ( elem.parentNode || {} ).firstChild, elem );\n" \
"	},\n" \
"	children: function( elem ) {\n" \
"		return jQuery.sibling( elem.firstChild );\n" \
"	},\n" \
"	contents: function( elem ) {\n" \
"		return jQuery.nodeName( elem, \"iframe\" ) ?\n" \
"			elem.contentDocument || elem.contentWindow.document :\n" \
"			jQuery.merge( [], elem.childNodes );\n" \
"	}\n" \
"}, function( name, fn ) {\n" \
"	jQuery.fn[ name ] = function( until, selector ) {\n" \
"		var ret = jQuery.map( this, fn, until );\n" \
"\n" \
"		if ( !runtil.test( name ) ) {\n" \
"			selector = until;\n" \
"		}\n" \
"\n" \
"		if ( selector && typeof selector === \"string\" ) {\n" \
"			ret = jQuery.filter( selector, ret );\n" \
"		}\n" \
"\n" \
"		ret = this.length > 1 && !guaranteedUnique[ name ] ? jQuery.unique( ret ) : ret;\n" \
"\n" \
"		if ( this.length > 1 && rparentsprev.test( name ) ) {\n" \
"			ret = ret.reverse();\n" \
"		}\n" \
"\n" \
"		return this.pushStack( ret, name, core_slice.call( arguments ).join(\",\") );\n" \
"	};\n" \
"});\n" \
"\n" \
"jQuery.extend({\n" \
"	filter: function( expr, elems, not ) {\n" \
"		if ( not ) {\n" \
"			expr = \":not(\" + expr + \")\";\n" \
"		}\n" \
"\n" \
"		return elems.length === 1 ?\n" \
"			jQuery.find.matchesSelector(elems[0], expr) ? [ elems[0] ] : [] :\n" \
"			jQuery.find.matches(expr, elems);\n" \
"	},\n" \
"\n" \
"	dir: function( elem, dir, until ) {\n" \
"		var matched = [],\n" \
"			cur = elem[ dir ];\n" \
"\n" \
"		while ( cur && cur.nodeType !== 9 && (until === undefined || cur.nodeType !== 1 || !jQuery( cur ).is( until )) ) {\n" \
"			if ( cur.nodeType === 1 ) {\n" \
"				matched.push( cur );\n" \
"			}\n" \
"			cur = cur[dir];\n" \
"		}\n" \
"		return matched;\n" \
"	},\n" \
"\n" \
"	sibling: function( n, elem ) {\n" \
"		var r = [];\n" \
"\n" \
"		for ( ; n; n = n.nextSibling ) {\n" \
"			if ( n.nodeType === 1 && n !== elem ) {\n" \
"				r.push( n );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return r;\n" \
"	}\n" \
"});\n" \
"\n" \
"// Implement the identical functionality for filter and not\n" \
"function winnow( elements, qualifier, keep ) {\n" \
"\n" \
"	// Can't pass null or undefined to indexOf in Firefox 4\n" \
"	// Set to 0 to skip string check\n" \
"	qualifier = qualifier || 0;\n" \
"\n" \
"	if ( jQuery.isFunction( qualifier ) ) {\n" \
"		return jQuery.grep(elements, function( elem, i ) {\n" \
"			var retVal = !!qualifier.call( elem, i, elem );\n" \
"			return retVal === keep;\n" \
"		});\n" \
"\n" \
"	} else if ( qualifier.nodeType ) {\n" \
"		return jQuery.grep(elements, function( elem, i ) {\n" \
"			return ( elem === qualifier ) === keep;\n" \
"		});\n" \
"\n" \
"	} else if ( typeof qualifier === \"string\" ) {\n" \
"		var filtered = jQuery.grep(elements, function( elem ) {\n" \
"			return elem.nodeType === 1;\n" \
"		});\n" \
"\n" \
"		if ( isSimple.test( qualifier ) ) {\n" \
"			return jQuery.filter(qualifier, filtered, !keep);\n" \
"		} else {\n" \
"			qualifier = jQuery.filter( qualifier, filtered );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return jQuery.grep(elements, function( elem, i ) {\n" \
"		return ( jQuery.inArray( elem, qualifier ) >= 0 ) === keep;\n" \
"	});\n" \
"}\n" \
"function createSafeFragment( document ) {\n" \
"	var list = nodeNames.split( \"|\" ),\n" \
"	safeFrag = document.createDocumentFragment();\n" \
"\n" \
"	if ( safeFrag.createElement ) {\n" \
"		while ( list.length ) {\n" \
"			safeFrag.createElement(\n" \
"				list.pop()\n" \
"			);\n" \
"		}\n" \
"	}\n" \
"	return safeFrag;\n" \
"}\n" \
"\n" \
"var nodeNames = \"abbr|article|aside|audio|bdi|canvas|data|datalist|details|figcaption|figure|footer|\" +\n" \
"		\"header|hgroup|mark|meter|nav|output|progress|section|summary|time|video\",\n" \
"	rinlinejQuery = / jQuery\\d+=\"(?:null|\\d+)\"/g,\n" \
"	rleadingWhitespace = /^\\s+/,\n" \
"	rxhtmlTag = /<(?!area|br|col|embed|hr|img|input|link|meta|param)(([\\w:]+)[^>]*)\\/>/gi,\n" \
"	rtagName = /<([\\w:]+)/,\n" \
"	rtbody = /<tbody/i,\n" \
"	rhtml = /<|&#?\\w+;/,\n" \
"	rnoInnerhtml = /<(?:script|style|link)/i,\n" \
"	rnocache = /<(?:script|object|embed|option|style)/i,\n" \
"	rnoshimcache = new RegExp(\"<(?:\" + nodeNames + \")[\\\\s/>]\", \"i\"),\n" \
"	rcheckableType = /^(?:checkbox|radio)$/,\n" \
"	// checked=\"checked\" or checked\n" \
"	rchecked = /checked\\s*(?:[^=]|=\\s*.checked.)/i,\n" \
"	rscriptType = /\\/(java|ecma)script/i,\n" \
"	rcleanScript = /^\\s*<!(?:\\[CDATA\\[|\\-\\-)|[\\]\\-]{2}>\\s*$/g,\n" \
"	wrapMap = {\n" \
"		option: [ 1, \"<select multiple='multiple'>\", \"</select>\" ],\n" \
"		legend: [ 1, \"<fieldset>\", \"</fieldset>\" ],\n" \
"		thead: [ 1, \"<table>\", \"</table>\" ],\n" \
"		tr: [ 2, \"<table><tbody>\", \"</tbody></table>\" ],\n" \
"		td: [ 3, \"<table><tbody><tr>\", \"</tr></tbody></table>\" ],\n" \
"		col: [ 2, \"<table><tbody></tbody><colgroup>\", \"</colgroup></table>\" ],\n" \
"		area: [ 1, \"<map>\", \"</map>\" ],\n" \
"		_default: [ 0, \"\", \"\" ]\n" \
"	},\n" \
"	safeFragment = createSafeFragment( document ),\n" \
"	fragmentDiv = safeFragment.appendChild( document.createElement(\"div\") );\n" \
"\n" \
"wrapMap.optgroup = wrapMap.option;\n" \
"wrapMap.tbody = wrapMap.tfoot = wrapMap.colgroup = wrapMap.caption = wrapMap.thead;\n" \
"wrapMap.th = wrapMap.td;\n" \
"\n" \
"// IE6-8 can't serialize link, script, style, or any html5 (NoScope) tags,\n" \
"// unless wrapped in a div with non-breaking characters in front of it.\n" \
"if ( !jQuery.support.htmlSerialize ) {\n" \
"	wrapMap._default = [ 1, \"X<div>\", \"</div>\" ];\n" \
"}\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	text: function( value ) {\n" \
"		return jQuery.access( this, function( value ) {\n" \
"			return value === undefined ?\n" \
"				jQuery.text( this ) :\n" \
"				this.empty().append( ( this[0] && this[0].ownerDocument || document ).createTextNode( value ) );\n" \
"		}, null, value, arguments.length );\n" \
"	},\n" \
"\n" \
"	wrapAll: function( html ) {\n" \
"		if ( jQuery.isFunction( html ) ) {\n" \
"			return this.each(function(i) {\n" \
"				jQuery(this).wrapAll( html.call(this, i) );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( this[0] ) {\n" \
"			// The elements to wrap the target around\n" \
"			var wrap = jQuery( html, this[0].ownerDocument ).eq(0).clone(true);\n" \
"\n" \
"			if ( this[0].parentNode ) {\n" \
"				wrap.insertBefore( this[0] );\n" \
"			}\n" \
"\n" \
"			wrap.map(function() {\n" \
"				var elem = this;\n" \
"\n" \
"				while ( elem.firstChild && elem.firstChild.nodeType === 1 ) {\n" \
"					elem = elem.firstChild;\n" \
"				}\n" \
"\n" \
"				return elem;\n" \
"			}).append( this );\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	wrapInner: function( html ) {\n" \
"		if ( jQuery.isFunction( html ) ) {\n" \
"			return this.each(function(i) {\n" \
"				jQuery(this).wrapInner( html.call(this, i) );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		return this.each(function() {\n" \
"			var self = jQuery( this ),\n" \
"				contents = self.contents();\n" \
"\n" \
"			if ( contents.length ) {\n" \
"				contents.wrapAll( html );\n" \
"\n" \
"			} else {\n" \
"				self.append( html );\n" \
"			}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	wrap: function( html ) {\n" \
"		var isFunction = jQuery.isFunction( html );\n" \
"\n" \
"		return this.each(function(i) {\n" \
"			jQuery( this ).wrapAll( isFunction ? html.call(this, i) : html );\n" \
"		});\n" \
"	},\n" \
"\n" \
"	unwrap: function() {\n" \
"		return this.parent().each(function() {\n" \
"			if ( !jQuery.nodeName( this, \"body\" ) ) {\n" \
"				jQuery( this ).replaceWith( this.childNodes );\n" \
"			}\n" \
"		}).end();\n" \
"	},\n" \
"\n" \
"	append: function() {\n" \
"		return this.domManip(arguments, true, function( elem ) {\n" \
"			if ( this.nodeType === 1 || this.nodeType === 11 ) {\n" \
"				this.appendChild( elem );\n" \
"			}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	prepend: function() {\n" \
"		return this.domManip(arguments, true, function( elem ) {\n" \
"			if ( this.nodeType === 1 || this.nodeType === 11 ) {\n" \
"				this.insertBefore( elem, this.firstChild );\n" \
"			}\n" \
"		});\n" \
"	},\n" \
"\n" \
"	before: function() {\n" \
"		if ( !isDisconnected( this[0] ) ) {\n" \
"			return this.domManip(arguments, false, function( elem ) {\n" \
"				this.parentNode.insertBefore( elem, this );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( arguments.length ) {\n" \
"			var set = jQuery.clean( arguments );\n" \
"			return this.pushStack( jQuery.merge( set, this ), \"before\", this.selector );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	after: function() {\n" \
"		if ( !isDisconnected( this[0] ) ) {\n" \
"			return this.domManip(arguments, false, function( elem ) {\n" \
"				this.parentNode.insertBefore( elem, this.nextSibling );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( arguments.length ) {\n" \
"			var set = jQuery.clean( arguments );\n" \
"			return this.pushStack( jQuery.merge( this, set ), \"after\", this.selector );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// keepData is for internal use only--do not document\n" \
"	remove: function( selector, keepData ) {\n" \
"		var elem,\n" \
"			i = 0;\n" \
"\n" \
"		for ( ; (elem = this[i]) != null; i++ ) {\n" \
"			if ( !selector || jQuery.filter( selector, [ elem ] ).length ) {\n" \
"				if ( !keepData && elem.nodeType === 1 ) {\n" \
"					jQuery.cleanData( elem.getElementsByTagName(\"*\") );\n" \
"					jQuery.cleanData( [ elem ] );\n" \
"				}\n" \
"\n" \
"				if ( elem.parentNode ) {\n" \
"					elem.parentNode.removeChild( elem );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	empty: function() {\n" \
"		var elem,\n" \
"			i = 0;\n" \
"\n" \
"		for ( ; (elem = this[i]) != null; i++ ) {\n" \
"			// Remove element nodes and prevent memory leaks\n" \
"			if ( elem.nodeType === 1 ) {\n" \
"				jQuery.cleanData( elem.getElementsByTagName(\"*\") );\n" \
"			}\n" \
"\n" \
"			// Remove any remaining nodes\n" \
"			while ( elem.firstChild ) {\n" \
"				elem.removeChild( elem.firstChild );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	},\n" \
"\n" \
"	clone: function( dataAndEvents, deepDataAndEvents ) {\n" \
"		dataAndEvents = dataAndEvents == null ? false : dataAndEvents;\n" \
"		deepDataAndEvents = deepDataAndEvents == null ? dataAndEvents : deepDataAndEvents;\n" \
"\n" \
"		return this.map( function () {\n" \
"			return jQuery.clone( this, dataAndEvents, deepDataAndEvents );\n" \
"		});\n" \
"	},\n" \
"\n" \
"	html: function( value ) {\n" \
"		return jQuery.access( this, function( value ) {\n" \
"			var elem = this[0] || {},\n" \
"				i = 0,\n" \
"				l = this.length;\n" \
"\n" \
"			if ( value === undefined ) {\n" \
"				return elem.nodeType === 1 ?\n" \
"					elem.innerHTML.replace( rinlinejQuery, \"\" ) :\n" \
"					undefined;\n" \
"			}\n" \
"\n" \
"			// See if we can take a shortcut and just use innerHTML\n" \
"			if ( typeof value === \"string\" && !rnoInnerhtml.test( value ) &&\n" \
"				( jQuery.support.htmlSerialize || !rnoshimcache.test( value )  ) &&\n" \
"				( jQuery.support.leadingWhitespace || !rleadingWhitespace.test( value ) ) &&\n" \
"				!wrapMap[ ( rtagName.exec( value ) || [\"\", \"\"] )[1].toLowerCase() ] ) {\n" \
"\n" \
"				value = value.replace( rxhtmlTag, \"<$1></$2>\" );\n" \
"\n" \
"				try {\n" \
"					for (; i < l; i++ ) {\n" \
"						// Remove element nodes and prevent memory leaks\n" \
"						elem = this[i] || {};\n" \
"						if ( elem.nodeType === 1 ) {\n" \
"							jQuery.cleanData( elem.getElementsByTagName( \"*\" ) );\n" \
"							elem.innerHTML = value;\n" \
"						}\n" \
"					}\n" \
"\n" \
"					elem = 0;\n" \
"\n" \
"				// If using innerHTML throws an exception, use the fallback method\n" \
"				} catch(e) {}\n" \
"			}\n" \
"\n" \
"			if ( elem ) {\n" \
"				this.empty().append( value );\n" \
"			}\n" \
"		}, null, value, arguments.length );\n" \
"	},\n" \
"\n" \
"	replaceWith: function( value ) {\n" \
"		if ( !isDisconnected( this[0] ) ) {\n" \
"			// Make sure that the elements are removed from the DOM before they are inserted\n" \
"			// this can help fix replacing a parent with child elements\n" \
"			if ( jQuery.isFunction( value ) ) {\n" \
"				return this.each(function(i) {\n" \
"					var self = jQuery(this), old = self.html();\n" \
"					self.replaceWith( value.call( this, i, old ) );\n" \
"				});\n" \
"			}\n" \
"\n" \
"			if ( typeof value !== \"string\" ) {\n" \
"				value = jQuery( value ).detach();\n" \
"			}\n" \
"\n" \
"			return this.each(function() {\n" \
"				var next = this.nextSibling,\n" \
"					parent = this.parentNode;\n" \
"\n" \
"				jQuery( this ).remove();\n" \
"\n" \
"				if ( next ) {\n" \
"					jQuery(next).before( value );\n" \
"				} else {\n" \
"					jQuery(parent).append( value );\n" \
"				}\n" \
"			});\n" \
"		}\n" \
"\n" \
"		return this.length ?\n" \
"			this.pushStack( jQuery(jQuery.isFunction(value) ? value() : value), \"replaceWith\", value ) :\n" \
"			this;\n" \
"	},\n" \
"\n" \
"	detach: function( selector ) {\n" \
"		return this.remove( selector, true );\n" \
"	},\n" \
"\n" \
"	domManip: function( args, table, callback ) {\n" \
"\n" \
"		// Flatten any nested arrays\n" \
"		args = [].concat.apply( [], args );\n" \
"\n" \
"		var results, first, fragment, iNoClone,\n" \
"			i = 0,\n" \
"			value = args[0],\n" \
"			scripts = [],\n" \
"			l = this.length;\n" \
"\n" \
"		// We can't cloneNode fragments that contain checked, in WebKit\n" \
"		if ( !jQuery.support.checkClone && l > 1 && typeof value === \"string\" && rchecked.test( value ) ) {\n" \
"			return this.each(function() {\n" \
"				jQuery(this).domManip( args, table, callback );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( jQuery.isFunction(value) ) {\n" \
"			return this.each(function(i) {\n" \
"				var self = jQuery(this);\n" \
"				args[0] = value.call( this, i, table ? self.html() : undefined );\n" \
"				self.domManip( args, table, callback );\n" \
"			});\n" \
"		}\n" \
"\n" \
"		if ( this[0] ) {\n" \
"			results = jQuery.buildFragment( args, this, scripts );\n" \
"			fragment = results.fragment;\n" \
"			first = fragment.firstChild;\n" \
"\n" \
"			if ( fragment.childNodes.length === 1 ) {\n" \
"				fragment = first;\n" \
"			}\n" \
"\n" \
"			if ( first ) {\n" \
"				table = table && jQuery.nodeName( first, \"tr\" );\n" \
"\n" \
"				// Use the original fragment for the last item instead of the first because it can end up\n" \
"				// being emptied incorrectly in certain situations (#8070).\n" \
"				// Fragments from the fragment cache must always be cloned and never used in place.\n" \
"				for ( iNoClone = results.cacheable || l - 1; i < l; i++ ) {\n" \
"					callback.call(\n" \
"						table && jQuery.nodeName( this[i], \"table\" ) ?\n" \
"							findOrAppend( this[i], \"tbody\" ) :\n" \
"							this[i],\n" \
"						i === iNoClone ?\n" \
"							fragment :\n" \
"							jQuery.clone( fragment, true, true )\n" \
"					);\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Fix #11809: Avoid leaking memory\n" \
"			fragment = first = null;\n" \
"\n" \
"			if ( scripts.length ) {\n" \
"				jQuery.each( scripts, function( i, elem ) {\n" \
"					if ( elem.src ) {\n" \
"						if ( jQuery.ajax ) {\n" \
"							jQuery.ajax({\n" \
"								url: elem.src,\n" \
"								type: \"GET\",\n" \
"								dataType: \"script\",\n" \
"								async: false,\n" \
"								global: false,\n" \
"								\"throws\": true\n" \
"							});\n" \
"						} else {\n" \
"							jQuery.error(\"no ajax\");\n" \
"						}\n" \
"					} else {\n" \
"						jQuery.globalEval( ( elem.text || elem.textContent || elem.innerHTML || \"\" ).replace( rcleanScript, \"\" ) );\n" \
"					}\n" \
"\n" \
"					if ( elem.parentNode ) {\n" \
"						elem.parentNode.removeChild( elem );\n" \
"					}\n" \
"				});\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return this;\n" \
"	}\n" \
"});\n" \
"\n" \
"function findOrAppend( elem, tag ) {\n" \
"	return elem.getElementsByTagName( tag )[0] || elem.appendChild( elem.ownerDocument.createElement( tag ) );\n" \
"}\n" \
"\n" \
"function cloneCopyEvent( src, dest ) {\n" \
"\n" \
"	if ( dest.nodeType !== 1 || !jQuery.hasData( src ) ) {\n" \
"		return;\n" \
"	}\n" \
"\n" \
"	var type, i, l,\n" \
"		oldData = jQuery._data( src ),\n" \
"		curData = jQuery._data( dest, oldData ),\n" \
"		events = oldData.events;\n" \
"\n" \
"	if ( events ) {\n" \
"		delete curData.handle;\n" \
"		curData.events = {};\n" \
"\n" \
"		for ( type in events ) {\n" \
"			for ( i = 0, l = events[ type ].length; i < l; i++ ) {\n" \
"				jQuery.event.add( dest, type, events[ type ][ i ] );\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// make the cloned public data object a copy from the original\n" \
"	if ( curData.data ) {\n" \
"		curData.data = jQuery.extend( {}, curData.data );\n" \
"	}\n" \
"}\n" \
"\n" \
"function cloneFixAttributes( src, dest ) {\n" \
"	var nodeName;\n" \
"\n" \
"	// We do not need to do anything for non-Elements\n" \
"	if ( dest.nodeType !== 1 ) {\n" \
"		return;\n" \
"	}\n" \
"\n" \
"	// clearAttributes removes the attributes, which we don't want,\n" \
"	// but also removes the attachEvent events, which we *do* want\n" \
"	if ( dest.clearAttributes ) {\n" \
"		dest.clearAttributes();\n" \
"	}\n" \
"\n" \
"	// mergeAttributes, in contrast, only merges back on the\n" \
"	// original attributes, not the events\n" \
"	if ( dest.mergeAttributes ) {\n" \
"		dest.mergeAttributes( src );\n" \
"	}\n" \
"\n" \
"	nodeName = dest.nodeName.toLowerCase();\n" \
"\n" \
"	if ( nodeName === \"object\" ) {\n" \
"		// IE6-10 improperly clones children of object elements using classid.\n" \
"		// IE10 throws NoModificationAllowedError if parent is null, #12132.\n" \
"		if ( dest.parentNode ) {\n" \
"			dest.outerHTML = src.outerHTML;\n" \
"		}\n" \
"\n" \
"		// This path appears unavoidable for IE9. When cloning an object\n" \
"		// element in IE9, the outerHTML strategy above is not sufficient.\n" \
"		// If the src has innerHTML and the destination does not,\n" \
"		// copy the src.innerHTML into the dest.innerHTML. #10324\n" \
"		if ( jQuery.support.html5Clone && (src.innerHTML && !jQuery.trim(dest.innerHTML)) ) {\n" \
"			dest.innerHTML = src.innerHTML;\n" \
"		}\n" \
"\n" \
"	} else if ( nodeName === \"input\" && rcheckableType.test( src.type ) ) {\n" \
"		// IE6-8 fails to persist the checked state of a cloned checkbox\n" \
"		// or radio button. Worse, IE6-7 fail to give the cloned element\n" \
"		// a checked appearance if the defaultChecked value isn't also set\n" \
"\n" \
"		dest.defaultChecked = dest.checked = src.checked;\n" \
"\n" \
"		// IE6-7 get confused and end up setting the value of a cloned\n" \
"		// checkbox/radio button to an empty string instead of \"on\"\n" \
"		if ( dest.value !== src.value ) {\n" \
"			dest.value = src.value;\n" \
"		}\n" \
"\n" \
"	// IE6-8 fails to return the selected option to the default selected\n" \
"	// state when cloning options\n" \
"	} else if ( nodeName === \"option\" ) {\n" \
"		dest.selected = src.defaultSelected;\n" \
"\n" \
"	// IE6-8 fails to set the defaultValue to the correct value when\n" \
"	// cloning other types of input fields\n" \
"	} else if ( nodeName === \"input\" || nodeName === \"textarea\" ) {\n" \
"		dest.defaultValue = src.defaultValue;\n" \
"\n" \
"	// IE blanks contents when cloning scripts\n" \
"	} else if ( nodeName === \"script\" && dest.text !== src.text ) {\n" \
"		dest.text = src.text;\n" \
"	}\n" \
"\n" \
"	// Event data gets referenced instead of copied if the expando\n" \
"	// gets copied too\n" \
"	dest.removeAttribute( jQuery.expando );\n" \
"}\n" \
"\n" \
"jQuery.buildFragment = function( args, context, scripts ) {\n" \
"	var fragment, cacheable, cachehit,\n" \
"		first = args[ 0 ];\n" \
"\n" \
"	// Set context from what may come in as undefined or a jQuery collection or a node\n" \
"	// Updated to fix #12266 where accessing context[0] could throw an exception in IE9/10 &\n" \
"	// also doubles as fix for #8950 where plain objects caused createDocumentFragment exception\n" \
"	context = context || document;\n" \
"	context = !context.nodeType && context[0] || context;\n" \
"	context = context.ownerDocument || context;\n" \
"\n" \
"	// Only cache \"small\" (1/2 KB) HTML strings that are associated with the main document\n" \
"	// Cloning options loses the selected state, so don't cache them\n" \
"	// IE 6 doesn't like it when you put <object> or <embed> elements in a fragment\n" \
"	// Also, WebKit does not clone 'checked' attributes on cloneNode, so don't cache\n" \
"	// Lastly, IE6,7,8 will not correctly reuse cached fragments that were created from unknown elems #10501\n" \
"	if ( args.length === 1 && typeof first === \"string\" && first.length < 512 && context === document &&\n" \
"		first.charAt(0) === \"<\" && !rnocache.test( first ) &&\n" \
"		(jQuery.support.checkClone || !rchecked.test( first )) &&\n" \
"		(jQuery.support.html5Clone || !rnoshimcache.test( first )) ) {\n" \
"\n" \
"		// Mark cacheable and look for a hit\n" \
"		cacheable = true;\n" \
"		fragment = jQuery.fragments[ first ];\n" \
"		cachehit = fragment !== undefined;\n" \
"	}\n" \
"\n" \
"	if ( !fragment ) {\n" \
"		fragment = context.createDocumentFragment();\n" \
"		jQuery.clean( args, context, fragment, scripts );\n" \
"\n" \
"		// Update the cache, but only store false\n" \
"		// unless this is a second parsing of the same content\n" \
"		if ( cacheable ) {\n" \
"			jQuery.fragments[ first ] = cachehit && fragment;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return { fragment: fragment, cacheable: cacheable };\n" \
"};\n" \
"\n" \
"jQuery.fragments = {};\n" \
"\n" \
"jQuery.each({\n" \
"	appendTo: \"append\",\n" \
"	prependTo: \"prepend\",\n" \
"	insertBefore: \"before\",\n" \
"	insertAfter: \"after\",\n" \
"	replaceAll: \"replaceWith\"\n" \
"}, function( name, original ) {\n" \
"	jQuery.fn[ name ] = function( selector ) {\n" \
"		var elems,\n" \
"			i = 0,\n" \
"			ret = [],\n" \
"			insert = jQuery( selector ),\n" \
"			l = insert.length,\n" \
"			parent = this.length === 1 && this[0].parentNode;\n" \
"\n" \
"		if ( (parent == null || parent && parent.nodeType === 11 && parent.childNodes.length === 1) && l === 1 ) {\n" \
"			insert[ original ]( this[0] );\n" \
"			return this;\n" \
"		} else {\n" \
"			for ( ; i < l; i++ ) {\n" \
"				elems = ( i > 0 ? this.clone(true) : this ).get();\n" \
"				jQuery( insert[i] )[ original ]( elems );\n" \
"				ret = ret.concat( elems );\n" \
"			}\n" \
"\n" \
"			return this.pushStack( ret, name, insert.selector );\n" \
"		}\n" \
"	};\n" \
"});\n" \
"\n" \
"function getAll( elem ) {\n" \
"	if ( typeof elem.getElementsByTagName !== \"undefined\" ) {\n" \
"		return elem.getElementsByTagName( \"*\" );\n" \
"\n" \
"	} else if ( typeof elem.querySelectorAll !== \"undefined\" ) {\n" \
"		return elem.querySelectorAll( \"*\" );\n" \
"\n" \
"	} else {\n" \
"		return [];\n" \
"	}\n" \
"}\n" \
"\n" \
"// Used in clean, fixes the defaultChecked property\n" \
"function fixDefaultChecked( elem ) {\n" \
"	if ( rcheckableType.test( elem.type ) ) {\n" \
"		elem.defaultChecked = elem.checked;\n" \
"	}\n" \
"}\n" \
"\n" \
"jQuery.extend({\n" \
"	clone: function( elem, dataAndEvents, deepDataAndEvents ) {\n" \
"		var srcElements,\n" \
"			destElements,\n" \
"			i,\n" \
"			clone;\n" \
"\n" \
"		if ( jQuery.support.html5Clone || jQuery.isXMLDoc(elem) || !rnoshimcache.test( \"<\" + elem.nodeName + \">\" ) ) {\n" \
"			clone = elem.cloneNode( true );\n" \
"\n" \
"		// IE<=8 does not properly clone detached, unknown element nodes\n" \
"		} else {\n" \
"			fragmentDiv.innerHTML = elem.outerHTML;\n" \
"			fragmentDiv.removeChild( clone = fragmentDiv.firstChild );\n" \
"		}\n" \
"\n" \
"		if ( (!jQuery.support.noCloneEvent || !jQuery.support.noCloneChecked) &&\n" \
"				(elem.nodeType === 1 || elem.nodeType === 11) && !jQuery.isXMLDoc(elem) ) {\n" \
"			// IE copies events bound via attachEvent when using cloneNode.\n" \
"			// Calling detachEvent on the clone will also remove the events\n" \
"			// from the original. In order to get around this, we use some\n" \
"			// proprietary methods to clear the events. Thanks to MooTools\n" \
"			// guys for this hotness.\n" \
"\n" \
"			cloneFixAttributes( elem, clone );\n" \
"\n" \
"			// Using Sizzle here is crazy slow, so we use getElementsByTagName instead\n" \
"			srcElements = getAll( elem );\n" \
"			destElements = getAll( clone );\n" \
"\n" \
"			// Weird iteration because IE will replace the length property\n" \
"			// with an element if you are cloning the body and one of the\n" \
"			// elements on the page has a name or id of \"length\"\n" \
"			for ( i = 0; srcElements[i]; ++i ) {\n" \
"				// Ensure that the destination node is not null; Fixes #9587\n" \
"				if ( destElements[i] ) {\n" \
"					cloneFixAttributes( srcElements[i], destElements[i] );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Copy the events from the original to the clone\n" \
"		if ( dataAndEvents ) {\n" \
"			cloneCopyEvent( elem, clone );\n" \
"\n" \
"			if ( deepDataAndEvents ) {\n" \
"				srcElements = getAll( elem );\n" \
"				destElements = getAll( clone );\n" \
"\n" \
"				for ( i = 0; srcElements[i]; ++i ) {\n" \
"					cloneCopyEvent( srcElements[i], destElements[i] );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		srcElements = destElements = null;\n" \
"\n" \
"		// Return the cloned set\n" \
"		return clone;\n" \
"	},\n" \
"\n" \
"	clean: function( elems, context, fragment, scripts ) {\n" \
"		var i, j, elem, tag, wrap, depth, div, hasBody, tbody, len, handleScript, jsTags,\n" \
"			safe = context === document && safeFragment,\n" \
"			ret = [];\n" \
"\n" \
"		// Ensure that context is a document\n" \
"		if ( !context || typeof context.createDocumentFragment === \"undefined\" ) {\n" \
"			context = document;\n" \
"		}\n" \
"\n" \
"		// Use the already-created safe fragment if context permits\n" \
"		for ( i = 0; (elem = elems[i]) != null; i++ ) {\n" \
"			if ( typeof elem === \"number\" ) {\n" \
"				elem += \"\";\n" \
"			}\n" \
"\n" \
"			if ( !elem ) {\n" \
"				continue;\n" \
"			}\n" \
"\n" \
"			// Convert html string into DOM nodes\n" \
"			if ( typeof elem === \"string\" ) {\n" \
"				if ( !rhtml.test( elem ) ) {\n" \
"					elem = context.createTextNode( elem );\n" \
"				} else {\n" \
"					// Ensure a safe container in which to render the html\n" \
"					safe = safe || createSafeFragment( context );\n" \
"					div = context.createElement(\"div\");\n" \
"					safe.appendChild( div );\n" \
"\n" \
"					// Fix \"XHTML\"-style tags in all browsers\n" \
"					elem = elem.replace(rxhtmlTag, \"<$1></$2>\");\n" \
"\n" \
"					// Go to html and back, then peel off extra wrappers\n" \
"					tag = ( rtagName.exec( elem ) || [\"\", \"\"] )[1].toLowerCase();\n" \
"					wrap = wrapMap[ tag ] || wrapMap._default;\n" \
"					depth = wrap[0];\n" \
"					div.innerHTML = wrap[1] + elem + wrap[2];\n" \
"\n" \
"					// Move to the right depth\n" \
"					while ( depth-- ) {\n" \
"						div = div.lastChild;\n" \
"					}\n" \
"\n" \
"					// Remove IE's autoinserted <tbody> from table fragments\n" \
"					if ( !jQuery.support.tbody ) {\n" \
"\n" \
"						// String was a <table>, *may* have spurious <tbody>\n" \
"						hasBody = rtbody.test(elem);\n" \
"							tbody = tag === \"table\" && !hasBody ?\n" \
"								div.firstChild && div.firstChild.childNodes :\n" \
"\n" \
"								// String was a bare <thead> or <tfoot>\n" \
"								wrap[1] === \"<table>\" && !hasBody ?\n" \
"									div.childNodes :\n" \
"									[];\n" \
"\n" \
"						for ( j = tbody.length - 1; j >= 0 ; --j ) {\n" \
"							if ( jQuery.nodeName( tbody[ j ], \"tbody\" ) && !tbody[ j ].childNodes.length ) {\n" \
"								tbody[ j ].parentNode.removeChild( tbody[ j ] );\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"\n" \
"					// IE completely kills leading whitespace when innerHTML is used\n" \
"					if ( !jQuery.support.leadingWhitespace && rleadingWhitespace.test( elem ) ) {\n" \
"						div.insertBefore( context.createTextNode( rleadingWhitespace.exec(elem)[0] ), div.firstChild );\n" \
"					}\n" \
"\n" \
"					elem = div.childNodes;\n" \
"\n" \
"					// Take out of fragment container (we need a fresh div each time)\n" \
"					div.parentNode.removeChild( div );\n" \
"				}\n" \
"			}\n" \
"\n" \
"			if ( elem.nodeType ) {\n" \
"				ret.push( elem );\n" \
"			} else {\n" \
"				jQuery.merge( ret, elem );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Fix #11356: Clear elements from safeFragment\n" \
"		if ( div ) {\n" \
"			elem = div = safe = null;\n" \
"		}\n" \
"\n" \
"		// Reset defaultChecked for any radios and checkboxes\n" \
"		// about to be appended to the DOM in IE 6/7 (#8060)\n" \
"		if ( !jQuery.support.appendChecked ) {\n" \
"			for ( i = 0; (elem = ret[i]) != null; i++ ) {\n" \
"				if ( jQuery.nodeName( elem, \"input\" ) ) {\n" \
"					fixDefaultChecked( elem );\n" \
"				} else if ( typeof elem.getElementsByTagName !== \"undefined\" ) {\n" \
"					jQuery.grep( elem.getElementsByTagName(\"input\"), fixDefaultChecked );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Append elements to a provided document fragment\n" \
"		if ( fragment ) {\n" \
"			// Special handling of each script element\n" \
"			handleScript = function( elem ) {\n" \
"				// Check if we consider it executable\n" \
"				if ( !elem.type || rscriptType.test( elem.type ) ) {\n" \
"					// Detach the script and store it in the scripts array (if provided) or the fragment\n" \
"					// Return truthy to indicate that it has been handled\n" \
"					return scripts ?\n" \
"						scripts.push( elem.parentNode ? elem.parentNode.removeChild( elem ) : elem ) :\n" \
"						fragment.appendChild( elem );\n" \
"				}\n" \
"			};\n" \
"\n" \
"			for ( i = 0; (elem = ret[i]) != null; i++ ) {\n" \
"				// Check if we're done after handling an executable script\n" \
"				if ( !( jQuery.nodeName( elem, \"script\" ) && handleScript( elem ) ) ) {\n" \
"					// Append to fragment and handle embedded scripts\n" \
"					fragment.appendChild( elem );\n" \
"					if ( typeof elem.getElementsByTagName !== \"undefined\" ) {\n" \
"						// handleScript alters the DOM, so use jQuery.merge to ensure snapshot iteration\n" \
"						jsTags = jQuery.grep( jQuery.merge( [], elem.getElementsByTagName(\"script\") ), handleScript );\n" \
"\n" \
"						// Splice the scripts into ret after their former ancestor and advance our index beyond them\n" \
"						ret.splice.apply( ret, [i + 1, 0].concat( jsTags ) );\n" \
"						i += jsTags.length;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	},\n" \
"\n" \
"	cleanData: function( elems, /* internal */ acceptData ) {\n" \
"		var data, id, elem, type,\n" \
"			i = 0,\n" \
"			internalKey = jQuery.expando,\n" \
"			cache = jQuery.cache,\n" \
"			deleteExpando = jQuery.support.deleteExpando,\n" \
"			special = jQuery.event.special;\n" \
"\n" \
"		for ( ; (elem = elems[i]) != null; i++ ) {\n" \
"\n" \
"			if ( acceptData || jQuery.acceptData( elem ) ) {\n" \
"\n" \
"				id = elem[ internalKey ];\n" \
"				data = id && cache[ id ];\n" \
"\n" \
"				if ( data ) {\n" \
"					if ( data.events ) {\n" \
"						for ( type in data.events ) {\n" \
"							if ( special[ type ] ) {\n" \
"								jQuery.event.remove( elem, type );\n" \
"\n" \
"							// This is a shortcut to avoid jQuery.event.remove's overhead\n" \
"							} else {\n" \
"								jQuery.removeEvent( elem, type, data.handle );\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"\n" \
"					// Remove cache only if it was not already removed by jQuery.event.remove\n" \
"					if ( cache[ id ] ) {\n" \
"\n" \
"						delete cache[ id ];\n" \
"\n" \
"						// IE does not allow us to delete expando properties from nodes,\n" \
"						// nor does it have a removeAttribute function on Document nodes;\n" \
"						// we must handle all of these cases\n" \
"						if ( deleteExpando ) {\n" \
"							delete elem[ internalKey ];\n" \
"\n" \
"						} else if ( elem.removeAttribute ) {\n" \
"							elem.removeAttribute( internalKey );\n" \
"\n" \
"						} else {\n" \
"							elem[ internalKey ] = null;\n" \
"						}\n" \
"\n" \
"						jQuery.deletedIds.push( id );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"});\n" \
"// Limit scope pollution from any deprecated API\n" \
"(function() {\n" \
"\n" \
"var matched, browser;\n" \
"\n" \
"// Use of jQuery.browser is frowned upon.\n" \
"// More details: http://api.jquery.com/jQuery.browser\n" \
"// jQuery.uaMatch maintained for back-compat\n" \
"jQuery.uaMatch = function( ua ) {\n" \
"	ua = ua.toLowerCase();\n" \
"\n" \
"	var match = /(chrome)[ \\/]([\\w.]+)/.exec( ua ) ||\n" \
"		/(webkit)[ \\/]([\\w.]+)/.exec( ua ) ||\n" \
"		/(opera)(?:.*version|)[ \\/]([\\w.]+)/.exec( ua ) ||\n" \
"		/(msie) ([\\w.]+)/.exec( ua ) ||\n" \
"		ua.indexOf(\"compatible\") < 0 && /(mozilla)(?:.*? rv:([\\w.]+)|)/.exec( ua ) ||\n" \
"		[];\n" \
"\n" \
"	return {\n" \
"		browser: match[ 1 ] || \"\",\n" \
"		version: match[ 2 ] || \"0\"\n" \
"	};\n" \
"};\n" \
"\n" \
"matched = jQuery.uaMatch( navigator.userAgent );\n" \
"browser = {};\n" \
"\n" \
"if ( matched.browser ) {\n" \
"	browser[ matched.browser ] = true;\n" \
"	browser.version = matched.version;\n" \
"}\n" \
"\n" \
"// Chrome is Webkit, but Webkit is also Safari.\n" \
"if ( browser.chrome ) {\n" \
"	browser.webkit = true;\n" \
"} else if ( browser.webkit ) {\n" \
"	browser.safari = true;\n" \
"}\n" \
"\n" \
"jQuery.browser = browser;\n" \
"\n" \
"jQuery.sub = function() {\n" \
"	function jQuerySub( selector, context ) {\n" \
"		return new jQuerySub.fn.init( selector, context );\n" \
"	}\n" \
"	jQuery.extend( true, jQuerySub, this );\n" \
"	jQuerySub.superclass = this;\n" \
"	jQuerySub.fn = jQuerySub.prototype = this();\n" \
"	jQuerySub.fn.constructor = jQuerySub;\n" \
"	jQuerySub.sub = this.sub;\n" \
"	jQuerySub.fn.init = function init( selector, context ) {\n" \
"		if ( context && context instanceof jQuery && !(context instanceof jQuerySub) ) {\n" \
"			context = jQuerySub( context );\n" \
"		}\n" \
"\n" \
"		return jQuery.fn.init.call( this, selector, context, rootjQuerySub );\n" \
"	};\n" \
"	jQuerySub.fn.init.prototype = jQuerySub.fn;\n" \
"	var rootjQuerySub = jQuerySub(document);\n" \
"	return jQuerySub;\n" \
"};\n" \
"\n" \
"})();\n" \
"var curCSS, iframe, iframeDoc,\n" \
"	ralpha = /alpha\\([^)]*\\)/i,\n" \
"	ropacity = /opacity=([^)]*)/,\n" \
"	rposition = /^(top|right|bottom|left)$/,\n" \
"	// swappable if display is none or starts with table except \"table\", \"table-cell\", or \"table-caption\"\n" \
"	// see here for display values: https://developer.mozilla.org/en-US/docs/CSS/display\n" \
"	rdisplayswap = /^(none|table(?!-c[ea]).+)/,\n" \
"	rmargin = /^margin/,\n" \
"	rnumsplit = new RegExp( \"^(\" + core_pnum + \")(.*)$\", \"i\" ),\n" \
"	rnumnonpx = new RegExp( \"^(\" + core_pnum + \")(?!px)[a-z%]+$\", \"i\" ),\n" \
"	rrelNum = new RegExp( \"^([-+])=(\" + core_pnum + \")\", \"i\" ),\n" \
"	elemdisplay = { BODY: \"block\" },\n" \
"\n" \
"	cssShow = { position: \"absolute\", visibility: \"hidden\", display: \"block\" },\n" \
"	cssNormalTransform = {\n" \
"		letterSpacing: 0,\n" \
"		fontWeight: 400\n" \
"	},\n" \
"\n" \
"	cssExpand = [ \"Top\", \"Right\", \"Bottom\", \"Left\" ],\n" \
"	cssPrefixes = [ \"Webkit\", \"O\", \"Moz\", \"ms\" ],\n" \
"\n" \
"	eventsToggle = jQuery.fn.toggle;\n" \
"\n" \
"// return a css property mapped to a potentially vendor prefixed property\n" \
"function vendorPropName( style, name ) {\n" \
"\n" \
"	// shortcut for names that are not vendor prefixed\n" \
"	if ( name in style ) {\n" \
"		return name;\n" \
"	}\n" \
"\n" \
"	// check for vendor prefixed names\n" \
"	var capName = name.charAt(0).toUpperCase() + name.slice(1),\n" \
"		origName = name,\n" \
"		i = cssPrefixes.length;\n" \
"\n" \
"	while ( i-- ) {\n" \
"		name = cssPrefixes[ i ] + capName;\n" \
"		if ( name in style ) {\n" \
"			return name;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return origName;\n" \
"}\n" \
"\n" \
"function isHidden( elem, el ) {\n" \
"	elem = el || elem;\n" \
"	return jQuery.css( elem, \"display\" ) === \"none\" || !jQuery.contains( elem.ownerDocument, elem );\n" \
"}\n" \
"\n" \
"function showHide( elements, show ) {\n" \
"	var elem, display,\n" \
"		values = [],\n" \
"		index = 0,\n" \
"		length = elements.length;\n" \
"\n" \
"	for ( ; index < length; index++ ) {\n" \
"		elem = elements[ index ];\n" \
"		if ( !elem.style ) {\n" \
"			continue;\n" \
"		}\n" \
"		values[ index ] = jQuery._data( elem, \"olddisplay\" );\n" \
"		if ( show ) {\n" \
"			// Reset the inline display of this element to learn if it is\n" \
"			// being hidden by cascaded rules or not\n" \
"			if ( !values[ index ] && elem.style.display === \"none\" ) {\n" \
"				elem.style.display = \"\";\n" \
"			}\n" \
"\n" \
"			// Set elements which have been overridden with display: none\n" \
"			// in a stylesheet to whatever the default browser style is\n" \
"			// for such an element\n" \
"			if ( elem.style.display === \"\" && isHidden( elem ) ) {\n" \
"				values[ index ] = jQuery._data( elem, \"olddisplay\", css_defaultDisplay(elem.nodeName) );\n" \
"			}\n" \
"		} else {\n" \
"			display = curCSS( elem, \"display\" );\n" \
"\n" \
"			if ( !values[ index ] && display !== \"none\" ) {\n" \
"				jQuery._data( elem, \"olddisplay\", display );\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Set the display of most of the elements in a second loop\n" \
"	// to avoid the constant reflow\n" \
"	for ( index = 0; index < length; index++ ) {\n" \
"		elem = elements[ index ];\n" \
"		if ( !elem.style ) {\n" \
"			continue;\n" \
"		}\n" \
"		if ( !show || elem.style.display === \"none\" || elem.style.display === \"\" ) {\n" \
"			elem.style.display = show ? values[ index ] || \"\" : \"none\";\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return elements;\n" \
"}\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	css: function( name, value ) {\n" \
"		return jQuery.access( this, function( elem, name, value ) {\n" \
"			return value !== undefined ?\n" \
"				jQuery.style( elem, name, value ) :\n" \
"				jQuery.css( elem, name );\n" \
"		}, name, value, arguments.length > 1 );\n" \
"	},\n" \
"	show: function() {\n" \
"		return showHide( this, true );\n" \
"	},\n" \
"	hide: function() {\n" \
"		return showHide( this );\n" \
"	},\n" \
"	toggle: function( state, fn2 ) {\n" \
"		var bool = typeof state === \"boolean\";\n" \
"\n" \
"		if ( jQuery.isFunction( state ) && jQuery.isFunction( fn2 ) ) {\n" \
"			return eventsToggle.apply( this, arguments );\n" \
"		}\n" \
"\n" \
"		return this.each(function() {\n" \
"			if ( bool ? state : isHidden( this ) ) {\n" \
"				jQuery( this ).show();\n" \
"			} else {\n" \
"				jQuery( this ).hide();\n" \
"			}\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"jQuery.extend({\n" \
"	// Add in style property hooks for overriding the default\n" \
"	// behavior of getting and setting a style property\n" \
"	cssHooks: {\n" \
"		opacity: {\n" \
"			get: function( elem, computed ) {\n" \
"				if ( computed ) {\n" \
"					// We should always get a number back from opacity\n" \
"					var ret = curCSS( elem, \"opacity\" );\n" \
"					return ret === \"\" ? \"1\" : ret;\n" \
"\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	},\n" \
"\n" \
"	// Exclude the following css properties to add px\n" \
"	cssNumber: {\n" \
"		\"fillOpacity\": true,\n" \
"		\"fontWeight\": true,\n" \
"		\"lineHeight\": true,\n" \
"		\"opacity\": true,\n" \
"		\"orphans\": true,\n" \
"		\"widows\": true,\n" \
"		\"zIndex\": true,\n" \
"		\"zoom\": true\n" \
"	},\n" \
"\n" \
"	// Add in properties whose names you wish to fix before\n" \
"	// setting or getting the value\n" \
"	cssProps: {\n" \
"		// normalize float css property\n" \
"		\"float\": jQuery.support.cssFloat ? \"cssFloat\" : \"styleFloat\"\n" \
"	},\n" \
"\n" \
"	// Get and set the style property on a DOM Node\n" \
"	style: function( elem, name, value, extra ) {\n" \
"		// Don't set styles on text and comment nodes\n" \
"		if ( !elem || elem.nodeType === 3 || elem.nodeType === 8 || !elem.style ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		// Make sure that we're working with the right name\n" \
"		var ret, type, hooks,\n" \
"			origName = jQuery.camelCase( name ),\n" \
"			style = elem.style;\n" \
"\n" \
"		name = jQuery.cssProps[ origName ] || ( jQuery.cssProps[ origName ] = vendorPropName( style, origName ) );\n" \
"\n" \
"		// gets hook for the prefixed version\n" \
"		// followed by the unprefixed version\n" \
"		hooks = jQuery.cssHooks[ name ] || jQuery.cssHooks[ origName ];\n" \
"\n" \
"		// Check if we're setting a value\n" \
"		if ( value !== undefined ) {\n" \
"			type = typeof value;\n" \
"\n" \
"			// convert relative number strings (+= or -=) to relative numbers. #7345\n" \
"			if ( type === \"string\" && (ret = rrelNum.exec( value )) ) {\n" \
"				value = ( ret[1] + 1 ) * ret[2] + parseFloat( jQuery.css( elem, name ) );\n" \
"				// Fixes bug #9237\n" \
"				type = \"number\";\n" \
"			}\n" \
"\n" \
"			// Make sure that NaN and null values aren't set. See: #7116\n" \
"			if ( value == null || type === \"number\" && isNaN( value ) ) {\n" \
"				return;\n" \
"			}\n" \
"\n" \
"			// If a number was passed in, add 'px' to the (except for certain CSS properties)\n" \
"			if ( type === \"number\" && !jQuery.cssNumber[ origName ] ) {\n" \
"				value += \"px\";\n" \
"			}\n" \
"\n" \
"			// If a hook was provided, use that value, otherwise just set the specified value\n" \
"			if ( !hooks || !(\"set\" in hooks) || (value = hooks.set( elem, value, extra )) !== undefined ) {\n" \
"				// Wrapped to prevent IE from throwing errors when 'invalid' values are provided\n" \
"				// Fixes bug #5509\n" \
"				try {\n" \
"					style[ name ] = value;\n" \
"				} catch(e) {}\n" \
"			}\n" \
"\n" \
"		} else {\n" \
"			// If a hook was provided get the non-computed value from there\n" \
"			if ( hooks && \"get\" in hooks && (ret = hooks.get( elem, false, extra )) !== undefined ) {\n" \
"				return ret;\n" \
"			}\n" \
"\n" \
"			// Otherwise just get the value from the style object\n" \
"			return style[ name ];\n" \
"		}\n" \
"	},\n" \
"\n" \
"	css: function( elem, name, numeric, extra ) {\n" \
"		var val, num, hooks,\n" \
"			origName = jQuery.camelCase( name );\n" \
"\n" \
"		// Make sure that we're working with the right name\n" \
"		name = jQuery.cssProps[ origName ] || ( jQuery.cssProps[ origName ] = vendorPropName( elem.style, origName ) );\n" \
"\n" \
"		// gets hook for the prefixed version\n" \
"		// followed by the unprefixed version\n" \
"		hooks = jQuery.cssHooks[ name ] || jQuery.cssHooks[ origName ];\n" \
"\n" \
"		// If a hook was provided get the computed value from there\n" \
"		if ( hooks && \"get\" in hooks ) {\n" \
"			val = hooks.get( elem, true, extra );\n" \
"		}\n" \
"\n" \
"		// Otherwise, if a way to get the computed value exists, use that\n" \
"		if ( val === undefined ) {\n" \
"			val = curCSS( elem, name );\n" \
"		}\n" \
"\n" \
"		//convert \"normal\" to computed value\n" \
"		if ( val === \"normal\" && name in cssNormalTransform ) {\n" \
"			val = cssNormalTransform[ name ];\n" \
"		}\n" \
"\n" \
"		// Return, converting to number if forced or a qualifier was provided and val looks numeric\n" \
"		if ( numeric || extra !== undefined ) {\n" \
"			num = parseFloat( val );\n" \
"			return numeric || jQuery.isNumeric( num ) ? num || 0 : val;\n" \
"		}\n" \
"		return val;\n" \
"	},\n" \
"\n" \
"	// A method for quickly swapping in/out CSS properties to get correct calculations\n" \
"	swap: function( elem, options, callback ) {\n" \
"		var ret, name,\n" \
"			old = {};\n" \
"\n" \
"		// Remember the old values, and insert the new ones\n" \
"		for ( name in options ) {\n" \
"			old[ name ] = elem.style[ name ];\n" \
"			elem.style[ name ] = options[ name ];\n" \
"		}\n" \
"\n" \
"		ret = callback.call( elem );\n" \
"\n" \
"		// Revert the old values\n" \
"		for ( name in options ) {\n" \
"			elem.style[ name ] = old[ name ];\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	}\n" \
"});\n" \
"\n" \
"// NOTE: To any future maintainer, we've window.getComputedStyle\n" \
"// because jsdom on node.js will break without it.\n" \
"if ( window.getComputedStyle ) {\n" \
"	curCSS = function( elem, name ) {\n" \
"		var ret, width, minWidth, maxWidth,\n" \
"			computed = window.getComputedStyle( elem, null ),\n" \
"			style = elem.style;\n" \
"\n" \
"		if ( computed ) {\n" \
"\n" \
"			// getPropertyValue is only needed for .css('filter') in IE9, see #12537\n" \
"			ret = computed.getPropertyValue( name ) || computed[ name ];\n" \
"\n" \
"			if ( ret === \"\" && !jQuery.contains( elem.ownerDocument, elem ) ) {\n" \
"				ret = jQuery.style( elem, name );\n" \
"			}\n" \
"\n" \
"			// A tribute to the \"awesome hack by Dean Edwards\"\n" \
"			// Chrome < 17 and Safari 5.0 uses \"computed value\" instead of \"used value\" for margin-right\n" \
"			// Safari 5.1.7 (at least) returns percentage for a larger set of values, but width seems to be reliably pixels\n" \
"			// this is against the CSSOM draft spec: http://dev.w3.org/csswg/cssom/#resolved-values\n" \
"			if ( rnumnonpx.test( ret ) && rmargin.test( name ) ) {\n" \
"				width = style.width;\n" \
"				minWidth = style.minWidth;\n" \
"				maxWidth = style.maxWidth;\n" \
"\n" \
"				style.minWidth = style.maxWidth = style.width = ret;\n" \
"				ret = computed.width;\n" \
"\n" \
"				style.width = width;\n" \
"				style.minWidth = minWidth;\n" \
"				style.maxWidth = maxWidth;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret;\n" \
"	};\n" \
"} else if ( document.documentElement.currentStyle ) {\n" \
"	curCSS = function( elem, name ) {\n" \
"		var left, rsLeft,\n" \
"			ret = elem.currentStyle && elem.currentStyle[ name ],\n" \
"			style = elem.style;\n" \
"\n" \
"		// Avoid setting ret to empty string here\n" \
"		// so we don't default to auto\n" \
"		if ( ret == null && style && style[ name ] ) {\n" \
"			ret = style[ name ];\n" \
"		}\n" \
"\n" \
"		// From the awesome hack by Dean Edwards\n" \
"		// http://erik.eae.net/archives/2007/07/27/18.54.15/#comment-102291\n" \
"\n" \
"		// If we're not dealing with a regular pixel number\n" \
"		// but a number that has a weird ending, we need to convert it to pixels\n" \
"		// but not position css attributes, as those are proportional to the parent element instead\n" \
"		// and we can't measure the parent instead because it might trigger a \"stacking dolls\" problem\n" \
"		if ( rnumnonpx.test( ret ) && !rposition.test( name ) ) {\n" \
"\n" \
"			// Remember the original values\n" \
"			left = style.left;\n" \
"			rsLeft = elem.runtimeStyle && elem.runtimeStyle.left;\n" \
"\n" \
"			// Put in the new values to get a computed value out\n" \
"			if ( rsLeft ) {\n" \
"				elem.runtimeStyle.left = elem.currentStyle.left;\n" \
"			}\n" \
"			style.left = name === \"fontSize\" ? \"1em\" : ret;\n" \
"			ret = style.pixelLeft + \"px\";\n" \
"\n" \
"			// Revert the changed values\n" \
"			style.left = left;\n" \
"			if ( rsLeft ) {\n" \
"				elem.runtimeStyle.left = rsLeft;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return ret === \"\" ? \"auto\" : ret;\n" \
"	};\n" \
"}\n" \
"\n" \
"function setPositiveNumber( elem, value, subtract ) {\n" \
"	var matches = rnumsplit.exec( value );\n" \
"	return matches ?\n" \
"			Math.max( 0, matches[ 1 ] - ( subtract || 0 ) ) + ( matches[ 2 ] || \"px\" ) :\n" \
"			value;\n" \
"}\n" \
"\n" \
"function augmentWidthOrHeight( elem, name, extra, isBorderBox ) {\n" \
"	var i = extra === ( isBorderBox ? \"border\" : \"content\" ) ?\n" \
"		// If we already have the right measurement, avoid augmentation\n" \
"		4 :\n" \
"		// Otherwise initialize for horizontal or vertical properties\n" \
"		name === \"width\" ? 1 : 0,\n" \
"\n" \
"		val = 0;\n" \
"\n" \
"	for ( ; i < 4; i += 2 ) {\n" \
"		// both box models exclude margin, so add it if we want it\n" \
"		if ( extra === \"margin\" ) {\n" \
"			// we use jQuery.css instead of curCSS here\n" \
"			// because of the reliableMarginRight CSS hook!\n" \
"			val += jQuery.css( elem, extra + cssExpand[ i ], true );\n" \
"		}\n" \
"\n" \
"		// From this point on we use curCSS for maximum performance (relevant in animations)\n" \
"		if ( isBorderBox ) {\n" \
"			// border-box includes padding, so remove it if we want content\n" \
"			if ( extra === \"content\" ) {\n" \
"				val -= parseFloat( curCSS( elem, \"padding\" + cssExpand[ i ] ) ) || 0;\n" \
"			}\n" \
"\n" \
"			// at this point, extra isn't border nor margin, so remove border\n" \
"			if ( extra !== \"margin\" ) {\n" \
"				val -= parseFloat( curCSS( elem, \"border\" + cssExpand[ i ] + \"Width\" ) ) || 0;\n" \
"			}\n" \
"		} else {\n" \
"			// at this point, extra isn't content, so add padding\n" \
"			val += parseFloat( curCSS( elem, \"padding\" + cssExpand[ i ] ) ) || 0;\n" \
"\n" \
"			// at this point, extra isn't content nor padding, so add border\n" \
"			if ( extra !== \"padding\" ) {\n" \
"				val += parseFloat( curCSS( elem, \"border\" + cssExpand[ i ] + \"Width\" ) ) || 0;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return val;\n" \
"}\n" \
"\n" \
"function getWidthOrHeight( elem, name, extra ) {\n" \
"\n" \
"	// Start with offset property, which is equivalent to the border-box value\n" \
"	var val = name === \"width\" ? elem.offsetWidth : elem.offsetHeight,\n" \
"		valueIsBorderBox = true,\n" \
"		isBorderBox = jQuery.support.boxSizing && jQuery.css( elem, \"boxSizing\" ) === \"border-box\";\n" \
"\n" \
"	// some non-html elements return undefined for offsetWidth, so check for null/undefined\n" \
"	// svg - https://bugzilla.mozilla.org/show_bug.cgi?id=649285\n" \
"	// MathML - https://bugzilla.mozilla.org/show_bug.cgi?id=491668\n" \
"	if ( val <= 0 || val == null ) {\n" \
"		// Fall back to computed then uncomputed css if necessary\n" \
"		val = curCSS( elem, name );\n" \
"		if ( val < 0 || val == null ) {\n" \
"			val = elem.style[ name ];\n" \
"		}\n" \
"\n" \
"		// Computed unit is not pixels. Stop here and return.\n" \
"		if ( rnumnonpx.test(val) ) {\n" \
"			return val;\n" \
"		}\n" \
"\n" \
"		// we need the check for style in case a browser which returns unreliable values\n" \
"		// for getComputedStyle silently falls back to the reliable elem.style\n" \
"		valueIsBorderBox = isBorderBox && ( jQuery.support.boxSizingReliable || val === elem.style[ name ] );\n" \
"\n" \
"		// Normalize \"\", auto, and prepare for extra\n" \
"		val = parseFloat( val ) || 0;\n" \
"	}\n" \
"\n" \
"	// use the active box-sizing model to add/subtract irrelevant styles\n" \
"	return ( val +\n" \
"		augmentWidthOrHeight(\n" \
"			elem,\n" \
"			name,\n" \
"			extra || ( isBorderBox ? \"border\" : \"content\" ),\n" \
"			valueIsBorderBox\n" \
"		)\n" \
"	) + \"px\";\n" \
"}\n" \
"\n" \
"\n" \
"// Try to determine the default display value of an element\n" \
"function css_defaultDisplay( nodeName ) {\n" \
"	if ( elemdisplay[ nodeName ] ) {\n" \
"		return elemdisplay[ nodeName ];\n" \
"	}\n" \
"\n" \
"	var elem = jQuery( \"<\" + nodeName + \">\" ).appendTo( document.body ),\n" \
"		display = elem.css(\"display\");\n" \
"	elem.remove();\n" \
"\n" \
"	// If the simple way fails,\n" \
"	// get element's real default display by attaching it to a temp iframe\n" \
"	if ( display === \"none\" || display === \"\" ) {\n" \
"		// Use the already-created iframe if possible\n" \
"		iframe = document.body.appendChild(\n" \
"			iframe || jQuery.extend( document.createElement(\"iframe\"), {\n" \
"				frameBorder: 0,\n" \
"				width: 0,\n" \
"				height: 0\n" \
"			})\n" \
"		);\n" \
"\n" \
"		// Create a cacheable copy of the iframe document on first call.\n" \
"		// IE and Opera will allow us to reuse the iframeDoc without re-writing the fake HTML\n" \
"		// document to it; WebKit & Firefox won't allow reusing the iframe document.\n" \
"		if ( !iframeDoc || !iframe.createElement ) {\n" \
"			iframeDoc = ( iframe.contentWindow || iframe.contentDocument ).document;\n" \
"			iframeDoc.write(\"<!doctype html><html><body>\");\n" \
"			iframeDoc.close();\n" \
"		}\n" \
"\n" \
"		elem = iframeDoc.body.appendChild( iframeDoc.createElement(nodeName) );\n" \
"\n" \
"		display = curCSS( elem, \"display\" );\n" \
"		document.body.removeChild( iframe );\n" \
"	}\n" \
"\n" \
"	// Store the correct default display\n" \
"	elemdisplay[ nodeName ] = display;\n" \
"\n" \
"	return display;\n" \
"}\n" \
"\n" \
"jQuery.each([ \"height\", \"width\" ], function( i, name ) {\n" \
"	jQuery.cssHooks[ name ] = {\n" \
"		get: function( elem, computed, extra ) {\n" \
"			if ( computed ) {\n" \
"				// certain elements can have dimension info if we invisibly show them\n" \
"				// however, it must have a current display style that would benefit from this\n" \
"				if ( elem.offsetWidth === 0 && rdisplayswap.test( curCSS( elem, \"display\" ) ) ) {\n" \
"					return jQuery.swap( elem, cssShow, function() {\n" \
"						return getWidthOrHeight( elem, name, extra );\n" \
"					});\n" \
"				} else {\n" \
"					return getWidthOrHeight( elem, name, extra );\n" \
"				}\n" \
"			}\n" \
"		},\n" \
"\n" \
"		set: function( elem, value, extra ) {\n" \
"			return setPositiveNumber( elem, value, extra ?\n" \
"				augmentWidthOrHeight(\n" \
"					elem,\n" \
"					name,\n" \
"					extra,\n" \
"					jQuery.support.boxSizing && jQuery.css( elem, \"boxSizing\" ) === \"border-box\"\n" \
"				) : 0\n" \
"			);\n" \
"		}\n" \
"	};\n" \
"});\n" \
"\n" \
"if ( !jQuery.support.opacity ) {\n" \
"	jQuery.cssHooks.opacity = {\n" \
"		get: function( elem, computed ) {\n" \
"			// IE uses filters for opacity\n" \
"			return ropacity.test( (computed && elem.currentStyle ? elem.currentStyle.filter : elem.style.filter) || \"\" ) ?\n" \
"				( 0.01 * parseFloat( RegExp.$1 ) ) + \"\" :\n" \
"				computed ? \"1\" : \"\";\n" \
"		},\n" \
"\n" \
"		set: function( elem, value ) {\n" \
"			var style = elem.style,\n" \
"				currentStyle = elem.currentStyle,\n" \
"				opacity = jQuery.isNumeric( value ) ? \"alpha(opacity=\" + value * 100 + \")\" : \"\",\n" \
"				filter = currentStyle && currentStyle.filter || style.filter || \"\";\n" \
"\n" \
"			// IE has trouble with opacity if it does not have layout\n" \
"			// Force it by setting the zoom level\n" \
"			style.zoom = 1;\n" \
"\n" \
"			// if setting opacity to 1, and no other filters exist - attempt to remove filter attribute #6652\n" \
"			if ( value >= 1 && jQuery.trim( filter.replace( ralpha, \"\" ) ) === \"\" &&\n" \
"				style.removeAttribute ) {\n" \
"\n" \
"				// Setting style.filter to null, \"\" & \" \" still leave \"filter:\" in the cssText\n" \
"				// if \"filter:\" is present at all, clearType is disabled, we want to avoid this\n" \
"				// style.removeAttribute is IE Only, but so apparently is this code path...\n" \
"				style.removeAttribute( \"filter\" );\n" \
"\n" \
"				// if there there is no filter style applied in a css rule, we are done\n" \
"				if ( currentStyle && !currentStyle.filter ) {\n" \
"					return;\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// otherwise, set new filter values\n" \
"			style.filter = ralpha.test( filter ) ?\n" \
"				filter.replace( ralpha, opacity ) :\n" \
"				filter + \" \" + opacity;\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"// These hooks cannot be added until DOM ready because the support test\n" \
"// for it is not run until after DOM ready\n" \
"jQuery(function() {\n" \
"	if ( !jQuery.support.reliableMarginRight ) {\n" \
"		jQuery.cssHooks.marginRight = {\n" \
"			get: function( elem, computed ) {\n" \
"				// WebKit Bug 13343 - getComputedStyle returns wrong value for margin-right\n" \
"				// Work around by temporarily setting element display to inline-block\n" \
"				return jQuery.swap( elem, { \"display\": \"inline-block\" }, function() {\n" \
"					if ( computed ) {\n" \
"						return curCSS( elem, \"marginRight\" );\n" \
"					}\n" \
"				});\n" \
"			}\n" \
"		};\n" \
"	}\n" \
"\n" \
"	// Webkit bug: https://bugs.webkit.org/show_bug.cgi?id=29084\n" \
"	// getComputedStyle returns percent when specified for top/left/bottom/right\n" \
"	// rather than make the css module depend on the offset module, we just check for it here\n" \
"	if ( !jQuery.support.pixelPosition && jQuery.fn.position ) {\n" \
"		jQuery.each( [ \"top\", \"left\" ], function( i, prop ) {\n" \
"			jQuery.cssHooks[ prop ] = {\n" \
"				get: function( elem, computed ) {\n" \
"					if ( computed ) {\n" \
"						var ret = curCSS( elem, prop );\n" \
"						// if curCSS returns percentage, fallback to offset\n" \
"						return rnumnonpx.test( ret ) ? jQuery( elem ).position()[ prop ] + \"px\" : ret;\n" \
"					}\n" \
"				}\n" \
"			};\n" \
"		});\n" \
"	}\n" \
"\n" \
"});\n" \
"\n" \
"if ( jQuery.expr && jQuery.expr.filters ) {\n" \
"	jQuery.expr.filters.hidden = function( elem ) {\n" \
"		return ( elem.offsetWidth === 0 && elem.offsetHeight === 0 ) || (!jQuery.support.reliableHiddenOffsets && ((elem.style && elem.style.display) || curCSS( elem, \"display\" )) === \"none\");\n" \
"	};\n" \
"\n" \
"	jQuery.expr.filters.visible = function( elem ) {\n" \
"		return !jQuery.expr.filters.hidden( elem );\n" \
"	};\n" \
"}\n" \
"\n" \
"// These hooks are used by animate to expand properties\n" \
"jQuery.each({\n" \
"	margin: \"\",\n" \
"	padding: \"\",\n" \
"	border: \"Width\"\n" \
"}, function( prefix, suffix ) {\n" \
"	jQuery.cssHooks[ prefix + suffix ] = {\n" \
"		expand: function( value ) {\n" \
"			var i,\n" \
"\n" \
"				// assumes a single number if not a string\n" \
"				parts = typeof value === \"string\" ? value.split(\" \") : [ value ],\n" \
"				expanded = {};\n" \
"\n" \
"			for ( i = 0; i < 4; i++ ) {\n" \
"				expanded[ prefix + cssExpand[ i ] + suffix ] =\n" \
"					parts[ i ] || parts[ i - 2 ] || parts[ 0 ];\n" \
"			}\n" \
"\n" \
"			return expanded;\n" \
"		}\n" \
"	};\n" \
"\n" \
"	if ( !rmargin.test( prefix ) ) {\n" \
"		jQuery.cssHooks[ prefix + suffix ].set = setPositiveNumber;\n" \
"	}\n" \
"});\n" \
"var r20 = /%20/g,\n" \
"	rbracket = /\\[\\]$/,\n" \
"	rCRLF = /\\r?\\n/g,\n" \
"	rinput = /^(?:color|date|datetime|datetime-local|email|hidden|month|number|password|range|search|tel|text|time|url|week)$/i,\n" \
"	rselectTextarea = /^(?:select|textarea)/i;\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	serialize: function() {\n" \
"		return jQuery.param( this.serializeArray() );\n" \
"	},\n" \
"	serializeArray: function() {\n" \
"		return this.map(function(){\n" \
"			return this.elements ? jQuery.makeArray( this.elements ) : this;\n" \
"		})\n" \
"		.filter(function(){\n" \
"			return this.name && !this.disabled &&\n" \
"				( this.checked || rselectTextarea.test( this.nodeName ) ||\n" \
"					rinput.test( this.type ) );\n" \
"		})\n" \
"		.map(function( i, elem ){\n" \
"			var val = jQuery( this ).val();\n" \
"\n" \
"			return val == null ?\n" \
"				null :\n" \
"				jQuery.isArray( val ) ?\n" \
"					jQuery.map( val, function( val, i ){\n" \
"						return { name: elem.name, value: val.replace( rCRLF, \"\\r\\n\" ) };\n" \
"					}) :\n" \
"					{ name: elem.name, value: val.replace( rCRLF, \"\\r\\n\" ) };\n" \
"		}).get();\n" \
"	}\n" \
"});\n" \
"\n" \
"//Serialize an array of form elements or a set of\n" \
"//key/values into a query string\n" \
"jQuery.param = function( a, traditional ) {\n" \
"	var prefix,\n" \
"		s = [],\n" \
"		add = function( key, value ) {\n" \
"			// If value is a function, invoke it and return its value\n" \
"			value = jQuery.isFunction( value ) ? value() : ( value == null ? \"\" : value );\n" \
"			s[ s.length ] = encodeURIComponent( key ) + \"=\" + encodeURIComponent( value );\n" \
"		};\n" \
"\n" \
"	// Set traditional to true for jQuery <= 1.3.2 behavior.\n" \
"	if ( traditional === undefined ) {\n" \
"		traditional = jQuery.ajaxSettings && jQuery.ajaxSettings.traditional;\n" \
"	}\n" \
"\n" \
"	// If an array was passed in, assume that it is an array of form elements.\n" \
"	if ( jQuery.isArray( a ) || ( a.jquery && !jQuery.isPlainObject( a ) ) ) {\n" \
"		// Serialize the form elements\n" \
"		jQuery.each( a, function() {\n" \
"			add( this.name, this.value );\n" \
"		});\n" \
"\n" \
"	} else {\n" \
"		// If traditional, encode the \"old\" way (the way 1.3.2 or older\n" \
"		// did it), otherwise encode params recursively.\n" \
"		for ( prefix in a ) {\n" \
"			buildParams( prefix, a[ prefix ], traditional, add );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Return the resulting serialization\n" \
"	return s.join( \"&\" ).replace( r20, \"+\" );\n" \
"};\n" \
"\n" \
"function buildParams( prefix, obj, traditional, add ) {\n" \
"	var name;\n" \
"\n" \
"	if ( jQuery.isArray( obj ) ) {\n" \
"		// Serialize array item.\n" \
"		jQuery.each( obj, function( i, v ) {\n" \
"			if ( traditional || rbracket.test( prefix ) ) {\n" \
"				// Treat each array item as a scalar.\n" \
"				add( prefix, v );\n" \
"\n" \
"			} else {\n" \
"				// If array item is non-scalar (array or object), encode its\n" \
"				// numeric index to resolve deserialization ambiguity issues.\n" \
"				// Note that rack (as of 1.0.0) can't currently deserialize\n" \
"				// nested arrays properly, and attempting to do so may cause\n" \
"				// a server error. Possible fixes are to modify rack's\n" \
"				// deserialization algorithm or to provide an option or flag\n" \
"				// to force array serialization to be shallow.\n" \
"				buildParams( prefix + \"[\" + ( typeof v === \"object\" ? i : \"\" ) + \"]\", v, traditional, add );\n" \
"			}\n" \
"		});\n" \
"\n" \
"	} else if ( !traditional && jQuery.type( obj ) === \"object\" ) {\n" \
"		// Serialize object item.\n" \
"		for ( name in obj ) {\n" \
"			buildParams( prefix + \"[\" + name + \"]\", obj[ name ], traditional, add );\n" \
"		}\n" \
"\n" \
"	} else {\n" \
"		// Serialize scalar item.\n" \
"		add( prefix, obj );\n" \
"	}\n" \
"}\n" \
"var\n" \
"	// Document location\n" \
"	ajaxLocParts,\n" \
"	ajaxLocation,\n" \
"\n" \
"	rhash = /#.*$/,\n" \
"	rheaders = /^(.*?):[ \\t]*([^\\r\\n]*)\\r?$/mg, // IE leaves an \\r character at EOL\n" \
"	// #7653, #8125, #8152: local protocol detection\n" \
"	rlocalProtocol = /^(?:about|app|app\\-storage|.+\\-extension|file|res|widget):$/,\n" \
"	rnoContent = /^(?:GET|HEAD)$/,\n" \
"	rprotocol = /^\\/\\//,\n" \
"	rquery = /\\?/,\n" \
"	rscript = /<script\\b[^<]*(?:(?!<\\/script>)<[^<]*)*<\\/script>/gi,\n" \
"	rts = /([?&])_=[^&]*/,\n" \
"	rurl = /^([\\w\\+\\.\\-]+:)(?:\\/\\/([^\\/?#:]*)(?::(\\d+)|)|)/,\n" \
"\n" \
"	// Keep a copy of the old load method\n" \
"	_load = jQuery.fn.load,\n" \
"\n" \
"	/* Prefilters\n" \
"	 * 1) They are useful to introduce custom dataTypes (see ajax/jsonp.js for an example)\n" \
"	 * 2) These are called:\n" \
"	 *    - BEFORE asking for a transport\n" \
"	 *    - AFTER param serialization (s.data is a string if s.processData is true)\n" \
"	 * 3) key is the dataType\n" \
"	 * 4) the catchall symbol \"*\" can be used\n" \
"	 * 5) execution will start with transport dataType and THEN continue down to \"*\" if needed\n" \
"	 */\n" \
"	prefilters = {},\n" \
"\n" \
"	/* Transports bindings\n" \
"	 * 1) key is the dataType\n" \
"	 * 2) the catchall symbol \"*\" can be used\n" \
"	 * 3) selection will start with transport dataType and THEN go to \"*\" if needed\n" \
"	 */\n" \
"	transports = {},\n" \
"\n" \
"	// Avoid comment-prolog char sequence (#10098); must appease lint and evade compression\n" \
"	allTypes = [\"*/\"] + [\"*\"];\n" \
"\n" \
"// #8138, IE may throw an exception when accessing\n" \
"// a field from window.location if document.domain has been set\n" \
"try {\n" \
"	ajaxLocation = location.href;\n" \
"} catch( e ) {\n" \
"	// Use the href attribute of an A element\n" \
"	// since IE will modify it given document.location\n" \
"	ajaxLocation = document.createElement( \"a\" );\n" \
"	ajaxLocation.href = \"\";\n" \
"	ajaxLocation = ajaxLocation.href;\n" \
"}\n" \
"\n" \
"// Segment location into parts\n" \
"ajaxLocParts = rurl.exec( ajaxLocation.toLowerCase() ) || [];\n" \
"\n" \
"// Base \"constructor\" for jQuery.ajaxPrefilter and jQuery.ajaxTransport\n" \
"function addToPrefiltersOrTransports( structure ) {\n" \
"\n" \
"	// dataTypeExpression is optional and defaults to \"*\"\n" \
"	return function( dataTypeExpression, func ) {\n" \
"\n" \
"		if ( typeof dataTypeExpression !== \"string\" ) {\n" \
"			func = dataTypeExpression;\n" \
"			dataTypeExpression = \"*\";\n" \
"		}\n" \
"\n" \
"		var dataType, list, placeBefore,\n" \
"			dataTypes = dataTypeExpression.toLowerCase().split( core_rspace ),\n" \
"			i = 0,\n" \
"			length = dataTypes.length;\n" \
"\n" \
"		if ( jQuery.isFunction( func ) ) {\n" \
"			// For each dataType in the dataTypeExpression\n" \
"			for ( ; i < length; i++ ) {\n" \
"				dataType = dataTypes[ i ];\n" \
"				// We control if we're asked to add before\n" \
"				// any existing element\n" \
"				placeBefore = /^\\+/.test( dataType );\n" \
"				if ( placeBefore ) {\n" \
"					dataType = dataType.substr( 1 ) || \"*\";\n" \
"				}\n" \
"				list = structure[ dataType ] = structure[ dataType ] || [];\n" \
"				// then we add to the structure accordingly\n" \
"				list[ placeBefore ? \"unshift\" : \"push\" ]( func );\n" \
"			}\n" \
"		}\n" \
"	};\n" \
"}\n" \
"\n" \
"// Base inspection function for prefilters and transports\n" \
"function inspectPrefiltersOrTransports( structure, options, originalOptions, jqXHR,\n" \
"		dataType /* internal */, inspected /* internal */ ) {\n" \
"\n" \
"	dataType = dataType || options.dataTypes[ 0 ];\n" \
"	inspected = inspected || {};\n" \
"\n" \
"	inspected[ dataType ] = true;\n" \
"\n" \
"	var selection,\n" \
"		list = structure[ dataType ],\n" \
"		i = 0,\n" \
"		length = list ? list.length : 0,\n" \
"		executeOnly = ( structure === prefilters );\n" \
"\n" \
"	for ( ; i < length && ( executeOnly || !selection ); i++ ) {\n" \
"		selection = list[ i ]( options, originalOptions, jqXHR );\n" \
"		// If we got redirected to another dataType\n" \
"		// we try there if executing only and not done already\n" \
"		if ( typeof selection === \"string\" ) {\n" \
"			if ( !executeOnly || inspected[ selection ] ) {\n" \
"				selection = undefined;\n" \
"			} else {\n" \
"				options.dataTypes.unshift( selection );\n" \
"				selection = inspectPrefiltersOrTransports(\n" \
"						structure, options, originalOptions, jqXHR, selection, inspected );\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"	// If we're only executing or nothing was selected\n" \
"	// we try the catchall dataType if not done already\n" \
"	if ( ( executeOnly || !selection ) && !inspected[ \"*\" ] ) {\n" \
"		selection = inspectPrefiltersOrTransports(\n" \
"				structure, options, originalOptions, jqXHR, \"*\", inspected );\n" \
"	}\n" \
"	// unnecessary when only executing (prefilters)\n" \
"	// but it'll be ignored by the caller in that case\n" \
"	return selection;\n" \
"}\n" \
"\n" \
"// A special extend for ajax options\n" \
"// that takes \"flat\" options (not to be deep extended)\n" \
"// Fixes #9887\n" \
"function ajaxExtend( target, src ) {\n" \
"	var key, deep,\n" \
"		flatOptions = jQuery.ajaxSettings.flatOptions || {};\n" \
"	for ( key in src ) {\n" \
"		if ( src[ key ] !== undefined ) {\n" \
"			( flatOptions[ key ] ? target : ( deep || ( deep = {} ) ) )[ key ] = src[ key ];\n" \
"		}\n" \
"	}\n" \
"	if ( deep ) {\n" \
"		jQuery.extend( true, target, deep );\n" \
"	}\n" \
"}\n" \
"\n" \
"jQuery.fn.load = function( url, params, callback ) {\n" \
"	if ( typeof url !== \"string\" && _load ) {\n" \
"		return _load.apply( this, arguments );\n" \
"	}\n" \
"\n" \
"	// Don't do a request if no elements are being requested\n" \
"	if ( !this.length ) {\n" \
"		return this;\n" \
"	}\n" \
"\n" \
"	var selector, type, response,\n" \
"		self = this,\n" \
"		off = url.indexOf(\" \");\n" \
"\n" \
"	if ( off >= 0 ) {\n" \
"		selector = url.slice( off, url.length );\n" \
"		url = url.slice( 0, off );\n" \
"	}\n" \
"\n" \
"	// If it's a function\n" \
"	if ( jQuery.isFunction( params ) ) {\n" \
"\n" \
"		// We assume that it's the callback\n" \
"		callback = params;\n" \
"		params = undefined;\n" \
"\n" \
"	// Otherwise, build a param string\n" \
"	} else if ( params && typeof params === \"object\" ) {\n" \
"		type = \"POST\";\n" \
"	}\n" \
"\n" \
"	// Request the remote document\n" \
"	jQuery.ajax({\n" \
"		url: url,\n" \
"\n" \
"		// if \"type\" variable is undefined, then \"GET\" method will be used\n" \
"		type: type,\n" \
"		dataType: \"html\",\n" \
"		data: params,\n" \
"		complete: function( jqXHR, status ) {\n" \
"			if ( callback ) {\n" \
"				self.each( callback, response || [ jqXHR.responseText, status, jqXHR ] );\n" \
"			}\n" \
"		}\n" \
"	}).done(function( responseText ) {\n" \
"\n" \
"		// Save response for use in complete callback\n" \
"		response = arguments;\n" \
"\n" \
"		// See if a selector was specified\n" \
"		self.html( selector ?\n" \
"\n" \
"			// Create a dummy div to hold the results\n" \
"			jQuery(\"<div>\")\n" \
"\n" \
"				// inject the contents of the document in, removing the scripts\n" \
"				// to avoid any 'Permission Denied' errors in IE\n" \
"				.append( responseText.replace( rscript, \"\" ) )\n" \
"\n" \
"				// Locate the specified elements\n" \
"				.find( selector ) :\n" \
"\n" \
"			// If not, just inject the full result\n" \
"			responseText );\n" \
"\n" \
"	});\n" \
"\n" \
"	return this;\n" \
"};\n" \
"\n" \
"// Attach a bunch of functions for handling common AJAX events\n" \
"jQuery.each( \"ajaxStart ajaxStop ajaxComplete ajaxError ajaxSuccess ajaxSend\".split( \" \" ), function( i, o ){\n" \
"	jQuery.fn[ o ] = function( f ){\n" \
"		return this.on( o, f );\n" \
"	};\n" \
"});\n" \
"\n" \
"jQuery.each( [ \"get\", \"post\" ], function( i, method ) {\n" \
"	jQuery[ method ] = function( url, data, callback, type ) {\n" \
"		// shift arguments if data argument was omitted\n" \
"		if ( jQuery.isFunction( data ) ) {\n" \
"			type = type || callback;\n" \
"			callback = data;\n" \
"			data = undefined;\n" \
"		}\n" \
"\n" \
"		return jQuery.ajax({\n" \
"			type: method,\n" \
"			url: url,\n" \
"			data: data,\n" \
"			success: callback,\n" \
"			dataType: type\n" \
"		});\n" \
"	};\n" \
"});\n" \
"\n" \
"jQuery.extend({\n" \
"\n" \
"	getScript: function( url, callback ) {\n" \
"		return jQuery.get( url, undefined, callback, \"script\" );\n" \
"	},\n" \
"\n" \
"	getJSON: function( url, data, callback ) {\n" \
"		return jQuery.get( url, data, callback, \"json\" );\n" \
"	},\n" \
"\n" \
"	// Creates a full fledged settings object into target\n" \
"	// with both ajaxSettings and settings fields.\n" \
"	// If target is omitted, writes into ajaxSettings.\n" \
"	ajaxSetup: function( target, settings ) {\n" \
"		if ( settings ) {\n" \
"			// Building a settings object\n" \
"			ajaxExtend( target, jQuery.ajaxSettings );\n" \
"		} else {\n" \
"			// Extending ajaxSettings\n" \
"			settings = target;\n" \
"			target = jQuery.ajaxSettings;\n" \
"		}\n" \
"		ajaxExtend( target, settings );\n" \
"		return target;\n" \
"	},\n" \
"\n" \
"	ajaxSettings: {\n" \
"		url: ajaxLocation,\n" \
"		isLocal: rlocalProtocol.test( ajaxLocParts[ 1 ] ),\n" \
"		global: true,\n" \
"		type: \"GET\",\n" \
"		contentType: \"application/x-www-form-urlencoded; charset=UTF-8\",\n" \
"		processData: true,\n" \
"		async: true,\n" \
"		/*\n" \
"		timeout: 0,\n" \
"		data: null,\n" \
"		dataType: null,\n" \
"		username: null,\n" \
"		password: null,\n" \
"		cache: null,\n" \
"		throws: false,\n" \
"		traditional: false,\n" \
"		headers: {},\n" \
"		*/\n" \
"\n" \
"		accepts: {\n" \
"			xml: \"application/xml, text/xml\",\n" \
"			html: \"text/html\",\n" \
"			text: \"text/plain\",\n" \
"			json: \"application/json, text/javascript\",\n" \
"			\"*\": allTypes\n" \
"		},\n" \
"\n" \
"		contents: {\n" \
"			xml: /xml/,\n" \
"			html: /html/,\n" \
"			json: /json/\n" \
"		},\n" \
"\n" \
"		responseFields: {\n" \
"			xml: \"responseXML\",\n" \
"			text: \"responseText\"\n" \
"		},\n" \
"\n" \
"		// List of data converters\n" \
"		// 1) key format is \"source_type destination_type\" (a single space in-between)\n" \
"		// 2) the catchall symbol \"*\" can be used for source_type\n" \
"		converters: {\n" \
"\n" \
"			// Convert anything to text\n" \
"			\"* text\": window.String,\n" \
"\n" \
"			// Text to html (true = no transformation)\n" \
"			\"text html\": true,\n" \
"\n" \
"			// Evaluate text as a json expression\n" \
"			\"text json\": jQuery.parseJSON,\n" \
"\n" \
"			// Parse text as xml\n" \
"			\"text xml\": jQuery.parseXML\n" \
"		},\n" \
"\n" \
"		// For options that shouldn't be deep extended:\n" \
"		// you can add your own custom options here if\n" \
"		// and when you create one that shouldn't be\n" \
"		// deep extended (see ajaxExtend)\n" \
"		flatOptions: {\n" \
"			context: true,\n" \
"			url: true\n" \
"		}\n" \
"	},\n" \
"\n" \
"	ajaxPrefilter: addToPrefiltersOrTransports( prefilters ),\n" \
"	ajaxTransport: addToPrefiltersOrTransports( transports ),\n" \
"\n" \
"	// Main method\n" \
"	ajax: function( url, options ) {\n" \
"\n" \
"		// If url is an object, simulate pre-1.5 signature\n" \
"		if ( typeof url === \"object\" ) {\n" \
"			options = url;\n" \
"			url = undefined;\n" \
"		}\n" \
"\n" \
"		// Force options to be an object\n" \
"		options = options || {};\n" \
"\n" \
"		var // ifModified key\n" \
"			ifModifiedKey,\n" \
"			// Response headers\n" \
"			responseHeadersString,\n" \
"			responseHeaders,\n" \
"			// transport\n" \
"			transport,\n" \
"			// timeout handle\n" \
"			timeoutTimer,\n" \
"			// Cross-domain detection vars\n" \
"			parts,\n" \
"			// To know if global events are to be dispatched\n" \
"			fireGlobals,\n" \
"			// Loop variable\n" \
"			i,\n" \
"			// Create the final options object\n" \
"			s = jQuery.ajaxSetup( {}, options ),\n" \
"			// Callbacks context\n" \
"			callbackContext = s.context || s,\n" \
"			// Context for global events\n" \
"			// It's the callbackContext if one was provided in the options\n" \
"			// and if it's a DOM node or a jQuery collection\n" \
"			globalEventContext = callbackContext !== s &&\n" \
"				( callbackContext.nodeType || callbackContext instanceof jQuery ) ?\n" \
"						jQuery( callbackContext ) : jQuery.event,\n" \
"			// Deferreds\n" \
"			deferred = jQuery.Deferred(),\n" \
"			completeDeferred = jQuery.Callbacks( \"once memory\" ),\n" \
"			// Status-dependent callbacks\n" \
"			statusCode = s.statusCode || {},\n" \
"			// Headers (they are sent all at once)\n" \
"			requestHeaders = {},\n" \
"			requestHeadersNames = {},\n" \
"			// The jqXHR state\n" \
"			state = 0,\n" \
"			// Default abort message\n" \
"			strAbort = \"canceled\",\n" \
"			// Fake xhr\n" \
"			jqXHR = {\n" \
"\n" \
"				readyState: 0,\n" \
"\n" \
"				// Caches the header\n" \
"				setRequestHeader: function( name, value ) {\n" \
"					if ( !state ) {\n" \
"						var lname = name.toLowerCase();\n" \
"						name = requestHeadersNames[ lname ] = requestHeadersNames[ lname ] || name;\n" \
"						requestHeaders[ name ] = value;\n" \
"					}\n" \
"					return this;\n" \
"				},\n" \
"\n" \
"				// Raw string\n" \
"				getAllResponseHeaders: function() {\n" \
"					return state === 2 ? responseHeadersString : null;\n" \
"				},\n" \
"\n" \
"				// Builds headers hashtable if needed\n" \
"				getResponseHeader: function( key ) {\n" \
"					var match;\n" \
"					if ( state === 2 ) {\n" \
"						if ( !responseHeaders ) {\n" \
"							responseHeaders = {};\n" \
"							while( ( match = rheaders.exec( responseHeadersString ) ) ) {\n" \
"								responseHeaders[ match[1].toLowerCase() ] = match[ 2 ];\n" \
"							}\n" \
"						}\n" \
"						match = responseHeaders[ key.toLowerCase() ];\n" \
"					}\n" \
"					return match === undefined ? null : match;\n" \
"				},\n" \
"\n" \
"				// Overrides response content-type header\n" \
"				overrideMimeType: function( type ) {\n" \
"					if ( !state ) {\n" \
"						s.mimeType = type;\n" \
"					}\n" \
"					return this;\n" \
"				},\n" \
"\n" \
"				// Cancel the request\n" \
"				abort: function( statusText ) {\n" \
"					statusText = statusText || strAbort;\n" \
"					if ( transport ) {\n" \
"						transport.abort( statusText );\n" \
"					}\n" \
"					done( 0, statusText );\n" \
"					return this;\n" \
"				}\n" \
"			};\n" \
"\n" \
"		// Callback for when everything is done\n" \
"		// It is defined here because jslint complains if it is declared\n" \
"		// at the end of the function (which would be more logical and readable)\n" \
"		function done( status, nativeStatusText, responses, headers ) {\n" \
"			var isSuccess, success, error, response, modified,\n" \
"				statusText = nativeStatusText;\n" \
"\n" \
"			// Called once\n" \
"			if ( state === 2 ) {\n" \
"				return;\n" \
"			}\n" \
"\n" \
"			// State is \"done\" now\n" \
"			state = 2;\n" \
"\n" \
"			// Clear timeout if it exists\n" \
"			if ( timeoutTimer ) {\n" \
"				clearTimeout( timeoutTimer );\n" \
"			}\n" \
"\n" \
"			// Dereference transport for early garbage collection\n" \
"			// (no matter how long the jqXHR object will be used)\n" \
"			transport = undefined;\n" \
"\n" \
"			// Cache response headers\n" \
"			responseHeadersString = headers || \"\";\n" \
"\n" \
"			// Set readyState\n" \
"			jqXHR.readyState = status > 0 ? 4 : 0;\n" \
"\n" \
"			// Get response data\n" \
"			if ( responses ) {\n" \
"				response = ajaxHandleResponses( s, jqXHR, responses );\n" \
"			}\n" \
"\n" \
"			// If successful, handle type chaining\n" \
"			if ( status >= 200 && status < 300 || status === 304 ) {\n" \
"\n" \
"				// Set the If-Modified-Since and/or If-None-Match header, if in ifModified mode.\n" \
"				if ( s.ifModified ) {\n" \
"\n" \
"					modified = jqXHR.getResponseHeader(\"Last-Modified\");\n" \
"					if ( modified ) {\n" \
"						jQuery.lastModified[ ifModifiedKey ] = modified;\n" \
"					}\n" \
"					modified = jqXHR.getResponseHeader(\"Etag\");\n" \
"					if ( modified ) {\n" \
"						jQuery.etag[ ifModifiedKey ] = modified;\n" \
"					}\n" \
"				}\n" \
"\n" \
"				// If not modified\n" \
"				if ( status === 304 ) {\n" \
"\n" \
"					statusText = \"notmodified\";\n" \
"					isSuccess = true;\n" \
"\n" \
"				// If we have data\n" \
"				} else {\n" \
"\n" \
"					isSuccess = ajaxConvert( s, response );\n" \
"					statusText = isSuccess.state;\n" \
"					success = isSuccess.data;\n" \
"					error = isSuccess.error;\n" \
"					isSuccess = !error;\n" \
"				}\n" \
"			} else {\n" \
"				// We extract error from statusText\n" \
"				// then normalize statusText and status for non-aborts\n" \
"				error = statusText;\n" \
"				if ( !statusText || status ) {\n" \
"					statusText = \"error\";\n" \
"					if ( status < 0 ) {\n" \
"						status = 0;\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Set data for the fake xhr object\n" \
"			jqXHR.status = status;\n" \
"			jqXHR.statusText = ( nativeStatusText || statusText ) + \"\";\n" \
"\n" \
"			// Success/Error\n" \
"			if ( isSuccess ) {\n" \
"				deferred.resolveWith( callbackContext, [ success, statusText, jqXHR ] );\n" \
"			} else {\n" \
"				deferred.rejectWith( callbackContext, [ jqXHR, statusText, error ] );\n" \
"			}\n" \
"\n" \
"			// Status-dependent callbacks\n" \
"			jqXHR.statusCode( statusCode );\n" \
"			statusCode = undefined;\n" \
"\n" \
"			if ( fireGlobals ) {\n" \
"				globalEventContext.trigger( \"ajax\" + ( isSuccess ? \"Success\" : \"Error\" ),\n" \
"						[ jqXHR, s, isSuccess ? success : error ] );\n" \
"			}\n" \
"\n" \
"			// Complete\n" \
"			completeDeferred.fireWith( callbackContext, [ jqXHR, statusText ] );\n" \
"\n" \
"			if ( fireGlobals ) {\n" \
"				globalEventContext.trigger( \"ajaxComplete\", [ jqXHR, s ] );\n" \
"				// Handle the global AJAX counter\n" \
"				if ( !( --jQuery.active ) ) {\n" \
"					jQuery.event.trigger( \"ajaxStop\" );\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Attach deferreds\n" \
"		deferred.promise( jqXHR );\n" \
"		jqXHR.success = jqXHR.done;\n" \
"		jqXHR.error = jqXHR.fail;\n" \
"		jqXHR.complete = completeDeferred.add;\n" \
"\n" \
"		// Status-dependent callbacks\n" \
"		jqXHR.statusCode = function( map ) {\n" \
"			if ( map ) {\n" \
"				var tmp;\n" \
"				if ( state < 2 ) {\n" \
"					for ( tmp in map ) {\n" \
"						statusCode[ tmp ] = [ statusCode[tmp], map[tmp] ];\n" \
"					}\n" \
"				} else {\n" \
"					tmp = map[ jqXHR.status ];\n" \
"					jqXHR.always( tmp );\n" \
"				}\n" \
"			}\n" \
"			return this;\n" \
"		};\n" \
"\n" \
"		// Remove hash character (#7531: and string promotion)\n" \
"		// Add protocol if not provided (#5866: IE7 issue with protocol-less urls)\n" \
"		// We also use the url parameter if available\n" \
"		s.url = ( ( url || s.url ) + \"\" ).replace( rhash, \"\" ).replace( rprotocol, ajaxLocParts[ 1 ] + \"//\" );\n" \
"\n" \
"		// Extract dataTypes list\n" \
"		s.dataTypes = jQuery.trim( s.dataType || \"*\" ).toLowerCase().split( core_rspace );\n" \
"\n" \
"		// A cross-domain request is in order when we have a protocol:host:port mismatch\n" \
"		if ( s.crossDomain == null ) {\n" \
"			parts = rurl.exec( s.url.toLowerCase() );\n" \
"			s.crossDomain = !!( parts &&\n" \
"				( parts[ 1 ] !== ajaxLocParts[ 1 ] || parts[ 2 ] !== ajaxLocParts[ 2 ] ||\n" \
"					( parts[ 3 ] || ( parts[ 1 ] === \"http:\" ? 80 : 443 ) ) !=\n" \
"						( ajaxLocParts[ 3 ] || ( ajaxLocParts[ 1 ] === \"http:\" ? 80 : 443 ) ) )\n" \
"			);\n" \
"		}\n" \
"\n" \
"		// Convert data if not already a string\n" \
"		if ( s.data && s.processData && typeof s.data !== \"string\" ) {\n" \
"			s.data = jQuery.param( s.data, s.traditional );\n" \
"		}\n" \
"\n" \
"		// Apply prefilters\n" \
"		inspectPrefiltersOrTransports( prefilters, s, options, jqXHR );\n" \
"\n" \
"		// If request was aborted inside a prefilter, stop there\n" \
"		if ( state === 2 ) {\n" \
"			return jqXHR;\n" \
"		}\n" \
"\n" \
"		// We can fire global events as of now if asked to\n" \
"		fireGlobals = s.global;\n" \
"\n" \
"		// Uppercase the type\n" \
"		s.type = s.type.toUpperCase();\n" \
"\n" \
"		// Determine if request has content\n" \
"		s.hasContent = !rnoContent.test( s.type );\n" \
"\n" \
"		// Watch for a new set of requests\n" \
"		if ( fireGlobals && jQuery.active++ === 0 ) {\n" \
"			jQuery.event.trigger( \"ajaxStart\" );\n" \
"		}\n" \
"\n" \
"		// More options handling for requests with no content\n" \
"		if ( !s.hasContent ) {\n" \
"\n" \
"			// If data is available, append data to url\n" \
"			if ( s.data ) {\n" \
"				s.url += ( rquery.test( s.url ) ? \"&\" : \"?\" ) + s.data;\n" \
"				// #9682: remove data so that it's not used in an eventual retry\n" \
"				delete s.data;\n" \
"			}\n" \
"\n" \
"			// Get ifModifiedKey before adding the anti-cache parameter\n" \
"			ifModifiedKey = s.url;\n" \
"\n" \
"			// Add anti-cache in url if needed\n" \
"			if ( s.cache === false ) {\n" \
"\n" \
"				var ts = jQuery.now(),\n" \
"					// try replacing _= if it is there\n" \
"					ret = s.url.replace( rts, \"$1_=\" + ts );\n" \
"\n" \
"				// if nothing was replaced, add timestamp to the end\n" \
"				s.url = ret + ( ( ret === s.url ) ? ( rquery.test( s.url ) ? \"&\" : \"?\" ) + \"_=\" + ts : \"\" );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Set the correct header, if data is being sent\n" \
"		if ( s.data && s.hasContent && s.contentType !== false || options.contentType ) {\n" \
"			jqXHR.setRequestHeader( \"Content-Type\", s.contentType );\n" \
"		}\n" \
"\n" \
"		// Set the If-Modified-Since and/or If-None-Match header, if in ifModified mode.\n" \
"		if ( s.ifModified ) {\n" \
"			ifModifiedKey = ifModifiedKey || s.url;\n" \
"			if ( jQuery.lastModified[ ifModifiedKey ] ) {\n" \
"				jqXHR.setRequestHeader( \"If-Modified-Since\", jQuery.lastModified[ ifModifiedKey ] );\n" \
"			}\n" \
"			if ( jQuery.etag[ ifModifiedKey ] ) {\n" \
"				jqXHR.setRequestHeader( \"If-None-Match\", jQuery.etag[ ifModifiedKey ] );\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// Set the Accepts header for the server, depending on the dataType\n" \
"		jqXHR.setRequestHeader(\n" \
"			\"Accept\",\n" \
"			s.dataTypes[ 0 ] && s.accepts[ s.dataTypes[0] ] ?\n" \
"				s.accepts[ s.dataTypes[0] ] + ( s.dataTypes[ 0 ] !== \"*\" ? \", \" + allTypes + \"; q=0.01\" : \"\" ) :\n" \
"				s.accepts[ \"*\" ]\n" \
"		);\n" \
"\n" \
"		// Check for headers option\n" \
"		for ( i in s.headers ) {\n" \
"			jqXHR.setRequestHeader( i, s.headers[ i ] );\n" \
"		}\n" \
"\n" \
"		// Allow custom headers/mimetypes and early abort\n" \
"		if ( s.beforeSend && ( s.beforeSend.call( callbackContext, jqXHR, s ) === false || state === 2 ) ) {\n" \
"				// Abort if not done already and return\n" \
"				return jqXHR.abort();\n" \
"\n" \
"		}\n" \
"\n" \
"		// aborting is no longer a cancellation\n" \
"		strAbort = \"abort\";\n" \
"\n" \
"		// Install callbacks on deferreds\n" \
"		for ( i in { success: 1, error: 1, complete: 1 } ) {\n" \
"			jqXHR[ i ]( s[ i ] );\n" \
"		}\n" \
"\n" \
"		// Get transport\n" \
"		transport = inspectPrefiltersOrTransports( transports, s, options, jqXHR );\n" \
"\n" \
"		// If no transport, we auto-abort\n" \
"		if ( !transport ) {\n" \
"			done( -1, \"No Transport\" );\n" \
"		} else {\n" \
"			jqXHR.readyState = 1;\n" \
"			// Send global event\n" \
"			if ( fireGlobals ) {\n" \
"				globalEventContext.trigger( \"ajaxSend\", [ jqXHR, s ] );\n" \
"			}\n" \
"			// Timeout\n" \
"			if ( s.async && s.timeout > 0 ) {\n" \
"				timeoutTimer = setTimeout( function(){\n" \
"					jqXHR.abort( \"timeout\" );\n" \
"				}, s.timeout );\n" \
"			}\n" \
"\n" \
"			try {\n" \
"				state = 1;\n" \
"				transport.send( requestHeaders, done );\n" \
"			} catch (e) {\n" \
"				// Propagate exception as error if not done\n" \
"				if ( state < 2 ) {\n" \
"					done( -1, e );\n" \
"				// Simply rethrow otherwise\n" \
"				} else {\n" \
"					throw e;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		return jqXHR;\n" \
"	},\n" \
"\n" \
"	// Counter for holding the number of active queries\n" \
"	active: 0,\n" \
"\n" \
"	// Last-Modified header cache for next request\n" \
"	lastModified: {},\n" \
"	etag: {}\n" \
"\n" \
"});\n" \
"\n" \
"/* Handles responses to an ajax request:\n" \
" * - sets all responseXXX fields accordingly\n" \
" * - finds the right dataType (mediates between content-type and expected dataType)\n" \
" * - returns the corresponding response\n" \
" */\n" \
"function ajaxHandleResponses( s, jqXHR, responses ) {\n" \
"\n" \
"	var ct, type, finalDataType, firstDataType,\n" \
"		contents = s.contents,\n" \
"		dataTypes = s.dataTypes,\n" \
"		responseFields = s.responseFields;\n" \
"\n" \
"	// Fill responseXXX fields\n" \
"	for ( type in responseFields ) {\n" \
"		if ( type in responses ) {\n" \
"			jqXHR[ responseFields[type] ] = responses[ type ];\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Remove auto dataType and get content-type in the process\n" \
"	while( dataTypes[ 0 ] === \"*\" ) {\n" \
"		dataTypes.shift();\n" \
"		if ( ct === undefined ) {\n" \
"			ct = s.mimeType || jqXHR.getResponseHeader( \"content-type\" );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Check if we're dealing with a known content-type\n" \
"	if ( ct ) {\n" \
"		for ( type in contents ) {\n" \
"			if ( contents[ type ] && contents[ type ].test( ct ) ) {\n" \
"				dataTypes.unshift( type );\n" \
"				break;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Check to see if we have a response for the expected dataType\n" \
"	if ( dataTypes[ 0 ] in responses ) {\n" \
"		finalDataType = dataTypes[ 0 ];\n" \
"	} else {\n" \
"		// Try convertible dataTypes\n" \
"		for ( type in responses ) {\n" \
"			if ( !dataTypes[ 0 ] || s.converters[ type + \" \" + dataTypes[0] ] ) {\n" \
"				finalDataType = type;\n" \
"				break;\n" \
"			}\n" \
"			if ( !firstDataType ) {\n" \
"				firstDataType = type;\n" \
"			}\n" \
"		}\n" \
"		// Or just use first one\n" \
"		finalDataType = finalDataType || firstDataType;\n" \
"	}\n" \
"\n" \
"	// If we found a dataType\n" \
"	// We add the dataType to the list if needed\n" \
"	// and return the corresponding response\n" \
"	if ( finalDataType ) {\n" \
"		if ( finalDataType !== dataTypes[ 0 ] ) {\n" \
"			dataTypes.unshift( finalDataType );\n" \
"		}\n" \
"		return responses[ finalDataType ];\n" \
"	}\n" \
"}\n" \
"\n" \
"// Chain conversions given the request and the original response\n" \
"function ajaxConvert( s, response ) {\n" \
"\n" \
"	var conv, conv2, current, tmp,\n" \
"		// Work with a copy of dataTypes in case we need to modify it for conversion\n" \
"		dataTypes = s.dataTypes.slice(),\n" \
"		prev = dataTypes[ 0 ],\n" \
"		converters = {},\n" \
"		i = 0;\n" \
"\n" \
"	// Apply the dataFilter if provided\n" \
"	if ( s.dataFilter ) {\n" \
"		response = s.dataFilter( response, s.dataType );\n" \
"	}\n" \
"\n" \
"	// Create converters map with lowercased keys\n" \
"	if ( dataTypes[ 1 ] ) {\n" \
"		for ( conv in s.converters ) {\n" \
"			converters[ conv.toLowerCase() ] = s.converters[ conv ];\n" \
"		}\n" \
"	}\n" \
"\n" \
"	// Convert to each sequential dataType, tolerating list modification\n" \
"	for ( ; (current = dataTypes[++i]); ) {\n" \
"\n" \
"		// There's only work to do if current dataType is non-auto\n" \
"		if ( current !== \"*\" ) {\n" \
"\n" \
"			// Convert response if prev dataType is non-auto and differs from current\n" \
"			if ( prev !== \"*\" && prev !== current ) {\n" \
"\n" \
"				// Seek a direct converter\n" \
"				conv = converters[ prev + \" \" + current ] || converters[ \"* \" + current ];\n" \
"\n" \
"				// If none found, seek a pair\n" \
"				if ( !conv ) {\n" \
"					for ( conv2 in converters ) {\n" \
"\n" \
"						// If conv2 outputs current\n" \
"						tmp = conv2.split(\" \");\n" \
"						if ( tmp[ 1 ] === current ) {\n" \
"\n" \
"							// If prev can be converted to accepted input\n" \
"							conv = converters[ prev + \" \" + tmp[ 0 ] ] ||\n" \
"								converters[ \"* \" + tmp[ 0 ] ];\n" \
"							if ( conv ) {\n" \
"								// Condense equivalence converters\n" \
"								if ( conv === true ) {\n" \
"									conv = converters[ conv2 ];\n" \
"\n" \
"								// Otherwise, insert the intermediate dataType\n" \
"								} else if ( converters[ conv2 ] !== true ) {\n" \
"									current = tmp[ 0 ];\n" \
"									dataTypes.splice( i--, 0, current );\n" \
"								}\n" \
"\n" \
"								break;\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"\n" \
"				// Apply converter (if not an equivalence)\n" \
"				if ( conv !== true ) {\n" \
"\n" \
"					// Unless errors are allowed to bubble, catch and return them\n" \
"					if ( conv && s[\"throws\"] ) {\n" \
"						response = conv( response );\n" \
"					} else {\n" \
"						try {\n" \
"							response = conv( response );\n" \
"						} catch ( e ) {\n" \
"							return { state: \"parsererror\", error: conv ? e : \"No conversion from \" + prev + \" to \" + current };\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// Update prev for next iteration\n" \
"			prev = current;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	return { state: \"success\", data: response };\n" \
"}\n" \
"var oldCallbacks = [],\n" \
"	rquestion = /\\?/,\n" \
"	rjsonp = /(=)\\?(?=&|$)|\\?\\?/,\n" \
"	nonce = jQuery.now();\n" \
"\n" \
"// Default jsonp settings\n" \
"jQuery.ajaxSetup({\n" \
"	jsonp: \"callback\",\n" \
"	jsonpCallback: function() {\n" \
"		var callback = oldCallbacks.pop() || ( jQuery.expando + \"_\" + ( nonce++ ) );\n" \
"		this[ callback ] = true;\n" \
"		return callback;\n" \
"	}\n" \
"});\n" \
"\n" \
"// Detect, normalize options and install callbacks for jsonp requests\n" \
"jQuery.ajaxPrefilter( \"json jsonp\", function( s, originalSettings, jqXHR ) {\n" \
"\n" \
"	var callbackName, overwritten, responseContainer,\n" \
"		data = s.data,\n" \
"		url = s.url,\n" \
"		hasCallback = s.jsonp !== false,\n" \
"		replaceInUrl = hasCallback && rjsonp.test( url ),\n" \
"		replaceInData = hasCallback && !replaceInUrl && typeof data === \"string\" &&\n" \
"			!( s.contentType || \"\" ).indexOf(\"application/x-www-form-urlencoded\") &&\n" \
"			rjsonp.test( data );\n" \
"\n" \
"	// Handle iff the expected data type is \"jsonp\" or we have a parameter to set\n" \
"	if ( s.dataTypes[ 0 ] === \"jsonp\" || replaceInUrl || replaceInData ) {\n" \
"\n" \
"		// Get callback name, remembering preexisting value associated with it\n" \
"		callbackName = s.jsonpCallback = jQuery.isFunction( s.jsonpCallback ) ?\n" \
"			s.jsonpCallback() :\n" \
"			s.jsonpCallback;\n" \
"		overwritten = window[ callbackName ];\n" \
"\n" \
"		// Insert callback into url or form data\n" \
"		if ( replaceInUrl ) {\n" \
"			s.url = url.replace( rjsonp, \"$1\" + callbackName );\n" \
"		} else if ( replaceInData ) {\n" \
"			s.data = data.replace( rjsonp, \"$1\" + callbackName );\n" \
"		} else if ( hasCallback ) {\n" \
"			s.url += ( rquestion.test( url ) ? \"&\" : \"?\" ) + s.jsonp + \"=\" + callbackName;\n" \
"		}\n" \
"\n" \
"		// Use data converter to retrieve json after script execution\n" \
"		s.converters[\"script json\"] = function() {\n" \
"			if ( !responseContainer ) {\n" \
"				jQuery.error( callbackName + \" was not called\" );\n" \
"			}\n" \
"			return responseContainer[ 0 ];\n" \
"		};\n" \
"\n" \
"		// force json dataType\n" \
"		s.dataTypes[ 0 ] = \"json\";\n" \
"\n" \
"		// Install callback\n" \
"		window[ callbackName ] = function() {\n" \
"			responseContainer = arguments;\n" \
"		};\n" \
"\n" \
"		// Clean-up function (fires after converters)\n" \
"		jqXHR.always(function() {\n" \
"			// Restore preexisting value\n" \
"			window[ callbackName ] = overwritten;\n" \
"\n" \
"			// Save back as free\n" \
"			if ( s[ callbackName ] ) {\n" \
"				// make sure that re-using the options doesn't screw things around\n" \
"				s.jsonpCallback = originalSettings.jsonpCallback;\n" \
"\n" \
"				// save the callback name for future use\n" \
"				oldCallbacks.push( callbackName );\n" \
"			}\n" \
"\n" \
"			// Call if it was a function and we have a response\n" \
"			if ( responseContainer && jQuery.isFunction( overwritten ) ) {\n" \
"				overwritten( responseContainer[ 0 ] );\n" \
"			}\n" \
"\n" \
"			responseContainer = overwritten = undefined;\n" \
"		});\n" \
"\n" \
"		// Delegate to script\n" \
"		return \"script\";\n" \
"	}\n" \
"});\n" \
"// Install script dataType\n" \
"jQuery.ajaxSetup({\n" \
"	accepts: {\n" \
"		script: \"text/javascript, application/javascript, application/ecmascript, application/x-ecmascript\"\n" \
"	},\n" \
"	contents: {\n" \
"		script: /javascript|ecmascript/\n" \
"	},\n" \
"	converters: {\n" \
"		\"text script\": function( text ) {\n" \
"			jQuery.globalEval( text );\n" \
"			return text;\n" \
"		}\n" \
"	}\n" \
"});\n" \
"\n" \
"// Handle cache's special case and global\n" \
"jQuery.ajaxPrefilter( \"script\", function( s ) {\n" \
"	if ( s.cache === undefined ) {\n" \
"		s.cache = false;\n" \
"	}\n" \
"	if ( s.crossDomain ) {\n" \
"		s.type = \"GET\";\n" \
"		s.global = false;\n" \
"	}\n" \
"});\n" \
"\n" \
"// Bind script tag hack transport\n" \
"jQuery.ajaxTransport( \"script\", function(s) {\n" \
"\n" \
"	// This transport only deals with cross domain requests\n" \
"	if ( s.crossDomain ) {\n" \
"\n" \
"		var script,\n" \
"			head = document.head || document.getElementsByTagName( \"head\" )[0] || document.documentElement;\n" \
"\n" \
"		return {\n" \
"\n" \
"			send: function( _, callback ) {\n" \
"\n" \
"				script = document.createElement( \"script\" );\n" \
"\n" \
"				script.async = \"async\";\n" \
"\n" \
"				if ( s.scriptCharset ) {\n" \
"					script.charset = s.scriptCharset;\n" \
"				}\n" \
"\n" \
"				script.src = s.url;\n" \
"\n" \
"				// Attach handlers for all browsers\n" \
"				script.onload = script.onreadystatechange = function( _, isAbort ) {\n" \
"\n" \
"					if ( isAbort || !script.readyState || /loaded|complete/.test( script.readyState ) ) {\n" \
"\n" \
"						// Handle memory leak in IE\n" \
"						script.onload = script.onreadystatechange = null;\n" \
"\n" \
"						// Remove the script\n" \
"						if ( head && script.parentNode ) {\n" \
"							head.removeChild( script );\n" \
"						}\n" \
"\n" \
"						// Dereference the script\n" \
"						script = undefined;\n" \
"\n" \
"						// Callback if not abort\n" \
"						if ( !isAbort ) {\n" \
"							callback( 200, \"success\" );\n" \
"						}\n" \
"					}\n" \
"				};\n" \
"				// Use insertBefore instead of appendChild  to circumvent an IE6 bug.\n" \
"				// This arises when a base node is used (#2709 and #4378).\n" \
"				head.insertBefore( script, head.firstChild );\n" \
"			},\n" \
"\n" \
"			abort: function() {\n" \
"				if ( script ) {\n" \
"					script.onload( 0, 1 );\n" \
"				}\n" \
"			}\n" \
"		};\n" \
"	}\n" \
"});\n" \
"var xhrCallbacks,\n" \
"	// #5280: Internet Explorer will keep connections alive if we don't abort on unload\n" \
"	xhrOnUnloadAbort = window.ActiveXObject ? function() {\n" \
"		// Abort all pending requests\n" \
"		for ( var key in xhrCallbacks ) {\n" \
"			xhrCallbacks[ key ]( 0, 1 );\n" \
"		}\n" \
"	} : false,\n" \
"	xhrId = 0;\n" \
"\n" \
"// Functions to create xhrs\n" \
"function createStandardXHR() {\n" \
"	try {\n" \
"		return new window.XMLHttpRequest();\n" \
"	} catch( e ) {}\n" \
"}\n" \
"\n" \
"function createActiveXHR() {\n" \
"	try {\n" \
"		return new window.ActiveXObject( \"Microsoft.XMLHTTP\" );\n" \
"	} catch( e ) {}\n" \
"}\n" \
"\n" \
"// Create the request object\n" \
"// (This is still attached to ajaxSettings for backward compatibility)\n" \
"jQuery.ajaxSettings.xhr = window.ActiveXObject ?\n" \
"	/* Microsoft failed to properly\n" \
"	 * implement the XMLHttpRequest in IE7 (can't request local files),\n" \
"	 * so we use the ActiveXObject when it is available\n" \
"	 * Additionally XMLHttpRequest can be disabled in IE7/IE8 so\n" \
"	 * we need a fallback.\n" \
"	 */\n" \
"	function() {\n" \
"		return !this.isLocal && createStandardXHR() || createActiveXHR();\n" \
"	} :\n" \
"	// For all other browsers, use the standard XMLHttpRequest object\n" \
"	createStandardXHR;\n" \
"\n" \
"// Determine support properties\n" \
"(function( xhr ) {\n" \
"	jQuery.extend( jQuery.support, {\n" \
"		ajax: !!xhr,\n" \
"		cors: !!xhr && ( \"withCredentials\" in xhr )\n" \
"	});\n" \
"})( jQuery.ajaxSettings.xhr() );\n" \
"\n" \
"// Create transport if the browser can provide an xhr\n" \
"if ( jQuery.support.ajax ) {\n" \
"\n" \
"	jQuery.ajaxTransport(function( s ) {\n" \
"		// Cross domain only allowed if supported through XMLHttpRequest\n" \
"		if ( !s.crossDomain || jQuery.support.cors ) {\n" \
"\n" \
"			var callback;\n" \
"\n" \
"			return {\n" \
"				send: function( headers, complete ) {\n" \
"\n" \
"					// Get a new xhr\n" \
"					var handle, i,\n" \
"						xhr = s.xhr();\n" \
"\n" \
"					// Open the socket\n" \
"					// Passing null username, generates a login popup on Opera (#2865)\n" \
"					if ( s.username ) {\n" \
"						xhr.open( s.type, s.url, s.async, s.username, s.password );\n" \
"					} else {\n" \
"						xhr.open( s.type, s.url, s.async );\n" \
"					}\n" \
"\n" \
"					// Apply custom fields if provided\n" \
"					if ( s.xhrFields ) {\n" \
"						for ( i in s.xhrFields ) {\n" \
"							xhr[ i ] = s.xhrFields[ i ];\n" \
"						}\n" \
"					}\n" \
"\n" \
"					// Override mime type if needed\n" \
"					if ( s.mimeType && xhr.overrideMimeType ) {\n" \
"						xhr.overrideMimeType( s.mimeType );\n" \
"					}\n" \
"\n" \
"					// X-Requested-With header\n" \
"					// For cross-domain requests, seeing as conditions for a preflight are\n" \
"					// akin to a jigsaw puzzle, we simply never set it to be sure.\n" \
"					// (it can always be set on a per-request basis or even using ajaxSetup)\n" \
"					// For same-domain requests, won't change header if already provided.\n" \
"					if ( !s.crossDomain && !headers[\"X-Requested-With\"] ) {\n" \
"						headers[ \"X-Requested-With\" ] = \"XMLHttpRequest\";\n" \
"					}\n" \
"\n" \
"					// Need an extra try/catch for cross domain requests in Firefox 3\n" \
"					try {\n" \
"						for ( i in headers ) {\n" \
"							xhr.setRequestHeader( i, headers[ i ] );\n" \
"						}\n" \
"					} catch( _ ) {}\n" \
"\n" \
"					// Do send the request\n" \
"					// This may raise an exception which is actually\n" \
"					// handled in jQuery.ajax (so no try/catch here)\n" \
"					xhr.send( ( s.hasContent && s.data ) || null );\n" \
"\n" \
"					// Listener\n" \
"					callback = function( _, isAbort ) {\n" \
"\n" \
"						var status,\n" \
"							statusText,\n" \
"							responseHeaders,\n" \
"							responses,\n" \
"							xml;\n" \
"\n" \
"						// Firefox throws exceptions when accessing properties\n" \
"						// of an xhr when a network error occurred\n" \
"						// http://helpful.knobs-dials.com/index.php/Component_returned_failure_code:_0x80040111_(NS_ERROR_NOT_AVAILABLE)\n" \
"						try {\n" \
"\n" \
"							// Was never called and is aborted or complete\n" \
"							if ( callback && ( isAbort || xhr.readyState === 4 ) ) {\n" \
"\n" \
"								// Only called once\n" \
"								callback = undefined;\n" \
"\n" \
"								// Do not keep as active anymore\n" \
"								if ( handle ) {\n" \
"									xhr.onreadystatechange = jQuery.noop;\n" \
"									if ( xhrOnUnloadAbort ) {\n" \
"										delete xhrCallbacks[ handle ];\n" \
"									}\n" \
"								}\n" \
"\n" \
"								// If it's an abort\n" \
"								if ( isAbort ) {\n" \
"									// Abort it manually if needed\n" \
"									if ( xhr.readyState !== 4 ) {\n" \
"										xhr.abort();\n" \
"									}\n" \
"								} else {\n" \
"									status = xhr.status;\n" \
"									responseHeaders = xhr.getAllResponseHeaders();\n" \
"									responses = {};\n" \
"									xml = xhr.responseXML;\n" \
"\n" \
"									// Construct response list\n" \
"									if ( xml && xml.documentElement /* #4958 */ ) {\n" \
"										responses.xml = xml;\n" \
"									}\n" \
"\n" \
"									// When requesting binary data, IE6-9 will throw an exception\n" \
"									// on any attempt to access responseText (#11426)\n" \
"									try {\n" \
"										responses.text = xhr.responseText;\n" \
"									} catch( e ) {\n" \
"									}\n" \
"\n" \
"									// Firefox throws an exception when accessing\n" \
"									// statusText for faulty cross-domain requests\n" \
"									try {\n" \
"										statusText = xhr.statusText;\n" \
"									} catch( e ) {\n" \
"										// We normalize with Webkit giving an empty statusText\n" \
"										statusText = \"\";\n" \
"									}\n" \
"\n" \
"									// Filter status for non standard behaviors\n" \
"\n" \
"									// If the request is local and we have data: assume a success\n" \
"									// (success with no data won't get notified, that's the best we\n" \
"									// can do given current implementations)\n" \
"									if ( !status && s.isLocal && !s.crossDomain ) {\n" \
"										status = responses.text ? 200 : 404;\n" \
"									// IE - #1450: sometimes returns 1223 when it should be 204\n" \
"									} else if ( status === 1223 ) {\n" \
"										status = 204;\n" \
"									}\n" \
"								}\n" \
"							}\n" \
"						} catch( firefoxAccessException ) {\n" \
"							if ( !isAbort ) {\n" \
"								complete( -1, firefoxAccessException );\n" \
"							}\n" \
"						}\n" \
"\n" \
"						// Call complete if needed\n" \
"						if ( responses ) {\n" \
"							complete( status, statusText, responses, responseHeaders );\n" \
"						}\n" \
"					};\n" \
"\n" \
"					if ( !s.async ) {\n" \
"						// if we're in sync mode we fire the callback\n" \
"						callback();\n" \
"					} else if ( xhr.readyState === 4 ) {\n" \
"						// (IE6 & IE7) if it's in cache and has been\n" \
"						// retrieved directly we need to fire the callback\n" \
"						setTimeout( callback, 0 );\n" \
"					} else {\n" \
"						handle = ++xhrId;\n" \
"						if ( xhrOnUnloadAbort ) {\n" \
"							// Create the active xhrs callbacks list if needed\n" \
"							// and attach the unload handler\n" \
"							if ( !xhrCallbacks ) {\n" \
"								xhrCallbacks = {};\n" \
"								jQuery( window ).unload( xhrOnUnloadAbort );\n" \
"							}\n" \
"							// Add to list of active xhrs callbacks\n" \
"							xhrCallbacks[ handle ] = callback;\n" \
"						}\n" \
"						xhr.onreadystatechange = callback;\n" \
"					}\n" \
"				},\n" \
"\n" \
"				abort: function() {\n" \
"					if ( callback ) {\n" \
"						callback(0,1);\n" \
"					}\n" \
"				}\n" \
"			};\n" \
"		}\n" \
"	});\n" \
"}\n" \
"var fxNow, timerId,\n" \
"	rfxtypes = /^(?:toggle|show|hide)$/,\n" \
"	rfxnum = new RegExp( \"^(?:([-+])=|)(\" + core_pnum + \")([a-z%]*)$\", \"i\" ),\n" \
"	rrun = /queueHooks$/,\n" \
"	animationPrefilters = [ defaultPrefilter ],\n" \
"	tweeners = {\n" \
"		\"*\": [function( prop, value ) {\n" \
"			var end, unit,\n" \
"				tween = this.createTween( prop, value ),\n" \
"				parts = rfxnum.exec( value ),\n" \
"				target = tween.cur(),\n" \
"				start = +target || 0,\n" \
"				scale = 1,\n" \
"				maxIterations = 20;\n" \
"\n" \
"			if ( parts ) {\n" \
"				end = +parts[2];\n" \
"				unit = parts[3] || ( jQuery.cssNumber[ prop ] ? \"\" : \"px\" );\n" \
"\n" \
"				// We need to compute starting value\n" \
"				if ( unit !== \"px\" && start ) {\n" \
"					// Iteratively approximate from a nonzero starting point\n" \
"					// Prefer the current property, because this process will be trivial if it uses the same units\n" \
"					// Fallback to end or a simple constant\n" \
"					start = jQuery.css( tween.elem, prop, true ) || end || 1;\n" \
"\n" \
"					do {\n" \
"						// If previous iteration zeroed out, double until we get *something*\n" \
"						// Use a string for doubling factor so we don't accidentally see scale as unchanged below\n" \
"						scale = scale || \".5\";\n" \
"\n" \
"						// Adjust and apply\n" \
"						start = start / scale;\n" \
"						jQuery.style( tween.elem, prop, start + unit );\n" \
"\n" \
"					// Update scale, tolerating zero or NaN from tween.cur()\n" \
"					// And breaking the loop if scale is unchanged or perfect, or if we've just had enough\n" \
"					} while ( scale !== (scale = tween.cur() / target) && scale !== 1 && --maxIterations );\n" \
"				}\n" \
"\n" \
"				tween.unit = unit;\n" \
"				tween.start = start;\n" \
"				// If a +=/-= token was provided, we're doing a relative animation\n" \
"				tween.end = parts[1] ? start + ( parts[1] + 1 ) * end : end;\n" \
"			}\n" \
"			return tween;\n" \
"		}]\n" \
"	};\n" \
"\n" \
"// Animations created synchronously will run synchronously\n" \
"function createFxNow() {\n" \
"	setTimeout(function() {\n" \
"		fxNow = undefined;\n" \
"	}, 0 );\n" \
"	return ( fxNow = jQuery.now() );\n" \
"}\n" \
"\n" \
"function createTweens( animation, props ) {\n" \
"	jQuery.each( props, function( prop, value ) {\n" \
"		var collection = ( tweeners[ prop ] || [] ).concat( tweeners[ \"*\" ] ),\n" \
"			index = 0,\n" \
"			length = collection.length;\n" \
"		for ( ; index < length; index++ ) {\n" \
"			if ( collection[ index ].call( animation, prop, value ) ) {\n" \
"\n" \
"				// we're done with this property\n" \
"				return;\n" \
"			}\n" \
"		}\n" \
"	});\n" \
"}\n" \
"\n" \
"function Animation( elem, properties, options ) {\n" \
"	var result,\n" \
"		index = 0,\n" \
"		tweenerIndex = 0,\n" \
"		length = animationPrefilters.length,\n" \
"		deferred = jQuery.Deferred().always( function() {\n" \
"			// don't match elem in the :animated selector\n" \
"			delete tick.elem;\n" \
"		}),\n" \
"		tick = function() {\n" \
"			var currentTime = fxNow || createFxNow(),\n" \
"				remaining = Math.max( 0, animation.startTime + animation.duration - currentTime ),\n" \
"				// archaic crash bug won't allow us to use 1 - ( 0.5 || 0 ) (#12497)\n" \
"				temp = remaining / animation.duration || 0,\n" \
"				percent = 1 - temp,\n" \
"				index = 0,\n" \
"				length = animation.tweens.length;\n" \
"\n" \
"			for ( ; index < length ; index++ ) {\n" \
"				animation.tweens[ index ].run( percent );\n" \
"			}\n" \
"\n" \
"			deferred.notifyWith( elem, [ animation, percent, remaining ]);\n" \
"\n" \
"			if ( percent < 1 && length ) {\n" \
"				return remaining;\n" \
"			} else {\n" \
"				deferred.resolveWith( elem, [ animation ] );\n" \
"				return false;\n" \
"			}\n" \
"		},\n" \
"		animation = deferred.promise({\n" \
"			elem: elem,\n" \
"			props: jQuery.extend( {}, properties ),\n" \
"			opts: jQuery.extend( true, { specialEasing: {} }, options ),\n" \
"			originalProperties: properties,\n" \
"			originalOptions: options,\n" \
"			startTime: fxNow || createFxNow(),\n" \
"			duration: options.duration,\n" \
"			tweens: [],\n" \
"			createTween: function( prop, end, easing ) {\n" \
"				var tween = jQuery.Tween( elem, animation.opts, prop, end,\n" \
"						animation.opts.specialEasing[ prop ] || animation.opts.easing );\n" \
"				animation.tweens.push( tween );\n" \
"				return tween;\n" \
"			},\n" \
"			stop: function( gotoEnd ) {\n" \
"				var index = 0,\n" \
"					// if we are going to the end, we want to run all the tweens\n" \
"					// otherwise we skip this part\n" \
"					length = gotoEnd ? animation.tweens.length : 0;\n" \
"\n" \
"				for ( ; index < length ; index++ ) {\n" \
"					animation.tweens[ index ].run( 1 );\n" \
"				}\n" \
"\n" \
"				// resolve when we played the last frame\n" \
"				// otherwise, reject\n" \
"				if ( gotoEnd ) {\n" \
"					deferred.resolveWith( elem, [ animation, gotoEnd ] );\n" \
"				} else {\n" \
"					deferred.rejectWith( elem, [ animation, gotoEnd ] );\n" \
"				}\n" \
"				return this;\n" \
"			}\n" \
"		}),\n" \
"		props = animation.props;\n" \
"\n" \
"	propFilter( props, animation.opts.specialEasing );\n" \
"\n" \
"	for ( ; index < length ; index++ ) {\n" \
"		result = animationPrefilters[ index ].call( animation, elem, props, animation.opts );\n" \
"		if ( result ) {\n" \
"			return result;\n" \
"		}\n" \
"	}\n" \
"\n" \
"	createTweens( animation, props );\n" \
"\n" \
"	if ( jQuery.isFunction( animation.opts.start ) ) {\n" \
"		animation.opts.start.call( elem, animation );\n" \
"	}\n" \
"\n" \
"	jQuery.fx.timer(\n" \
"		jQuery.extend( tick, {\n" \
"			anim: animation,\n" \
"			queue: animation.opts.queue,\n" \
"			elem: elem\n" \
"		})\n" \
"	);\n" \
"\n" \
"	// attach callbacks from options\n" \
"	return animation.progress( animation.opts.progress )\n" \
"		.done( animation.opts.done, animation.opts.complete )\n" \
"		.fail( animation.opts.fail )\n" \
"		.always( animation.opts.always );\n" \
"}\n" \
"\n" \
"function propFilter( props, specialEasing ) {\n" \
"	var index, name, easing, value, hooks;\n" \
"\n" \
"	// camelCase, specialEasing and expand cssHook pass\n" \
"	for ( index in props ) {\n" \
"		name = jQuery.camelCase( index );\n" \
"		easing = specialEasing[ name ];\n" \
"		value = props[ index ];\n" \
"		if ( jQuery.isArray( value ) ) {\n" \
"			easing = value[ 1 ];\n" \
"			value = props[ index ] = value[ 0 ];\n" \
"		}\n" \
"\n" \
"		if ( index !== name ) {\n" \
"			props[ name ] = value;\n" \
"			delete props[ index ];\n" \
"		}\n" \
"\n" \
"		hooks = jQuery.cssHooks[ name ];\n" \
"		if ( hooks && \"expand\" in hooks ) {\n" \
"			value = hooks.expand( value );\n" \
"			delete props[ name ];\n" \
"\n" \
"			// not quite $.extend, this wont overwrite keys already present.\n" \
"			// also - reusing 'index' from above because we have the correct \"name\"\n" \
"			for ( index in value ) {\n" \
"				if ( !( index in props ) ) {\n" \
"					props[ index ] = value[ index ];\n" \
"					specialEasing[ index ] = easing;\n" \
"				}\n" \
"			}\n" \
"		} else {\n" \
"			specialEasing[ name ] = easing;\n" \
"		}\n" \
"	}\n" \
"}\n" \
"\n" \
"jQuery.Animation = jQuery.extend( Animation, {\n" \
"\n" \
"	tweener: function( props, callback ) {\n" \
"		if ( jQuery.isFunction( props ) ) {\n" \
"			callback = props;\n" \
"			props = [ \"*\" ];\n" \
"		} else {\n" \
"			props = props.split(\" \");\n" \
"		}\n" \
"\n" \
"		var prop,\n" \
"			index = 0,\n" \
"			length = props.length;\n" \
"\n" \
"		for ( ; index < length ; index++ ) {\n" \
"			prop = props[ index ];\n" \
"			tweeners[ prop ] = tweeners[ prop ] || [];\n" \
"			tweeners[ prop ].unshift( callback );\n" \
"		}\n" \
"	},\n" \
"\n" \
"	prefilter: function( callback, prepend ) {\n" \
"		if ( prepend ) {\n" \
"			animationPrefilters.unshift( callback );\n" \
"		} else {\n" \
"			animationPrefilters.push( callback );\n" \
"		}\n" \
"	}\n" \
"});\n" \
"\n" \
"function defaultPrefilter( elem, props, opts ) {\n" \
"	var index, prop, value, length, dataShow, toggle, tween, hooks, oldfire,\n" \
"		anim = this,\n" \
"		style = elem.style,\n" \
"		orig = {},\n" \
"		handled = [],\n" \
"		hidden = elem.nodeType && isHidden( elem );\n" \
"\n" \
"	// handle queue: false promises\n" \
"	if ( !opts.queue ) {\n" \
"		hooks = jQuery._queueHooks( elem, \"fx\" );\n" \
"		if ( hooks.unqueued == null ) {\n" \
"			hooks.unqueued = 0;\n" \
"			oldfire = hooks.empty.fire;\n" \
"			hooks.empty.fire = function() {\n" \
"				if ( !hooks.unqueued ) {\n" \
"					oldfire();\n" \
"				}\n" \
"			};\n" \
"		}\n" \
"		hooks.unqueued++;\n" \
"\n" \
"		anim.always(function() {\n" \
"			// doing this makes sure that the complete handler will be called\n" \
"			// before this completes\n" \
"			anim.always(function() {\n" \
"				hooks.unqueued--;\n" \
"				if ( !jQuery.queue( elem, \"fx\" ).length ) {\n" \
"					hooks.empty.fire();\n" \
"				}\n" \
"			});\n" \
"		});\n" \
"	}\n" \
"\n" \
"	// height/width overflow pass\n" \
"	if ( elem.nodeType === 1 && ( \"height\" in props || \"width\" in props ) ) {\n" \
"		// Make sure that nothing sneaks out\n" \
"		// Record all 3 overflow attributes because IE does not\n" \
"		// change the overflow attribute when overflowX and\n" \
"		// overflowY are set to the same value\n" \
"		opts.overflow = [ style.overflow, style.overflowX, style.overflowY ];\n" \
"\n" \
"		// Set display property to inline-block for height/width\n" \
"		// animations on inline elements that are having width/height animated\n" \
"		if ( jQuery.css( elem, \"display\" ) === \"inline\" &&\n" \
"				jQuery.css( elem, \"float\" ) === \"none\" ) {\n" \
"\n" \
"			// inline-level elements accept inline-block;\n" \
"			// block-level elements need to be inline with layout\n" \
"			if ( !jQuery.support.inlineBlockNeedsLayout || css_defaultDisplay( elem.nodeName ) === \"inline\" ) {\n" \
"				style.display = \"inline-block\";\n" \
"\n" \
"			} else {\n" \
"				style.zoom = 1;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"\n" \
"	if ( opts.overflow ) {\n" \
"		style.overflow = \"hidden\";\n" \
"		if ( !jQuery.support.shrinkWrapBlocks ) {\n" \
"			anim.done(function() {\n" \
"				style.overflow = opts.overflow[ 0 ];\n" \
"				style.overflowX = opts.overflow[ 1 ];\n" \
"				style.overflowY = opts.overflow[ 2 ];\n" \
"			});\n" \
"		}\n" \
"	}\n" \
"\n" \
"\n" \
"	// show/hide pass\n" \
"	for ( index in props ) {\n" \
"		value = props[ index ];\n" \
"		if ( rfxtypes.exec( value ) ) {\n" \
"			delete props[ index ];\n" \
"			toggle = toggle || value === \"toggle\";\n" \
"			if ( value === ( hidden ? \"hide\" : \"show\" ) ) {\n" \
"				continue;\n" \
"			}\n" \
"			handled.push( index );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	length = handled.length;\n" \
"	if ( length ) {\n" \
"		dataShow = jQuery._data( elem, \"fxshow\" ) || jQuery._data( elem, \"fxshow\", {} );\n" \
"		if ( \"hidden\" in dataShow ) {\n" \
"			hidden = dataShow.hidden;\n" \
"		}\n" \
"\n" \
"		// store state if its toggle - enables .stop().toggle() to \"reverse\"\n" \
"		if ( toggle ) {\n" \
"			dataShow.hidden = !hidden;\n" \
"		}\n" \
"		if ( hidden ) {\n" \
"			jQuery( elem ).show();\n" \
"		} else {\n" \
"			anim.done(function() {\n" \
"				jQuery( elem ).hide();\n" \
"			});\n" \
"		}\n" \
"		anim.done(function() {\n" \
"			var prop;\n" \
"			jQuery.removeData( elem, \"fxshow\", true );\n" \
"			for ( prop in orig ) {\n" \
"				jQuery.style( elem, prop, orig[ prop ] );\n" \
"			}\n" \
"		});\n" \
"		for ( index = 0 ; index < length ; index++ ) {\n" \
"			prop = handled[ index ];\n" \
"			tween = anim.createTween( prop, hidden ? dataShow[ prop ] : 0 );\n" \
"			orig[ prop ] = dataShow[ prop ] || jQuery.style( elem, prop );\n" \
"\n" \
"			if ( !( prop in dataShow ) ) {\n" \
"				dataShow[ prop ] = tween.start;\n" \
"				if ( hidden ) {\n" \
"					tween.end = tween.start;\n" \
"					tween.start = prop === \"width\" || prop === \"height\" ? 1 : 0;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"}\n" \
"\n" \
"function Tween( elem, options, prop, end, easing ) {\n" \
"	return new Tween.prototype.init( elem, options, prop, end, easing );\n" \
"}\n" \
"jQuery.Tween = Tween;\n" \
"\n" \
"Tween.prototype = {\n" \
"	constructor: Tween,\n" \
"	init: function( elem, options, prop, end, easing, unit ) {\n" \
"		this.elem = elem;\n" \
"		this.prop = prop;\n" \
"		this.easing = easing || \"swing\";\n" \
"		this.options = options;\n" \
"		this.start = this.now = this.cur();\n" \
"		this.end = end;\n" \
"		this.unit = unit || ( jQuery.cssNumber[ prop ] ? \"\" : \"px\" );\n" \
"	},\n" \
"	cur: function() {\n" \
"		var hooks = Tween.propHooks[ this.prop ];\n" \
"\n" \
"		return hooks && hooks.get ?\n" \
"			hooks.get( this ) :\n" \
"			Tween.propHooks._default.get( this );\n" \
"	},\n" \
"	run: function( percent ) {\n" \
"		var eased,\n" \
"			hooks = Tween.propHooks[ this.prop ];\n" \
"\n" \
"		if ( this.options.duration ) {\n" \
"			this.pos = eased = jQuery.easing[ this.easing ](\n" \
"				percent, this.options.duration * percent, 0, 1, this.options.duration\n" \
"			);\n" \
"		} else {\n" \
"			this.pos = eased = percent;\n" \
"		}\n" \
"		this.now = ( this.end - this.start ) * eased + this.start;\n" \
"\n" \
"		if ( this.options.step ) {\n" \
"			this.options.step.call( this.elem, this.now, this );\n" \
"		}\n" \
"\n" \
"		if ( hooks && hooks.set ) {\n" \
"			hooks.set( this );\n" \
"		} else {\n" \
"			Tween.propHooks._default.set( this );\n" \
"		}\n" \
"		return this;\n" \
"	}\n" \
"};\n" \
"\n" \
"Tween.prototype.init.prototype = Tween.prototype;\n" \
"\n" \
"Tween.propHooks = {\n" \
"	_default: {\n" \
"		get: function( tween ) {\n" \
"			var result;\n" \
"\n" \
"			if ( tween.elem[ tween.prop ] != null &&\n" \
"				(!tween.elem.style || tween.elem.style[ tween.prop ] == null) ) {\n" \
"				return tween.elem[ tween.prop ];\n" \
"			}\n" \
"\n" \
"			// passing any value as a 4th parameter to .css will automatically\n" \
"			// attempt a parseFloat and fallback to a string if the parse fails\n" \
"			// so, simple values such as \"10px\" are parsed to Float.\n" \
"			// complex values such as \"rotate(1rad)\" are returned as is.\n" \
"			result = jQuery.css( tween.elem, tween.prop, false, \"\" );\n" \
"			// Empty strings, null, undefined and \"auto\" are converted to 0.\n" \
"			return !result || result === \"auto\" ? 0 : result;\n" \
"		},\n" \
"		set: function( tween ) {\n" \
"			// use step hook for back compat - use cssHook if its there - use .style if its\n" \
"			// available and use plain properties where available\n" \
"			if ( jQuery.fx.step[ tween.prop ] ) {\n" \
"				jQuery.fx.step[ tween.prop ]( tween );\n" \
"			} else if ( tween.elem.style && ( tween.elem.style[ jQuery.cssProps[ tween.prop ] ] != null || jQuery.cssHooks[ tween.prop ] ) ) {\n" \
"				jQuery.style( tween.elem, tween.prop, tween.now + tween.unit );\n" \
"			} else {\n" \
"				tween.elem[ tween.prop ] = tween.now;\n" \
"			}\n" \
"		}\n" \
"	}\n" \
"};\n" \
"\n" \
"// Remove in 2.0 - this supports IE8's panic based approach\n" \
"// to setting things on disconnected nodes\n" \
"\n" \
"Tween.propHooks.scrollTop = Tween.propHooks.scrollLeft = {\n" \
"	set: function( tween ) {\n" \
"		if ( tween.elem.nodeType && tween.elem.parentNode ) {\n" \
"			tween.elem[ tween.prop ] = tween.now;\n" \
"		}\n" \
"	}\n" \
"};\n" \
"\n" \
"jQuery.each([ \"toggle\", \"show\", \"hide\" ], function( i, name ) {\n" \
"	var cssFn = jQuery.fn[ name ];\n" \
"	jQuery.fn[ name ] = function( speed, easing, callback ) {\n" \
"		return speed == null || typeof speed === \"boolean\" ||\n" \
"			// special check for .toggle( handler, handler, ... )\n" \
"			( !i && jQuery.isFunction( speed ) && jQuery.isFunction( easing ) ) ?\n" \
"			cssFn.apply( this, arguments ) :\n" \
"			this.animate( genFx( name, true ), speed, easing, callback );\n" \
"	};\n" \
"});\n" \
"\n" \
"jQuery.fn.extend({\n" \
"	fadeTo: function( speed, to, easing, callback ) {\n" \
"\n" \
"		// show any hidden elements after setting opacity to 0\n" \
"		return this.filter( isHidden ).css( \"opacity\", 0 ).show()\n" \
"\n" \
"			// animate to the value specified\n" \
"			.end().animate({ opacity: to }, speed, easing, callback );\n" \
"	},\n" \
"	animate: function( prop, speed, easing, callback ) {\n" \
"		var empty = jQuery.isEmptyObject( prop ),\n" \
"			optall = jQuery.speed( speed, easing, callback ),\n" \
"			doAnimation = function() {\n" \
"				// Operate on a copy of prop so per-property easing won't be lost\n" \
"				var anim = Animation( this, jQuery.extend( {}, prop ), optall );\n" \
"\n" \
"				// Empty animations resolve immediately\n" \
"				if ( empty ) {\n" \
"					anim.stop( true );\n" \
"				}\n" \
"			};\n" \
"\n" \
"		return empty || optall.queue === false ?\n" \
"			this.each( doAnimation ) :\n" \
"			this.queue( optall.queue, doAnimation );\n" \
"	},\n" \
"	stop: function( type, clearQueue, gotoEnd ) {\n" \
"		var stopQueue = function( hooks ) {\n" \
"			var stop = hooks.stop;\n" \
"			delete hooks.stop;\n" \
"			stop( gotoEnd );\n" \
"		};\n" \
"\n" \
"		if ( typeof type !== \"string\" ) {\n" \
"			gotoEnd = clearQueue;\n" \
"			clearQueue = type;\n" \
"			type = undefined;\n" \
"		}\n" \
"		if ( clearQueue && type !== false ) {\n" \
"			this.queue( type || \"fx\", [] );\n" \
"		}\n" \
"\n" \
"		return this.each(function() {\n" \
"			var dequeue = true,\n" \
"				index = type != null && type + \"queueHooks\",\n" \
"				timers = jQuery.timers,\n" \
"				data = jQuery._data( this );\n" \
"\n" \
"			if ( index ) {\n" \
"				if ( data[ index ] && data[ index ].stop ) {\n" \
"					stopQueue( data[ index ] );\n" \
"				}\n" \
"			} else {\n" \
"				for ( index in data ) {\n" \
"					if ( data[ index ] && data[ index ].stop && rrun.test( index ) ) {\n" \
"						stopQueue( data[ index ] );\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"\n" \
"			for ( index = timers.length; index--; ) {\n" \
"				if ( timers[ index ].elem === this && (type == null || timers[ index ].queue === type) ) {\n" \
"					timers[ index ].anim.stop( gotoEnd );\n" \
"					dequeue = false;\n" \
"					timers.splice( index, 1 );\n" \
"				}\n" \
"			}\n" \
"\n" \
"			// start the next in the queue if the last step wasn't forced\n" \
"			// timers currently will call their complete callbacks, which will dequeue\n" \
"			// but only if they were gotoEnd\n" \
"			if ( dequeue || !gotoEnd ) {\n" \
"				jQuery.dequeue( this, type );\n" \
"			}\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"// Generate parameters to create a standard animation\n" \
"function genFx( type, includeWidth ) {\n" \
"	var which,\n" \
"		attrs = { height: type },\n" \
"		i = 0;\n" \
"\n" \
"	// if we include width, step value is 1 to do all cssExpand values,\n" \
"	// if we don't include width, step value is 2 to skip over Left and Right\n" \
"	includeWidth = includeWidth? 1 : 0;\n" \
"	for( ; i < 4 ; i += 2 - includeWidth ) {\n" \
"		which = cssExpand[ i ];\n" \
"		attrs[ \"margin\" + which ] = attrs[ \"padding\" + which ] = type;\n" \
"	}\n" \
"\n" \
"	if ( includeWidth ) {\n" \
"		attrs.opacity = attrs.width = type;\n" \
"	}\n" \
"\n" \
"	return attrs;\n" \
"}\n" \
"\n" \
"// Generate shortcuts for custom animations\n" \
"jQuery.each({\n" \
"	slideDown: genFx(\"show\"),\n" \
"	slideUp: genFx(\"hide\"),\n" \
"	slideToggle: genFx(\"toggle\"),\n" \
"	fadeIn: { opacity: \"show\" },\n" \
"	fadeOut: { opacity: \"hide\" },\n" \
"	fadeToggle: { opacity: \"toggle\" }\n" \
"}, function( name, props ) {\n" \
"	jQuery.fn[ name ] = function( speed, easing, callback ) {\n" \
"		return this.animate( props, speed, easing, callback );\n" \
"	};\n" \
"});\n" \
"\n" \
"jQuery.speed = function( speed, easing, fn ) {\n" \
"	var opt = speed && typeof speed === \"object\" ? jQuery.extend( {}, speed ) : {\n" \
"		complete: fn || !fn && easing ||\n" \
"			jQuery.isFunction( speed ) && speed,\n" \
"		duration: speed,\n" \
"		easing: fn && easing || easing && !jQuery.isFunction( easing ) && easing\n" \
"	};\n" \
"\n" \
"	opt.duration = jQuery.fx.off ? 0 : typeof opt.duration === \"number\" ? opt.duration :\n" \
"		opt.duration in jQuery.fx.speeds ? jQuery.fx.speeds[ opt.duration ] : jQuery.fx.speeds._default;\n" \
"\n" \
"	// normalize opt.queue - true/undefined/null -> \"fx\"\n" \
"	if ( opt.queue == null || opt.queue === true ) {\n" \
"		opt.queue = \"fx\";\n" \
"	}\n" \
"\n" \
"	// Queueing\n" \
"	opt.old = opt.complete;\n" \
"\n" \
"	opt.complete = function() {\n" \
"		if ( jQuery.isFunction( opt.old ) ) {\n" \
"			opt.old.call( this );\n" \
"		}\n" \
"\n" \
"		if ( opt.queue ) {\n" \
"			jQuery.dequeue( this, opt.queue );\n" \
"		}\n" \
"	};\n" \
"\n" \
"	return opt;\n" \
"};\n" \
"\n" \
"jQuery.easing = {\n" \
"	linear: function( p ) {\n" \
"		return p;\n" \
"	},\n" \
"	swing: function( p ) {\n" \
"		return 0.5 - Math.cos( p*Math.PI ) / 2;\n" \
"	}\n" \
"};\n" \
"\n" \
"jQuery.timers = [];\n" \
"jQuery.fx = Tween.prototype.init;\n" \
"jQuery.fx.tick = function() {\n" \
"	var timer,\n" \
"		timers = jQuery.timers,\n" \
"		i = 0;\n" \
"\n" \
"	fxNow = jQuery.now();\n" \
"\n" \
"	for ( ; i < timers.length; i++ ) {\n" \
"		timer = timers[ i ];\n" \
"		// Checks the timer has not already been removed\n" \
"		if ( !timer() && timers[ i ] === timer ) {\n" \
"			timers.splice( i--, 1 );\n" \
"		}\n" \
"	}\n" \
"\n" \
"	if ( !timers.length ) {\n" \
"		jQuery.fx.stop();\n" \
"	}\n" \
"	fxNow = undefined;\n" \
"};\n" \
"\n" \
"jQuery.fx.timer = function( timer ) {\n" \
"	if ( timer() && jQuery.timers.push( timer ) && !timerId ) {\n" \
"		timerId = setInterval( jQuery.fx.tick, jQuery.fx.interval );\n" \
"	}\n" \
"};\n" \
"\n" \
"jQuery.fx.interval = 13;\n" \
"\n" \
"jQuery.fx.stop = function() {\n" \
"	clearInterval( timerId );\n" \
"	timerId = null;\n" \
"};\n" \
"\n" \
"jQuery.fx.speeds = {\n" \
"	slow: 600,\n" \
"	fast: 200,\n" \
"	// Default speed\n" \
"	_default: 400\n" \
"};\n" \
"\n" \
"// Back Compat <1.8 extension point\n" \
"jQuery.fx.step = {};\n" \
"\n" \
"if ( jQuery.expr && jQuery.expr.filters ) {\n" \
"	jQuery.expr.filters.animated = function( elem ) {\n" \
"		return jQuery.grep(jQuery.timers, function( fn ) {\n" \
"			return elem === fn.elem;\n" \
"		}).length;\n" \
"	};\n" \
"}\n" \
"var rroot = /^(?:body|html)$/i;\n" \
"\n" \
"jQuery.fn.offset = function( options ) {\n" \
"	if ( arguments.length ) {\n" \
"		return options === undefined ?\n" \
"			this :\n" \
"			this.each(function( i ) {\n" \
"				jQuery.offset.setOffset( this, options, i );\n" \
"			});\n" \
"	}\n" \
"\n" \
"	var docElem, body, win, clientTop, clientLeft, scrollTop, scrollLeft,\n" \
"		box = { top: 0, left: 0 },\n" \
"		elem = this[ 0 ],\n" \
"		doc = elem && elem.ownerDocument;\n" \
"\n" \
"	if ( !doc ) {\n" \
"		return;\n" \
"	}\n" \
"\n" \
"	if ( (body = doc.body) === elem ) {\n" \
"		return jQuery.offset.bodyOffset( elem );\n" \
"	}\n" \
"\n" \
"	docElem = doc.documentElement;\n" \
"\n" \
"	// Make sure it's not a disconnected DOM node\n" \
"	if ( !jQuery.contains( docElem, elem ) ) {\n" \
"		return box;\n" \
"	}\n" \
"\n" \
"	// If we don't have gBCR, just use 0,0 rather than error\n" \
"	// BlackBerry 5, iOS 3 (original iPhone)\n" \
"	if ( typeof elem.getBoundingClientRect !== \"undefined\" ) {\n" \
"		box = elem.getBoundingClientRect();\n" \
"	}\n" \
"	win = getWindow( doc );\n" \
"	clientTop  = docElem.clientTop  || body.clientTop  || 0;\n" \
"	clientLeft = docElem.clientLeft || body.clientLeft || 0;\n" \
"	scrollTop  = win.pageYOffset || docElem.scrollTop;\n" \
"	scrollLeft = win.pageXOffset || docElem.scrollLeft;\n" \
"	return {\n" \
"		top: box.top  + scrollTop  - clientTop,\n" \
"		left: box.left + scrollLeft - clientLeft\n" \
"	};\n" \
"};\n" \
"\n" \
"jQuery.offset = {\n" \
"\n" \
"	bodyOffset: function( body ) {\n" \
"		var top = body.offsetTop,\n" \
"			left = body.offsetLeft;\n" \
"\n" \
"		if ( jQuery.support.doesNotIncludeMarginInBodyOffset ) {\n" \
"			top  += parseFloat( jQuery.css(body, \"marginTop\") ) || 0;\n" \
"			left += parseFloat( jQuery.css(body, \"marginLeft\") ) || 0;\n" \
"		}\n" \
"\n" \
"		return { top: top, left: left };\n" \
"	},\n" \
"\n" \
"	setOffset: function( elem, options, i ) {\n" \
"		var position = jQuery.css( elem, \"position\" );\n" \
"\n" \
"		// set position first, in-case top/left are set even on static elem\n" \
"		if ( position === \"static\" ) {\n" \
"			elem.style.position = \"relative\";\n" \
"		}\n" \
"\n" \
"		var curElem = jQuery( elem ),\n" \
"			curOffset = curElem.offset(),\n" \
"			curCSSTop = jQuery.css( elem, \"top\" ),\n" \
"			curCSSLeft = jQuery.css( elem, \"left\" ),\n" \
"			calculatePosition = ( position === \"absolute\" || position === \"fixed\" ) && jQuery.inArray(\"auto\", [curCSSTop, curCSSLeft]) > -1,\n" \
"			props = {}, curPosition = {}, curTop, curLeft;\n" \
"\n" \
"		// need to be able to calculate position if either top or left is auto and position is either absolute or fixed\n" \
"		if ( calculatePosition ) {\n" \
"			curPosition = curElem.position();\n" \
"			curTop = curPosition.top;\n" \
"			curLeft = curPosition.left;\n" \
"		} else {\n" \
"			curTop = parseFloat( curCSSTop ) || 0;\n" \
"			curLeft = parseFloat( curCSSLeft ) || 0;\n" \
"		}\n" \
"\n" \
"		if ( jQuery.isFunction( options ) ) {\n" \
"			options = options.call( elem, i, curOffset );\n" \
"		}\n" \
"\n" \
"		if ( options.top != null ) {\n" \
"			props.top = ( options.top - curOffset.top ) + curTop;\n" \
"		}\n" \
"		if ( options.left != null ) {\n" \
"			props.left = ( options.left - curOffset.left ) + curLeft;\n" \
"		}\n" \
"\n" \
"		if ( \"using\" in options ) {\n" \
"			options.using.call( elem, props );\n" \
"		} else {\n" \
"			curElem.css( props );\n" \
"		}\n" \
"	}\n" \
"};\n" \
"\n" \
"\n" \
"jQuery.fn.extend({\n" \
"\n" \
"	position: function() {\n" \
"		if ( !this[0] ) {\n" \
"			return;\n" \
"		}\n" \
"\n" \
"		var elem = this[0],\n" \
"\n" \
"		// Get *real* offsetParent\n" \
"		offsetParent = this.offsetParent(),\n" \
"\n" \
"		// Get correct offsets\n" \
"		offset       = this.offset(),\n" \
"		parentOffset = rroot.test(offsetParent[0].nodeName) ? { top: 0, left: 0 } : offsetParent.offset();\n" \
"\n" \
"		// Subtract element margins\n" \
"		// note: when an element has margin: auto the offsetLeft and marginLeft\n" \
"		// are the same in Safari causing offset.left to incorrectly be 0\n" \
"		offset.top  -= parseFloat( jQuery.css(elem, \"marginTop\") ) || 0;\n" \
"		offset.left -= parseFloat( jQuery.css(elem, \"marginLeft\") ) || 0;\n" \
"\n" \
"		// Add offsetParent borders\n" \
"		parentOffset.top  += parseFloat( jQuery.css(offsetParent[0], \"borderTopWidth\") ) || 0;\n" \
"		parentOffset.left += parseFloat( jQuery.css(offsetParent[0], \"borderLeftWidth\") ) || 0;\n" \
"\n" \
"		// Subtract the two offsets\n" \
"		return {\n" \
"			top:  offset.top  - parentOffset.top,\n" \
"			left: offset.left - parentOffset.left\n" \
"		};\n" \
"	},\n" \
"\n" \
"	offsetParent: function() {\n" \
"		return this.map(function() {\n" \
"			var offsetParent = this.offsetParent || document.body;\n" \
"			while ( offsetParent && (!rroot.test(offsetParent.nodeName) && jQuery.css(offsetParent, \"position\") === \"static\") ) {\n" \
"				offsetParent = offsetParent.offsetParent;\n" \
"			}\n" \
"			return offsetParent || document.body;\n" \
"		});\n" \
"	}\n" \
"});\n" \
"\n" \
"\n" \
"// Create scrollLeft and scrollTop methods\n" \
"jQuery.each( {scrollLeft: \"pageXOffset\", scrollTop: \"pageYOffset\"}, function( method, prop ) {\n" \
"	var top = /Y/.test( prop );\n" \
"\n" \
"	jQuery.fn[ method ] = function( val ) {\n" \
"		return jQuery.access( this, function( elem, method, val ) {\n" \
"			var win = getWindow( elem );\n" \
"\n" \
"			if ( val === undefined ) {\n" \
"				return win ? (prop in win) ? win[ prop ] :\n" \
"					win.document.documentElement[ method ] :\n" \
"					elem[ method ];\n" \
"			}\n" \
"\n" \
"			if ( win ) {\n" \
"				win.scrollTo(\n" \
"					!top ? val : jQuery( win ).scrollLeft(),\n" \
"					 top ? val : jQuery( win ).scrollTop()\n" \
"				);\n" \
"\n" \
"			} else {\n" \
"				elem[ method ] = val;\n" \
"			}\n" \
"		}, method, val, arguments.length, null );\n" \
"	};\n" \
"});\n" \
"\n" \
"function getWindow( elem ) {\n" \
"	return jQuery.isWindow( elem ) ?\n" \
"		elem :\n" \
"		elem.nodeType === 9 ?\n" \
"			elem.defaultView || elem.parentWindow :\n" \
"			false;\n" \
"}\n" \
"// Create innerHeight, innerWidth, height, width, outerHeight and outerWidth methods\n" \
"jQuery.each( { Height: \"height\", Width: \"width\" }, function( name, type ) {\n" \
"	jQuery.each( { padding: \"inner\" + name, content: type, \"\": \"outer\" + name }, function( defaultExtra, funcName ) {\n" \
"		// margin is only for outerHeight, outerWidth\n" \
"		jQuery.fn[ funcName ] = function( margin, value ) {\n" \
"			var chainable = arguments.length && ( defaultExtra || typeof margin !== \"boolean\" ),\n" \
"				extra = defaultExtra || ( margin === true || value === true ? \"margin\" : \"border\" );\n" \
"\n" \
"			return jQuery.access( this, function( elem, type, value ) {\n" \
"				var doc;\n" \
"\n" \
"				if ( jQuery.isWindow( elem ) ) {\n" \
"					// As of 5/8/2012 this will yield incorrect results for Mobile Safari, but there\n" \
"					// isn't a whole lot we can do. See pull request at this URL for discussion:\n" \
"					// https://github.com/jquery/jquery/pull/764\n" \
"					return elem.document.documentElement[ \"client\" + name ];\n" \
"				}\n" \
"\n" \
"				// Get document width or height\n" \
"				if ( elem.nodeType === 9 ) {\n" \
"					doc = elem.documentElement;\n" \
"\n" \
"					// Either scroll[Width/Height] or offset[Width/Height] or client[Width/Height], whichever is greatest\n" \
"					// unfortunately, this causes bug #3838 in IE6/8 only, but there is currently no good, small way to fix it.\n" \
"					return Math.max(\n" \
"						elem.body[ \"scroll\" + name ], doc[ \"scroll\" + name ],\n" \
"						elem.body[ \"offset\" + name ], doc[ \"offset\" + name ],\n" \
"						doc[ \"client\" + name ]\n" \
"					);\n" \
"				}\n" \
"\n" \
"				return value === undefined ?\n" \
"					// Get width or height on the element, requesting but not forcing parseFloat\n" \
"					jQuery.css( elem, type, value, extra ) :\n" \
"\n" \
"					// Set width or height on the element\n" \
"					jQuery.style( elem, type, value, extra );\n" \
"			}, type, chainable ? margin : undefined, chainable, null );\n" \
"		};\n" \
"	});\n" \
"});\n" \
"// Expose jQuery to the global object\n" \
"window.jQuery = window.$ = jQuery;\n" \
"\n" \
"// Expose jQuery as an AMD module, but only for AMD loaders that\n" \
"// understand the issues with loading multiple versions of jQuery\n" \
"// in a page that all might call define(). The loader will indicate\n" \
"// they have special allowances for multiple jQuery versions by\n" \
"// specifying define.amd.jQuery = true. Register as a named module,\n" \
"// since jQuery can be concatenated with other files that may use define,\n" \
"// but not use a proper concatenation script that understands anonymous\n" \
"// AMD modules. A named AMD is safest and most robust way to register.\n" \
"// Lowercase jquery is used because AMD module names are derived from\n" \
"// file names, and jQuery is normally delivered in a lowercase file name.\n" \
"// Do this after creating the global so that if an AMD module wants to call\n" \
"// noConflict to hide this version of jQuery, it will work.\n" \
"if ( typeof define === \"function\" && define.amd && define.amd.jQuery ) {\n" \
"	define( \"jquery\", [], function () { return jQuery; } );\n" \
"}\n" \
"\n" \
"})( window );\n" \


#define DATA_LEN_0 "266057"

#define DATA_1  \
"/* Javascript plotting library for jQuery, version 0.8.3.\n" \
"\n" \
"Copyright (c) 2007-2014 IOLA and Ole Laursen.\n" \
"Licensed under the MIT license.\n" \
"\n" \
"*/\n" \
"\n" \
"// first an inline dependency, jquery.colorhelpers.js, we inline it here\n" \
"// for convenience\n" \
"\n" \
"/* Plugin for jQuery for working with colors.\n" \
" *\n" \
" * Version 1.1.\n" \
" *\n" \
" * Inspiration from jQuery color animation plugin by John Resig.\n" \
" *\n" \
" * Released under the MIT license by Ole Laursen, October 2009.\n" \
" *\n" \
" * Examples:\n" \
" *\n" \
" *   $.color.parse(\"#fff\").scale('rgb', 0.25).add('a', -0.5).toString()\n" \
" *   var c = $.color.extract($(\"#mydiv\"), 'background-color');\n" \
" *   console.log(c.r, c.g, c.b, c.a);\n" \
" *   $.color.make(100, 50, 25, 0.4).toString() // returns \"rgba(100,50,25,0.4)\"\n" \
" *\n" \
" * Note that .scale() and .add() return the same modified object\n" \
" * instead of making a new one.\n" \
" *\n" \
" * V. 1.1: Fix error handling so e.g. parsing an empty string does\n" \
" * produce a color rather than just crashing.\n" \
" */\n" \
"(function($){$.color={};$.color.make=function(r,g,b,a){var o={};o.r=r||0;o.g=g||0;o.b=b||0;o.a=a!=null?a:1;o.add=function(c,d){for(var i=0;i<c.length;++i)o[c.charAt(i)]+=d;return o.normalize()};o.scale=function(c,f){for(var i=0;i<c.length;++i)o[c.charAt(i)]*=f;return o.normalize()};o.toString=function(){if(o.a>=1){return\"rgb(\"+[o.r,o.g,o.b].join(\",\")+\")\"}else{return\"rgba(\"+[o.r,o.g,o.b,o.a].join(\",\")+\")\"}};o.normalize=function(){function clamp(min,value,max){return value<min?min:value>max?max:value}o.r=clamp(0,parseInt(o.r),255);o.g=clamp(0,parseInt(o.g),255);o.b=clamp(0,parseInt(o.b),255);o.a=clamp(0,o.a,1);return o};o.clone=function(){return $.color.make(o.r,o.b,o.g,o.a)};return o.normalize()};$.color.extract=function(elem,css){var c;do{c=elem.css(css).toLowerCase();if(c!=\"\"&&c!=\"transparent\")break;elem=elem.parent()}while(elem.length&&!$.nodeName(elem.get(0),\"body\"));if(c==\"rgba(0, 0, 0, 0)\")c=\"transparent\";return $.color.parse(c)};$.color.parse=function(str){var res,m=$.color.make;if(res=/rgb\\(\\s*([0-9]{1,3})\\s*,\\s*([0-9]{1,3})\\s*,\\s*([0-9]{1,3})\\s*\\)/.exec(str))return m(parseInt(res[1],10),parseInt(res[2],10),parseInt(res[3],10));if(res=/rgba\\(\\s*([0-9]{1,3})\\s*,\\s*([0-9]{1,3})\\s*,\\s*([0-9]{1,3})\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\s*\\)/.exec(str))return m(parseInt(res[1],10),parseInt(res[2],10),parseInt(res[3],10),parseFloat(res[4]));if(res=/rgb\\(\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*\\)/.exec(str))return m(parseFloat(res[1])*2.55,parseFloat(res[2])*2.55,parseFloat(res[3])*2.55);if(res=/rgba\\(\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\%\\s*,\\s*([0-9]+(?:\\.[0-9]+)?)\\s*\\)/.exec(str))return m(parseFloat(res[1])*2.55,parseFloat(res[2])*2.55,parseFloat(res[3])*2.55,parseFloat(res[4]));if(res=/#([a-fA-F0-9]{2})([a-fA-F0-9]{2})([a-fA-F0-9]{2})/.exec(str))return m(parseInt(res[1],16),parseInt(res[2],16),parseInt(res[3],16));if(res=/#([a-fA-F0-9])([a-fA-F0-9])([a-fA-F0-9])/.exec(str))return m(parseInt(res[1]+res[1],16),parseInt(res[2]+res[2],16),parseInt(res[3]+res[3],16));var name=$.trim(str).toLowerCase();if(name==\"transparent\")return m(255,255,255,0);else{res=lookupColors[name]||[0,0,0];return m(res[0],res[1],res[2])}};var lookupColors={aqua:[0,255,255],azure:[240,255,255],beige:[245,245,220],black:[0,0,0],blue:[0,0,255],brown:[165,42,42],cyan:[0,255,255],darkblue:[0,0,139],darkcyan:[0,139,139],darkgrey:[169,169,169],darkgreen:[0,100,0],darkkhaki:[189,183,107],darkmagenta:[139,0,139],darkolivegreen:[85,107,47],darkorange:[255,140,0],darkorchid:[153,50,204],darkred:[139,0,0],darksalmon:[233,150,122],darkviolet:[148,0,211],fuchsia:[255,0,255],gold:[255,215,0],green:[0,128,0],indigo:[75,0,130],khaki:[240,230,140],lightblue:[173,216,230],lightcyan:[224,255,255],lightgreen:[144,238,144],lightgrey:[211,211,211],lightpink:[255,182,193],lightyellow:[255,255,224],lime:[0,255,0],magenta:[255,0,255],maroon:[128,0,0],navy:[0,0,128],olive:[128,128,0],orange:[255,165,0],pink:[255,192,203],purple:[128,0,128],violet:[128,0,128],red:[255,0,0],silver:[192,192,192],white:[255,255,255],yellow:[255,255,0]}})(jQuery);\n" \
"\n" \
"// the actual Flot code\n" \
"(function($) {\n" \
"\n" \
"	// Cache the prototype hasOwnProperty for faster access\n" \
"\n" \
"	var hasOwnProperty = Object.prototype.hasOwnProperty;\n" \
"\n" \
"    // A shim to provide 'detach' to jQuery versions prior to 1.4.  Using a DOM\n" \
"    // operation produces the same effect as detach, i.e. removing the element\n" \
"    // without touching its jQuery data.\n" \
"\n" \
"    // Do not merge this into Flot 0.9, since it requires jQuery 1.4.4+.\n" \
"\n" \
"    if (!$.fn.detach) {\n" \
"        $.fn.detach = function() {\n" \
"            return this.each(function() {\n" \
"                if (this.parentNode) {\n" \
"                    this.parentNode.removeChild( this );\n" \
"                }\n" \
"            });\n" \
"        };\n" \
"    }\n" \
"\n" \
"	///////////////////////////////////////////////////////////////////////////\n" \
"	// The Canvas object is a wrapper around an HTML5 <canvas> tag.\n" \
"	//\n" \
"	// @constructor\n" \
"	// @param {string} cls List of classes to apply to the canvas.\n" \
"	// @param {element} container Element onto which to append the canvas.\n" \
"	//\n" \
"	// Requiring a container is a little iffy, but unfortunately canvas\n" \
"	// operations don't work unless the canvas is attached to the DOM.\n" \
"\n" \
"	function Canvas(cls, container) {\n" \
"\n" \
"		var element = container.children(\".\" + cls)[0];\n" \
"\n" \
"		if (element == null) {\n" \
"\n" \
"			element = document.createElement(\"canvas\");\n" \
"			element.className = cls;\n" \
"\n" \
"			$(element).css({ direction: \"ltr\", position: \"absolute\", left: 0, top: 0 })\n" \
"				.appendTo(container);\n" \
"\n" \
"			// If HTML5 Canvas isn't available, fall back to [Ex|Flash]canvas\n" \
"\n" \
"			if (!element.getContext) {\n" \
"				if (window.G_vmlCanvasManager) {\n" \
"					element = window.G_vmlCanvasManager.initElement(element);\n" \
"				} else {\n" \
"					throw new Error(\"Canvas is not available. If you're using IE with a fall-back such as Excanvas, then there's either a mistake in your conditional include, or the page has no DOCTYPE and is rendering in Quirks Mode.\");\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		this.element = element;\n" \
"\n" \
"		var context = this.context = element.getContext(\"2d\");\n" \
"\n" \
"		// Determine the screen's ratio of physical to device-independent\n" \
"		// pixels.  This is the ratio between the canvas width that the browser\n" \
"		// advertises and the number of pixels actually present in that space.\n" \
"\n" \
"		// The iPhone 4, for example, has a device-independent width of 320px,\n" \
"		// but its screen is actually 640px wide.  It therefore has a pixel\n" \
"		// ratio of 2, while most normal devices have a ratio of 1.\n" \
"\n" \
"		var devicePixelRatio = window.devicePixelRatio || 1,\n" \
"			backingStoreRatio =\n" \
"				context.webkitBackingStorePixelRatio ||\n" \
"				context.mozBackingStorePixelRatio ||\n" \
"				context.msBackingStorePixelRatio ||\n" \
"				context.oBackingStorePixelRatio ||\n" \
"				context.backingStorePixelRatio || 1;\n" \
"\n" \
"		this.pixelRatio = devicePixelRatio / backingStoreRatio;\n" \
"\n" \
"		// Size the canvas to match the internal dimensions of its container\n" \
"\n" \
"		this.resize(container.width(), container.height());\n" \
"\n" \
"		// Collection of HTML div layers for text overlaid onto the canvas\n" \
"\n" \
"		this.textContainer = null;\n" \
"		this.text = {};\n" \
"\n" \
"		// Cache of text fragments and metrics, so we can avoid expensively\n" \
"		// re-calculating them when the plot is re-rendered in a loop.\n" \
"\n" \
"		this._textCache = {};\n" \
"	}\n" \
"\n" \
"	// Resizes the canvas to the given dimensions.\n" \
"	//\n" \
"	// @param {number} width New width of the canvas, in pixels.\n" \
"	// @param {number} width New height of the canvas, in pixels.\n" \
"\n" \
"	Canvas.prototype.resize = function(width, height) {\n" \
"\n" \
"		if (width <= 0 || height <= 0) {\n" \
"			throw new Error(\"Invalid dimensions for plot, width = \" + width + \", height = \" + height);\n" \
"		}\n" \
"\n" \
"		var element = this.element,\n" \
"			context = this.context,\n" \
"			pixelRatio = this.pixelRatio;\n" \
"\n" \
"		// Resize the canvas, increasing its density based on the display's\n" \
"		// pixel ratio; basically giving it more pixels without increasing the\n" \
"		// size of its element, to take advantage of the fact that retina\n" \
"		// displays have that many more pixels in the same advertised space.\n" \
"\n" \
"		// Resizing should reset the state (excanvas seems to be buggy though)\n" \
"\n" \
"		if (this.width != width) {\n" \
"			element.width = width * pixelRatio;\n" \
"			element.style.width = width + \"px\";\n" \
"			this.width = width;\n" \
"		}\n" \
"\n" \
"		if (this.height != height) {\n" \
"			element.height = height * pixelRatio;\n" \
"			element.style.height = height + \"px\";\n" \
"			this.height = height;\n" \
"		}\n" \
"\n" \
"		// Save the context, so we can reset in case we get replotted.  The\n" \
"		// restore ensure that we're really back at the initial state, and\n" \
"		// should be safe even if we haven't saved the initial state yet.\n" \
"\n" \
"		context.restore();\n" \
"		context.save();\n" \
"\n" \
"		// Scale the coordinate space to match the display density; so even though we\n" \
"		// may have twice as many pixels, we still want lines and other drawing to\n" \
"		// appear at the same size; the extra pixels will just make them crisper.\n" \
"\n" \
"		context.scale(pixelRatio, pixelRatio);\n" \
"	};\n" \
"\n" \
"	// Clears the entire canvas area, not including any overlaid HTML text\n" \
"\n" \
"	Canvas.prototype.clear = function() {\n" \
"		this.context.clearRect(0, 0, this.width, this.height);\n" \
"	};\n" \
"\n" \
"	// Finishes rendering the canvas, including managing the text overlay.\n" \
"\n" \
"	Canvas.prototype.render = function() {\n" \
"\n" \
"		var cache = this._textCache;\n" \
"\n" \
"		// For each text layer, add elements marked as active that haven't\n" \
"		// already been rendered, and remove those that are no longer active.\n" \
"\n" \
"		for (var layerKey in cache) {\n" \
"			if (hasOwnProperty.call(cache, layerKey)) {\n" \
"\n" \
"				var layer = this.getTextLayer(layerKey),\n" \
"					layerCache = cache[layerKey];\n" \
"\n" \
"				layer.hide();\n" \
"\n" \
"				for (var styleKey in layerCache) {\n" \
"					if (hasOwnProperty.call(layerCache, styleKey)) {\n" \
"						var styleCache = layerCache[styleKey];\n" \
"						for (var key in styleCache) {\n" \
"							if (hasOwnProperty.call(styleCache, key)) {\n" \
"\n" \
"								var positions = styleCache[key].positions;\n" \
"\n" \
"								for (var i = 0, position; position = positions[i]; i++) {\n" \
"									if (position.active) {\n" \
"										if (!position.rendered) {\n" \
"											layer.append(position.element);\n" \
"											position.rendered = true;\n" \
"										}\n" \
"									} else {\n" \
"										positions.splice(i--, 1);\n" \
"										if (position.rendered) {\n" \
"											position.element.detach();\n" \
"										}\n" \
"									}\n" \
"								}\n" \
"\n" \
"								if (positions.length == 0) {\n" \
"									delete styleCache[key];\n" \
"								}\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"\n" \
"				layer.show();\n" \
"			}\n" \
"		}\n" \
"	};\n" \
"\n" \
"	// Creates (if necessary) and returns the text overlay container.\n" \
"	//\n" \
"	// @param {string} classes String of space-separated CSS classes used to\n" \
"	//     uniquely identify the text layer.\n" \
"	// @return {object} The jQuery-wrapped text-layer div.\n" \
"\n" \
"	Canvas.prototype.getTextLayer = function(classes) {\n" \
"\n" \
"		var layer = this.text[classes];\n" \
"\n" \
"		// Create the text layer if it doesn't exist\n" \
"\n" \
"		if (layer == null) {\n" \
"\n" \
"			// Create the text layer container, if it doesn't exist\n" \
"\n" \
"			if (this.textContainer == null) {\n" \
"				this.textContainer = $(\"<div class='flot-text'></div>\")\n" \
"					.css({\n" \
"						position: \"absolute\",\n" \
"						top: 0,\n" \
"						left: 0,\n" \
"						bottom: 0,\n" \
"						right: 0,\n" \
"						'font-size': \"smaller\",\n" \
"						color: \"#545454\"\n" \
"					})\n" \
"					.insertAfter(this.element);\n" \
"			}\n" \
"\n" \
"			layer = this.text[classes] = $(\"<div></div>\")\n" \
"				.addClass(classes)\n" \
"				.css({\n" \
"					position: \"absolute\",\n" \
"					top: 0,\n" \
"					left: 0,\n" \
"					bottom: 0,\n" \
"					right: 0\n" \
"				})\n" \
"				.appendTo(this.textContainer);\n" \
"		}\n" \
"\n" \
"		return layer;\n" \
"	};\n" \
"\n" \
"	// Creates (if necessary) and returns a text info object.\n" \
"	//\n" \
"	// The object looks like this:\n" \
"	//\n" \
"	// {\n" \
"	//     width: Width of the text's wrapper div.\n" \
"	//     height: Height of the text's wrapper div.\n" \
"	//     element: The jQuery-wrapped HTML div containing the text.\n" \
"	//     positions: Array of positions at which this text is drawn.\n" \
"	// }\n" \
"	//\n" \
"	// The positions array contains objects that look like this:\n" \
"	//\n" \
"	// {\n" \
"	//     active: Flag indicating whether the text should be visible.\n" \
"	//     rendered: Flag indicating whether the text is currently visible.\n" \
"	//     element: The jQuery-wrapped HTML div containing the text.\n" \
"	//     x: X coordinate at which to draw the text.\n" \
"	//     y: Y coordinate at which to draw the text.\n" \
"	// }\n" \
"	//\n" \
"	// Each position after the first receives a clone of the original element.\n" \
"	//\n" \
"	// The idea is that that the width, height, and general 'identity' of the\n" \
"	// text is constant no matter where it is placed; the placements are a\n" \
"	// secondary property.\n" \
"	//\n" \
"	// Canvas maintains a cache of recently-used text info objects; getTextInfo\n" \
"	// either returns the cached element or creates a new entry.\n" \
"	//\n" \
"	// @param {string} layer A string of space-separated CSS classes uniquely\n" \
"	//     identifying the layer containing this text.\n" \
"	// @param {string} text Text string to retrieve info for.\n" \
"	// @param {(string|object)=} font Either a string of space-separated CSS\n" \
"	//     classes or a font-spec object, defining the text's font and style.\n" \
"	// @param {number=} angle Angle at which to rotate the text, in degrees.\n" \
"	//     Angle is currently unused, it will be implemented in the future.\n" \
"	// @param {number=} width Maximum width of the text before it wraps.\n" \
"	// @return {object} a text info object.\n" \
"\n" \
"	Canvas.prototype.getTextInfo = function(layer, text, font, angle, width) {\n" \
"\n" \
"		var textStyle, layerCache, styleCache, info;\n" \
"\n" \
"		// Cast the value to a string, in case we were given a number or such\n" \
"\n" \
"		text = \"\" + text;\n" \
"\n" \
"		// If the font is a font-spec object, generate a CSS font definition\n" \
"\n" \
"		if (typeof font === \"object\") {\n" \
"			textStyle = font.style + \" \" + font.variant + \" \" + font.weight + \" \" + font.size + \"px/\" + font.lineHeight + \"px \" + font.family;\n" \
"		} else {\n" \
"			textStyle = font;\n" \
"		}\n" \
"\n" \
"		// Retrieve (or create) the cache for the text's layer and styles\n" \
"\n" \
"		layerCache = this._textCache[layer];\n" \
"\n" \
"		if (layerCache == null) {\n" \
"			layerCache = this._textCache[layer] = {};\n" \
"		}\n" \
"\n" \
"		styleCache = layerCache[textStyle];\n" \
"\n" \
"		if (styleCache == null) {\n" \
"			styleCache = layerCache[textStyle] = {};\n" \
"		}\n" \
"\n" \
"		info = styleCache[text];\n" \
"\n" \
"		// If we can't find a matching element in our cache, create a new one\n" \
"\n" \
"		if (info == null) {\n" \
"\n" \
"			var element = $(\"<div></div>\").html(text)\n" \
"				.css({\n" \
"					position: \"absolute\",\n" \
"					'max-width': width,\n" \
"					top: -9999\n" \
"				})\n" \
"				.appendTo(this.getTextLayer(layer));\n" \
"\n" \
"			if (typeof font === \"object\") {\n" \
"				element.css({\n" \
"					font: textStyle,\n" \
"					color: font.color\n" \
"				});\n" \
"			} else if (typeof font === \"string\") {\n" \
"				element.addClass(font);\n" \
"			}\n" \
"\n" \
"			info = styleCache[text] = {\n" \
"				width: element.outerWidth(true),\n" \
"				height: element.outerHeight(true),\n" \
"				element: element,\n" \
"				positions: []\n" \
"			};\n" \
"\n" \
"			element.detach();\n" \
"		}\n" \
"\n" \
"		return info;\n" \
"	};\n" \
"\n" \
"	// Adds a text string to the canvas text overlay.\n" \
"	//\n" \
"	// The text isn't drawn immediately; it is marked as rendering, which will\n" \
"	// result in its addition to the canvas on the next render pass.\n" \
"	//\n" \
"	// @param {string} layer A string of space-separated CSS classes uniquely\n" \
"	//     identifying the layer containing this text.\n" \
"	// @param {number} x X coordinate at which to draw the text.\n" \
"	// @param {number} y Y coordinate at which to draw the text.\n" \
"	// @param {string} text Text string to draw.\n" \
"	// @param {(string|object)=} font Either a string of space-separated CSS\n" \
"	//     classes or a font-spec object, defining the text's font and style.\n" \
"	// @param {number=} angle Angle at which to rotate the text, in degrees.\n" \
"	//     Angle is currently unused, it will be implemented in the future.\n" \
"	// @param {number=} width Maximum width of the text before it wraps.\n" \
"	// @param {string=} halign Horizontal alignment of the text; either \"left\",\n" \
"	//     \"center\" or \"right\".\n" \
"	// @param {string=} valign Vertical alignment of the text; either \"top\",\n" \
"	//     \"middle\" or \"bottom\".\n" \
"\n" \
"	Canvas.prototype.addText = function(layer, x, y, text, font, angle, width, halign, valign) {\n" \
"\n" \
"		var info = this.getTextInfo(layer, text, font, angle, width),\n" \
"			positions = info.positions;\n" \
"\n" \
"		// Tweak the div's position to match the text's alignment\n" \
"\n" \
"		if (halign == \"center\") {\n" \
"			x -= info.width / 2;\n" \
"		} else if (halign == \"right\") {\n" \
"			x -= info.width;\n" \
"		}\n" \
"\n" \
"		if (valign == \"middle\") {\n" \
"			y -= info.height / 2;\n" \
"		} else if (valign == \"bottom\") {\n" \
"			y -= info.height;\n" \
"		}\n" \
"\n" \
"		// Determine whether this text already exists at this position.\n" \
"		// If so, mark it for inclusion in the next render pass.\n" \
"\n" \
"		for (var i = 0, position; position = positions[i]; i++) {\n" \
"			if (position.x == x && position.y == y) {\n" \
"				position.active = true;\n" \
"				return;\n" \
"			}\n" \
"		}\n" \
"\n" \
"		// If the text doesn't exist at this position, create a new entry\n" \
"\n" \
"		// For the very first position we'll re-use the original element,\n" \
"		// while for subsequent ones we'll clone it.\n" \
"\n" \
"		position = {\n" \
"			active: true,\n" \
"			rendered: false,\n" \
"			element: positions.length ? info.element.clone() : info.element,\n" \
"			x: x,\n" \
"			y: y\n" \
"		};\n" \
"\n" \
"		positions.push(position);\n" \
"\n" \
"		// Move the element to its final position within the container\n" \
"\n" \
"		position.element.css({\n" \
"			top: Math.round(y),\n" \
"			left: Math.round(x),\n" \
"			'text-align': halign	// In case the text wraps\n" \
"		});\n" \
"	};\n" \
"\n" \
"	// Removes one or more text strings from the canvas text overlay.\n" \
"	//\n" \
"	// If no parameters are given, all text within the layer is removed.\n" \
"	//\n" \
"	// Note that the text is not immediately removed; it is simply marked as\n" \
"	// inactive, which will result in its removal on the next render pass.\n" \
"	// This avoids the performance penalty for 'clear and redraw' behavior,\n" \
"	// where we potentially get rid of all text on a layer, but will likely\n" \
"	// add back most or all of it later, as when redrawing axes, for example.\n" \
"	//\n" \
"	// @param {string} layer A string of space-separated CSS classes uniquely\n" \
"	//     identifying the layer containing this text.\n" \
"	// @param {number=} x X coordinate of the text.\n" \
"	// @param {number=} y Y coordinate of the text.\n" \
"	// @param {string=} text Text string to remove.\n" \
"	// @param {(string|object)=} font Either a string of space-separated CSS\n" \
"	//     classes or a font-spec object, defining the text's font and style.\n" \
"	// @param {number=} angle Angle at which the text is rotated, in degrees.\n" \
"	//     Angle is currently unused, it will be implemented in the future.\n" \
"\n" \
"	Canvas.prototype.removeText = function(layer, x, y, text, font, angle) {\n" \
"		if (text == null) {\n" \
"			var layerCache = this._textCache[layer];\n" \
"			if (layerCache != null) {\n" \
"				for (var styleKey in layerCache) {\n" \
"					if (hasOwnProperty.call(layerCache, styleKey)) {\n" \
"						var styleCache = layerCache[styleKey];\n" \
"						for (var key in styleCache) {\n" \
"							if (hasOwnProperty.call(styleCache, key)) {\n" \
"								var positions = styleCache[key].positions;\n" \
"								for (var i = 0, position; position = positions[i]; i++) {\n" \
"									position.active = false;\n" \
"								}\n" \
"							}\n" \
"						}\n" \
"					}\n" \
"				}\n" \
"			}\n" \
"		} else {\n" \
"			var positions = this.getTextInfo(layer, text, font, angle).positions;\n" \
"			for (var i = 0, position; position = positions[i]; i++) {\n" \
"				if (position.x == x && position.y == y) {\n" \
"					position.active = false;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"	};\n" \
"\n" \
"	///////////////////////////////////////////////////////////////////////////\n" \
"	// The top-level container for the entire plot.\n" \
"\n" \
"    function Plot(placeholder, data_, options_, plugins) {\n" \
"        // data is on the form:\n" \
"        //   [ series1, series2 ... ]\n" \
"        // where series is either just the data as [ [x1, y1], [x2, y2], ... ]\n" \
"        // or { data: [ [x1, y1], [x2, y2], ... ], label: \"some label\", ... }\n" \
"\n" \
"        var series = [],\n" \
"            options = {\n" \
"                // the color theme used for graphs\n" \
"                colors: [\"#edc240\", \"#afd8f8\", \"#cb4b4b\", \"#4da74d\", \"#9440ed\"],\n" \
"                legend: {\n" \
"                    show: true,\n" \
"                    noColumns: 1, // number of colums in legend table\n" \
"                    labelFormatter: null, // fn: string -> string\n" \
"                    labelBoxBorderColor: \"#ccc\", // border color for the little label boxes\n" \
"                    container: null, // container (as jQuery object) to put legend in, null means default on top of graph\n" \
"                    position: \"ne\", // position of default legend container within plot\n" \
"                    margin: 5, // distance from grid edge to default legend container within plot\n" \
"                    backgroundColor: null, // null means auto-detect\n" \
"                    backgroundOpacity: 0.85, // set to 0 to avoid background\n" \
"                    sorted: null    // default to no legend sorting\n" \
"                },\n" \
"                xaxis: {\n" \
"                    show: null, // null = auto-detect, true = always, false = never\n" \
"                    position: \"bottom\", // or \"top\"\n" \
"                    mode: null, // null or \"time\"\n" \
"                    font: null, // null (derived from CSS in placeholder) or object like { size: 11, lineHeight: 13, style: \"italic\", weight: \"bold\", family: \"sans-serif\", variant: \"small-caps\" }\n" \
"                    color: null, // base color, labels, ticks\n" \
"                    tickColor: null, // possibly different color of ticks, e.g. \"rgba(0,0,0,0.15)\"\n" \
"                    transform: null, // null or f: number -> number to transform axis\n" \
"                    inverseTransform: null, // if transform is set, this should be the inverse function\n" \
"                    min: null, // min. value to show, null means set automatically\n" \
"                    max: null, // max. value to show, null means set automatically\n" \
"                    autoscaleMargin: null, // margin in % to add if auto-setting min/max\n" \
"                    ticks: null, // either [1, 3] or [[1, \"a\"], 3] or (fn: axis info -> ticks) or app. number of ticks for auto-ticks\n" \
"                    tickFormatter: null, // fn: number -> string\n" \
"                    labelWidth: null, // size of tick labels in pixels\n" \
"                    labelHeight: null,\n" \
"                    reserveSpace: null, // whether to reserve space even if axis isn't shown\n" \
"                    tickLength: null, // size in pixels of ticks, or \"full\" for whole line\n" \
"                    alignTicksWithAxis: null, // axis number or null for no sync\n" \
"                    tickDecimals: null, // no. of decimals, null means auto\n" \
"                    tickSize: null, // number or [number, \"unit\"]\n" \
"                    minTickSize: null // number or [number, \"unit\"]\n" \
"                },\n" \
"                yaxis: {\n" \
"                    autoscaleMargin: 0.02,\n" \
"                    position: \"left\" // or \"right\"\n" \
"                },\n" \
"                xaxes: [],\n" \
"                yaxes: [],\n" \
"                series: {\n" \
"                    points: {\n" \
"                        show: false,\n" \
"                        radius: 3,\n" \
"                        lineWidth: 2, // in pixels\n" \
"                        fill: true,\n" \
"                        fillColor: \"#ffffff\",\n" \
"                        symbol: \"circle\" // or callback\n" \
"                    },\n" \
"                    lines: {\n" \
"                        // we don't put in show: false so we can see\n" \
"                        // whether lines were actively disabled\n" \
"                        lineWidth: 2, // in pixels\n" \
"                        fill: false,\n" \
"                        fillColor: null,\n" \
"                        steps: false\n" \
"                        // Omit 'zero', so we can later default its value to\n" \
"                        // match that of the 'fill' option.\n" \
"                    },\n" \
"                    bars: {\n" \
"                        show: false,\n" \
"                        lineWidth: 2, // in pixels\n" \
"                        barWidth: 1, // in units of the x axis\n" \
"                        fill: true,\n" \
"                        fillColor: null,\n" \
"                        align: \"left\", // \"left\", \"right\", or \"center\"\n" \
"                        horizontal: false,\n" \
"                        zero: true\n" \
"                    },\n" \
"                    shadowSize: 3,\n" \
"                    highlightColor: null\n" \
"                },\n" \
"                grid: {\n" \
"                    show: true,\n" \
"                    aboveData: false,\n" \
"                    color: \"#545454\", // primary color used for outline and labels\n" \
"                    backgroundColor: null, // null for transparent, else color\n" \
"                    borderColor: null, // set if different from the grid color\n" \
"                    tickColor: null, // color for the ticks, e.g. \"rgba(0,0,0,0.15)\"\n" \
"                    margin: 0, // distance from the canvas edge to the grid\n" \
"                    labelMargin: 5, // in pixels\n" \
"                    axisMargin: 8, // in pixels\n" \
"                    borderWidth: 2, // in pixels\n" \
"                    minBorderMargin: null, // in pixels, null means taken from points radius\n" \
"                    markings: null, // array of ranges or fn: axes -> array of ranges\n" \
"                    markingsColor: \"#f4f4f4\",\n" \
"                    markingsLineWidth: 2,\n" \
"                    // interactive stuff\n" \
"                    clickable: false,\n" \
"                    hoverable: false,\n" \
"                    autoHighlight: true, // highlight in case mouse is near\n" \
"                    mouseActiveRadius: 10 // how far the mouse can be away to activate an item\n" \
"                },\n" \
"                interaction: {\n" \
"                    redrawOverlayInterval: 1000/60 // time between updates, -1 means in same flow\n" \
"                },\n" \
"                hooks: {}\n" \
"            },\n" \
"        surface = null,     // the canvas for the plot itself\n" \
"        overlay = null,     // canvas for interactive stuff on top of plot\n" \
"        eventHolder = null, // jQuery object that events should be bound to\n" \
"        ctx = null, octx = null,\n" \
"        xaxes = [], yaxes = [],\n" \
"        plotOffset = { left: 0, right: 0, top: 0, bottom: 0},\n" \
"        plotWidth = 0, plotHeight = 0,\n" \
"        hooks = {\n" \
"            processOptions: [],\n" \
"            processRawData: [],\n" \
"            processDatapoints: [],\n" \
"            processOffset: [],\n" \
"            drawBackground: [],\n" \
"            drawSeries: [],\n" \
"            draw: [],\n" \
"            bindEvents: [],\n" \
"            drawOverlay: [],\n" \
"            shutdown: []\n" \
"        },\n" \
"        plot = this;\n" \
"\n" \
"        // public functions\n" \
"        plot.setData = setData;\n" \
"        plot.setupGrid = setupGrid;\n" \
"        plot.draw = draw;\n" \
"        plot.getPlaceholder = function() { return placeholder; };\n" \
"        plot.getCanvas = function() { return surface.element; };\n" \
"        plot.getPlotOffset = function() { return plotOffset; };\n" \
"        plot.width = function () { return plotWidth; };\n" \
"        plot.height = function () { return plotHeight; };\n" \
"        plot.offset = function () {\n" \
"            var o = eventHolder.offset();\n" \
"            o.left += plotOffset.left;\n" \
"            o.top += plotOffset.top;\n" \
"            return o;\n" \
"        };\n" \
"        plot.getData = function () { return series; };\n" \
"        plot.getAxes = function () {\n" \
"            var res = {}, i;\n" \
"            $.each(xaxes.concat(yaxes), function (_, axis) {\n" \
"                if (axis)\n" \
"                    res[axis.direction + (axis.n != 1 ? axis.n : \"\") + \"axis\"] = axis;\n" \
"            });\n" \
"            return res;\n" \
"        };\n" \
"        plot.getXAxes = function () { return xaxes; };\n" \
"        plot.getYAxes = function () { return yaxes; };\n" \
"        plot.c2p = canvasToAxisCoords;\n" \
"        plot.p2c = axisToCanvasCoords;\n" \
"        plot.getOptions = function () { return options; };\n" \
"        plot.highlight = highlight;\n" \
"        plot.unhighlight = unhighlight;\n" \
"        plot.triggerRedrawOverlay = triggerRedrawOverlay;\n" \
"        plot.pointOffset = function(point) {\n" \
"            return {\n" \
"                left: parseInt(xaxes[axisNumber(point, \"x\") - 1].p2c(+point.x) + plotOffset.left, 10),\n" \
"                top: parseInt(yaxes[axisNumber(point, \"y\") - 1].p2c(+point.y) + plotOffset.top, 10)\n" \
"            };\n" \
"        };\n" \
"        plot.shutdown = shutdown;\n" \
"        plot.destroy = function () {\n" \
"            shutdown();\n" \
"            placeholder.removeData(\"plot\").empty();\n" \
"\n" \
"            series = [];\n" \
"            options = null;\n" \
"            surface = null;\n" \
"            overlay = null;\n" \
"            eventHolder = null;\n" \
"            ctx = null;\n" \
"            octx = null;\n" \
"            xaxes = [];\n" \
"            yaxes = [];\n" \
"            hooks = null;\n" \
"            highlights = [];\n" \
"            plot = null;\n" \
"        };\n" \
"        plot.resize = function () {\n" \
"        	var width = placeholder.width(),\n" \
"        		height = placeholder.height();\n" \
"            surface.resize(width, height);\n" \
"            overlay.resize(width, height);\n" \
"        };\n" \
"\n" \
"        // public attributes\n" \
"        plot.hooks = hooks;\n" \
"\n" \
"        // initialize\n" \
"        initPlugins(plot);\n" \
"        parseOptions(options_);\n" \
"        setupCanvases();\n" \
"        setData(data_);\n" \
"        setupGrid();\n" \
"        draw();\n" \
"        bindEvents();\n" \
"\n" \
"\n" \
"        function executeHooks(hook, args) {\n" \
"            args = [plot].concat(args);\n" \
"            for (var i = 0; i < hook.length; ++i)\n" \
"                hook[i].apply(this, args);\n" \
"        }\n" \
"\n" \
"        function initPlugins() {\n" \
"\n" \
"            // References to key classes, allowing plugins to modify them\n" \
"\n" \
"            var classes = {\n" \
"                Canvas: Canvas\n" \
"            };\n" \
"\n" \
"            for (var i = 0; i < plugins.length; ++i) {\n" \
"                var p = plugins[i];\n" \
"                p.init(plot, classes);\n" \
"                if (p.options)\n" \
"                    $.extend(true, options, p.options);\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function parseOptions(opts) {\n" \
"\n" \
"            $.extend(true, options, opts);\n" \
"\n" \
"            // $.extend merges arrays, rather than replacing them.  When less\n" \
"            // colors are provided than the size of the default palette, we\n" \
"            // end up with those colors plus the remaining defaults, which is\n" \
"            // not expected behavior; avoid it by replacing them here.\n" \
"\n" \
"            if (opts && opts.colors) {\n" \
"            	options.colors = opts.colors;\n" \
"            }\n" \
"\n" \
"            if (options.xaxis.color == null)\n" \
"                options.xaxis.color = $.color.parse(options.grid.color).scale('a', 0.22).toString();\n" \
"            if (options.yaxis.color == null)\n" \
"                options.yaxis.color = $.color.parse(options.grid.color).scale('a', 0.22).toString();\n" \
"\n" \
"            if (options.xaxis.tickColor == null) // grid.tickColor for back-compatibility\n" \
"                options.xaxis.tickColor = options.grid.tickColor || options.xaxis.color;\n" \
"            if (options.yaxis.tickColor == null) // grid.tickColor for back-compatibility\n" \
"                options.yaxis.tickColor = options.grid.tickColor || options.yaxis.color;\n" \
"\n" \
"            if (options.grid.borderColor == null)\n" \
"                options.grid.borderColor = options.grid.color;\n" \
"            if (options.grid.tickColor == null)\n" \
"                options.grid.tickColor = $.color.parse(options.grid.color).scale('a', 0.22).toString();\n" \
"\n" \
"            // Fill in defaults for axis options, including any unspecified\n" \
"            // font-spec fields, if a font-spec was provided.\n" \
"\n" \
"            // If no x/y axis options were provided, create one of each anyway,\n" \
"            // since the rest of the code assumes that they exist.\n" \
"\n" \
"            var i, axisOptions, axisCount,\n" \
"                fontSize = placeholder.css(\"font-size\"),\n" \
"                fontSizeDefault = fontSize ? +fontSize.replace(\"px\", \"\") : 13,\n" \
"                fontDefaults = {\n" \
"                    style: placeholder.css(\"font-style\"),\n" \
"                    size: Math.round(0.8 * fontSizeDefault),\n" \
"                    variant: placeholder.css(\"font-variant\"),\n" \
"                    weight: placeholder.css(\"font-weight\"),\n" \
"                    family: placeholder.css(\"font-family\")\n" \
"                };\n" \
"\n" \
"            axisCount = options.xaxes.length || 1;\n" \
"            for (i = 0; i < axisCount; ++i) {\n" \
"\n" \
"                axisOptions = options.xaxes[i];\n" \
"                if (axisOptions && !axisOptions.tickColor) {\n" \
"                    axisOptions.tickColor = axisOptions.color;\n" \
"                }\n" \
"\n" \
"                axisOptions = $.extend(true, {}, options.xaxis, axisOptions);\n" \
"                options.xaxes[i] = axisOptions;\n" \
"\n" \
"                if (axisOptions.font) {\n" \
"                    axisOptions.font = $.extend({}, fontDefaults, axisOptions.font);\n" \
"                    if (!axisOptions.font.color) {\n" \
"                        axisOptions.font.color = axisOptions.color;\n" \
"                    }\n" \
"                    if (!axisOptions.font.lineHeight) {\n" \
"                        axisOptions.font.lineHeight = Math.round(axisOptions.font.size * 1.15);\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            axisCount = options.yaxes.length || 1;\n" \
"            for (i = 0; i < axisCount; ++i) {\n" \
"\n" \
"                axisOptions = options.yaxes[i];\n" \
"                if (axisOptions && !axisOptions.tickColor) {\n" \
"                    axisOptions.tickColor = axisOptions.color;\n" \
"                }\n" \
"\n" \
"                axisOptions = $.extend(true, {}, options.yaxis, axisOptions);\n" \
"                options.yaxes[i] = axisOptions;\n" \
"\n" \
"                if (axisOptions.font) {\n" \
"                    axisOptions.font = $.extend({}, fontDefaults, axisOptions.font);\n" \
"                    if (!axisOptions.font.color) {\n" \
"                        axisOptions.font.color = axisOptions.color;\n" \
"                    }\n" \
"                    if (!axisOptions.font.lineHeight) {\n" \
"                        axisOptions.font.lineHeight = Math.round(axisOptions.font.size * 1.15);\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // backwards compatibility, to be removed in future\n" \
"            if (options.xaxis.noTicks && options.xaxis.ticks == null)\n" \
"                options.xaxis.ticks = options.xaxis.noTicks;\n" \
"            if (options.yaxis.noTicks && options.yaxis.ticks == null)\n" \
"                options.yaxis.ticks = options.yaxis.noTicks;\n" \
"            if (options.x2axis) {\n" \
"                options.xaxes[1] = $.extend(true, {}, options.xaxis, options.x2axis);\n" \
"                options.xaxes[1].position = \"top\";\n" \
"                // Override the inherit to allow the axis to auto-scale\n" \
"                if (options.x2axis.min == null) {\n" \
"                    options.xaxes[1].min = null;\n" \
"                }\n" \
"                if (options.x2axis.max == null) {\n" \
"                    options.xaxes[1].max = null;\n" \
"                }\n" \
"            }\n" \
"            if (options.y2axis) {\n" \
"                options.yaxes[1] = $.extend(true, {}, options.yaxis, options.y2axis);\n" \
"                options.yaxes[1].position = \"right\";\n" \
"                // Override the inherit to allow the axis to auto-scale\n" \
"                if (options.y2axis.min == null) {\n" \
"                    options.yaxes[1].min = null;\n" \
"                }\n" \
"                if (options.y2axis.max == null) {\n" \
"                    options.yaxes[1].max = null;\n" \
"                }\n" \
"            }\n" \
"            if (options.grid.coloredAreas)\n" \
"                options.grid.markings = options.grid.coloredAreas;\n" \
"            if (options.grid.coloredAreasColor)\n" \
"                options.grid.markingsColor = options.grid.coloredAreasColor;\n" \
"            if (options.lines)\n" \
"                $.extend(true, options.series.lines, options.lines);\n" \
"            if (options.points)\n" \
"                $.extend(true, options.series.points, options.points);\n" \
"            if (options.bars)\n" \
"                $.extend(true, options.series.bars, options.bars);\n" \
"            if (options.shadowSize != null)\n" \
"                options.series.shadowSize = options.shadowSize;\n" \
"            if (options.highlightColor != null)\n" \
"                options.series.highlightColor = options.highlightColor;\n" \
"\n" \
"            // save options on axes for future reference\n" \
"            for (i = 0; i < options.xaxes.length; ++i)\n" \
"                getOrCreateAxis(xaxes, i + 1).options = options.xaxes[i];\n" \
"            for (i = 0; i < options.yaxes.length; ++i)\n" \
"                getOrCreateAxis(yaxes, i + 1).options = options.yaxes[i];\n" \
"\n" \
"            // add hooks from options\n" \
"            for (var n in hooks)\n" \
"                if (options.hooks[n] && options.hooks[n].length)\n" \
"                    hooks[n] = hooks[n].concat(options.hooks[n]);\n" \
"\n" \
"            executeHooks(hooks.processOptions, [options]);\n" \
"        }\n" \
"\n" \
"        function setData(d) {\n" \
"            series = parseData(d);\n" \
"            fillInSeriesOptions();\n" \
"            processData();\n" \
"        }\n" \
"\n" \
"        function parseData(d) {\n" \
"            var res = [];\n" \
"            for (var i = 0; i < d.length; ++i) {\n" \
"                var s = $.extend(true, {}, options.series);\n" \
"\n" \
"                if (d[i].data != null) {\n" \
"                    s.data = d[i].data; // move the data instead of deep-copy\n" \
"                    delete d[i].data;\n" \
"\n" \
"                    $.extend(true, s, d[i]);\n" \
"\n" \
"                    d[i].data = s.data;\n" \
"                }\n" \
"                else\n" \
"                    s.data = d[i];\n" \
"                res.push(s);\n" \
"            }\n" \
"\n" \
"            return res;\n" \
"        }\n" \
"\n" \
"        function axisNumber(obj, coord) {\n" \
"            var a = obj[coord + \"axis\"];\n" \
"            if (typeof a == \"object\") // if we got a real axis, extract number\n" \
"                a = a.n;\n" \
"            if (typeof a != \"number\")\n" \
"                a = 1; // default to first axis\n" \
"            return a;\n" \
"        }\n" \
"\n" \
"        function allAxes() {\n" \
"            // return flat array without annoying null entries\n" \
"            return $.grep(xaxes.concat(yaxes), function (a) { return a; });\n" \
"        }\n" \
"\n" \
"        function canvasToAxisCoords(pos) {\n" \
"            // return an object with x/y corresponding to all used axes\n" \
"            var res = {}, i, axis;\n" \
"            for (i = 0; i < xaxes.length; ++i) {\n" \
"                axis = xaxes[i];\n" \
"                if (axis && axis.used)\n" \
"                    res[\"x\" + axis.n] = axis.c2p(pos.left);\n" \
"            }\n" \
"\n" \
"            for (i = 0; i < yaxes.length; ++i) {\n" \
"                axis = yaxes[i];\n" \
"                if (axis && axis.used)\n" \
"                    res[\"y\" + axis.n] = axis.c2p(pos.top);\n" \
"            }\n" \
"\n" \
"            if (res.x1 !== undefined)\n" \
"                res.x = res.x1;\n" \
"            if (res.y1 !== undefined)\n" \
"                res.y = res.y1;\n" \
"\n" \
"            return res;\n" \
"        }\n" \
"\n" \
"        function axisToCanvasCoords(pos) {\n" \
"            // get canvas coords from the first pair of x/y found in pos\n" \
"            var res = {}, i, axis, key;\n" \
"\n" \
"            for (i = 0; i < xaxes.length; ++i) {\n" \
"                axis = xaxes[i];\n" \
"                if (axis && axis.used) {\n" \
"                    key = \"x\" + axis.n;\n" \
"                    if (pos[key] == null && axis.n == 1)\n" \
"                        key = \"x\";\n" \
"\n" \
"                    if (pos[key] != null) {\n" \
"                        res.left = axis.p2c(pos[key]);\n" \
"                        break;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            for (i = 0; i < yaxes.length; ++i) {\n" \
"                axis = yaxes[i];\n" \
"                if (axis && axis.used) {\n" \
"                    key = \"y\" + axis.n;\n" \
"                    if (pos[key] == null && axis.n == 1)\n" \
"                        key = \"y\";\n" \
"\n" \
"                    if (pos[key] != null) {\n" \
"                        res.top = axis.p2c(pos[key]);\n" \
"                        break;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            return res;\n" \
"        }\n" \
"\n" \
"        function getOrCreateAxis(axes, number) {\n" \
"            if (!axes[number - 1])\n" \
"                axes[number - 1] = {\n" \
"                    n: number, // save the number for future reference\n" \
"                    direction: axes == xaxes ? \"x\" : \"y\",\n" \
"                    options: $.extend(true, {}, axes == xaxes ? options.xaxis : options.yaxis)\n" \
"                };\n" \
"\n" \
"            return axes[number - 1];\n" \
"        }\n" \
"\n" \
"        function fillInSeriesOptions() {\n" \
"\n" \
"            var neededColors = series.length, maxIndex = -1, i;\n" \
"\n" \
"            // Subtract the number of series that already have fixed colors or\n" \
"            // color indexes from the number that we still need to generate.\n" \
"\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                var sc = series[i].color;\n" \
"                if (sc != null) {\n" \
"                    neededColors--;\n" \
"                    if (typeof sc == \"number\" && sc > maxIndex) {\n" \
"                        maxIndex = sc;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // If any of the series have fixed color indexes, then we need to\n" \
"            // generate at least as many colors as the highest index.\n" \
"\n" \
"            if (neededColors <= maxIndex) {\n" \
"                neededColors = maxIndex + 1;\n" \
"            }\n" \
"\n" \
"            // Generate all the colors, using first the option colors and then\n" \
"            // variations on those colors once they're exhausted.\n" \
"\n" \
"            var c, colors = [], colorPool = options.colors,\n" \
"                colorPoolSize = colorPool.length, variation = 0;\n" \
"\n" \
"            for (i = 0; i < neededColors; i++) {\n" \
"\n" \
"                c = $.color.parse(colorPool[i % colorPoolSize] || \"#666\");\n" \
"\n" \
"                // Each time we exhaust the colors in the pool we adjust\n" \
"                // a scaling factor used to produce more variations on\n" \
"                // those colors. The factor alternates negative/positive\n" \
"                // to produce lighter/darker colors.\n" \
"\n" \
"                // Reset the variation after every few cycles, or else\n" \
"                // it will end up producing only white or black colors.\n" \
"\n" \
"                if (i % colorPoolSize == 0 && i) {\n" \
"                    if (variation >= 0) {\n" \
"                        if (variation < 0.5) {\n" \
"                            variation = -variation - 0.2;\n" \
"                        } else variation = 0;\n" \
"                    } else variation = -variation;\n" \
"                }\n" \
"\n" \
"                colors[i] = c.scale('rgb', 1 + variation);\n" \
"            }\n" \
"\n" \
"            // Finalize the series options, filling in their colors\n" \
"\n" \
"            var colori = 0, s;\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"\n" \
"                // assign colors\n" \
"                if (s.color == null) {\n" \
"                    s.color = colors[colori].toString();\n" \
"                    ++colori;\n" \
"                }\n" \
"                else if (typeof s.color == \"number\")\n" \
"                    s.color = colors[s.color].toString();\n" \
"\n" \
"                // turn on lines automatically in case nothing is set\n" \
"                if (s.lines.show == null) {\n" \
"                    var v, show = true;\n" \
"                    for (v in s)\n" \
"                        if (s[v] && s[v].show) {\n" \
"                            show = false;\n" \
"                            break;\n" \
"                        }\n" \
"                    if (show)\n" \
"                        s.lines.show = true;\n" \
"                }\n" \
"\n" \
"                // If nothing was provided for lines.zero, default it to match\n" \
"                // lines.fill, since areas by default should extend to zero.\n" \
"\n" \
"                if (s.lines.zero == null) {\n" \
"                    s.lines.zero = !!s.lines.fill;\n" \
"                }\n" \
"\n" \
"                // setup axes\n" \
"                s.xaxis = getOrCreateAxis(xaxes, axisNumber(s, \"x\"));\n" \
"                s.yaxis = getOrCreateAxis(yaxes, axisNumber(s, \"y\"));\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function processData() {\n" \
"            var topSentry = Number.POSITIVE_INFINITY,\n" \
"                bottomSentry = Number.NEGATIVE_INFINITY,\n" \
"                fakeInfinity = Number.MAX_VALUE,\n" \
"                i, j, k, m, length,\n" \
"                s, points, ps, x, y, axis, val, f, p,\n" \
"                data, format;\n" \
"\n" \
"            function updateAxis(axis, min, max) {\n" \
"                if (min < axis.datamin && min != -fakeInfinity)\n" \
"                    axis.datamin = min;\n" \
"                if (max > axis.datamax && max != fakeInfinity)\n" \
"                    axis.datamax = max;\n" \
"            }\n" \
"\n" \
"            $.each(allAxes(), function (_, axis) {\n" \
"                // init axis\n" \
"                axis.datamin = topSentry;\n" \
"                axis.datamax = bottomSentry;\n" \
"                axis.used = false;\n" \
"            });\n" \
"\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"                s.datapoints = { points: [] };\n" \
"\n" \
"                executeHooks(hooks.processRawData, [ s, s.data, s.datapoints ]);\n" \
"            }\n" \
"\n" \
"            // first pass: clean and copy data\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"\n" \
"                data = s.data;\n" \
"                format = s.datapoints.format;\n" \
"\n" \
"                if (!format) {\n" \
"                    format = [];\n" \
"                    // find out how to copy\n" \
"                    format.push({ x: true, number: true, required: true });\n" \
"                    format.push({ y: true, number: true, required: true });\n" \
"\n" \
"                    if (s.bars.show || (s.lines.show && s.lines.fill)) {\n" \
"                        var autoscale = !!((s.bars.show && s.bars.zero) || (s.lines.show && s.lines.zero));\n" \
"                        format.push({ y: true, number: true, required: false, defaultValue: 0, autoscale: autoscale });\n" \
"                        if (s.bars.horizontal) {\n" \
"                            delete format[format.length - 1].y;\n" \
"                            format[format.length - 1].x = true;\n" \
"                        }\n" \
"                    }\n" \
"\n" \
"                    s.datapoints.format = format;\n" \
"                }\n" \
"\n" \
"                if (s.datapoints.pointsize != null)\n" \
"                    continue; // already filled in\n" \
"\n" \
"                s.datapoints.pointsize = format.length;\n" \
"\n" \
"                ps = s.datapoints.pointsize;\n" \
"                points = s.datapoints.points;\n" \
"\n" \
"                var insertSteps = s.lines.show && s.lines.steps;\n" \
"                s.xaxis.used = s.yaxis.used = true;\n" \
"\n" \
"                for (j = k = 0; j < data.length; ++j, k += ps) {\n" \
"                    p = data[j];\n" \
"\n" \
"                    var nullify = p == null;\n" \
"                    if (!nullify) {\n" \
"                        for (m = 0; m < ps; ++m) {\n" \
"                            val = p[m];\n" \
"                            f = format[m];\n" \
"\n" \
"                            if (f) {\n" \
"                                if (f.number && val != null) {\n" \
"                                    val = +val; // convert to number\n" \
"                                    if (isNaN(val))\n" \
"                                        val = null;\n" \
"                                    else if (val == Infinity)\n" \
"                                        val = fakeInfinity;\n" \
"                                    else if (val == -Infinity)\n" \
"                                        val = -fakeInfinity;\n" \
"                                }\n" \
"\n" \
"                                if (val == null) {\n" \
"                                    if (f.required)\n" \
"                                        nullify = true;\n" \
"\n" \
"                                    if (f.defaultValue != null)\n" \
"                                        val = f.defaultValue;\n" \
"                                }\n" \
"                            }\n" \
"\n" \
"                            points[k + m] = val;\n" \
"                        }\n" \
"                    }\n" \
"\n" \
"                    if (nullify) {\n" \
"                        for (m = 0; m < ps; ++m) {\n" \
"                            val = points[k + m];\n" \
"                            if (val != null) {\n" \
"                                f = format[m];\n" \
"                                // extract min/max info\n" \
"                                if (f.autoscale !== false) {\n" \
"                                    if (f.x) {\n" \
"                                        updateAxis(s.xaxis, val, val);\n" \
"                                    }\n" \
"                                    if (f.y) {\n" \
"                                        updateAxis(s.yaxis, val, val);\n" \
"                                    }\n" \
"                                }\n" \
"                            }\n" \
"                            points[k + m] = null;\n" \
"                        }\n" \
"                    }\n" \
"                    else {\n" \
"                        // a little bit of line specific stuff that\n" \
"                        // perhaps shouldn't be here, but lacking\n" \
"                        // better means...\n" \
"                        if (insertSteps && k > 0\n" \
"                            && points[k - ps] != null\n" \
"                            && points[k - ps] != points[k]\n" \
"                            && points[k - ps + 1] != points[k + 1]) {\n" \
"                            // copy the point to make room for a middle point\n" \
"                            for (m = 0; m < ps; ++m)\n" \
"                                points[k + ps + m] = points[k + m];\n" \
"\n" \
"                            // middle point has same y\n" \
"                            points[k + 1] = points[k - ps + 1];\n" \
"\n" \
"                            // we've added a point, better reflect that\n" \
"                            k += ps;\n" \
"                        }\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // give the hooks a chance to run\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"\n" \
"                executeHooks(hooks.processDatapoints, [ s, s.datapoints]);\n" \
"            }\n" \
"\n" \
"            // second pass: find datamax/datamin for auto-scaling\n" \
"            for (i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"                points = s.datapoints.points;\n" \
"                ps = s.datapoints.pointsize;\n" \
"                format = s.datapoints.format;\n" \
"\n" \
"                var xmin = topSentry, ymin = topSentry,\n" \
"                    xmax = bottomSentry, ymax = bottomSentry;\n" \
"\n" \
"                for (j = 0; j < points.length; j += ps) {\n" \
"                    if (points[j] == null)\n" \
"                        continue;\n" \
"\n" \
"                    for (m = 0; m < ps; ++m) {\n" \
"                        val = points[j + m];\n" \
"                        f = format[m];\n" \
"                        if (!f || f.autoscale === false || val == fakeInfinity || val == -fakeInfinity)\n" \
"                            continue;\n" \
"\n" \
"                        if (f.x) {\n" \
"                            if (val < xmin)\n" \
"                                xmin = val;\n" \
"                            if (val > xmax)\n" \
"                                xmax = val;\n" \
"                        }\n" \
"                        if (f.y) {\n" \
"                            if (val < ymin)\n" \
"                                ymin = val;\n" \
"                            if (val > ymax)\n" \
"                                ymax = val;\n" \
"                        }\n" \
"                    }\n" \
"                }\n" \
"\n" \
"                if (s.bars.show) {\n" \
"                    // make sure we got room for the bar on the dancing floor\n" \
"                    var delta;\n" \
"\n" \
"                    switch (s.bars.align) {\n" \
"                        case \"left\":\n" \
"                            delta = 0;\n" \
"                            break;\n" \
"                        case \"right\":\n" \
"                            delta = -s.bars.barWidth;\n" \
"                            break;\n" \
"                        default:\n" \
"                            delta = -s.bars.barWidth / 2;\n" \
"                    }\n" \
"\n" \
"                    if (s.bars.horizontal) {\n" \
"                        ymin += delta;\n" \
"                        ymax += delta + s.bars.barWidth;\n" \
"                    }\n" \
"                    else {\n" \
"                        xmin += delta;\n" \
"                        xmax += delta + s.bars.barWidth;\n" \
"                    }\n" \
"                }\n" \
"\n" \
"                updateAxis(s.xaxis, xmin, xmax);\n" \
"                updateAxis(s.yaxis, ymin, ymax);\n" \
"            }\n" \
"\n" \
"            $.each(allAxes(), function (_, axis) {\n" \
"                if (axis.datamin == topSentry)\n" \
"                    axis.datamin = null;\n" \
"                if (axis.datamax == bottomSentry)\n" \
"                    axis.datamax = null;\n" \
"            });\n" \
"        }\n" \
"\n" \
"        function setupCanvases() {\n" \
"\n" \
"            // Make sure the placeholder is clear of everything except canvases\n" \
"            // from a previous plot in this container that we'll try to re-use.\n" \
"\n" \
"            placeholder.css(\"padding\", 0) // padding messes up the positioning\n" \
"                .children().filter(function(){\n" \
"                    return !$(this).hasClass(\"flot-overlay\") && !$(this).hasClass('flot-base');\n" \
"                }).remove();\n" \
"\n" \
"            if (placeholder.css(\"position\") == 'static')\n" \
"                placeholder.css(\"position\", \"relative\"); // for positioning labels and overlay\n" \
"\n" \
"            surface = new Canvas(\"flot-base\", placeholder);\n" \
"            overlay = new Canvas(\"flot-overlay\", placeholder); // overlay canvas for interactive features\n" \
"\n" \
"            ctx = surface.context;\n" \
"            octx = overlay.context;\n" \
"\n" \
"            // define which element we're listening for events on\n" \
"            eventHolder = $(overlay.element).unbind();\n" \
"\n" \
"            // If we're re-using a plot object, shut down the old one\n" \
"\n" \
"            var existing = placeholder.data(\"plot\");\n" \
"\n" \
"            if (existing) {\n" \
"                existing.shutdown();\n" \
"                overlay.clear();\n" \
"            }\n" \
"\n" \
"            // save in case we get replotted\n" \
"            placeholder.data(\"plot\", plot);\n" \
"        }\n" \
"\n" \
"        function bindEvents() {\n" \
"            // bind events\n" \
"            if (options.grid.hoverable) {\n" \
"                eventHolder.mousemove(onMouseMove);\n" \
"\n" \
"                // Use bind, rather than .mouseleave, because we officially\n" \
"                // still support jQuery 1.2.6, which doesn't define a shortcut\n" \
"                // for mouseenter or mouseleave.  This was a bug/oversight that\n" \
"                // was fixed somewhere around 1.3.x.  We can return to using\n" \
"                // .mouseleave when we drop support for 1.2.6.\n" \
"\n" \
"                eventHolder.bind(\"mouseleave\", onMouseLeave);\n" \
"            }\n" \
"\n" \
"            if (options.grid.clickable)\n" \
"                eventHolder.click(onClick);\n" \
"\n" \
"            executeHooks(hooks.bindEvents, [eventHolder]);\n" \
"        }\n" \
"\n" \
"        function shutdown() {\n" \
"            if (redrawTimeout)\n" \
"                clearTimeout(redrawTimeout);\n" \
"\n" \
"            eventHolder.unbind(\"mousemove\", onMouseMove);\n" \
"            eventHolder.unbind(\"mouseleave\", onMouseLeave);\n" \
"            eventHolder.unbind(\"click\", onClick);\n" \
"\n" \
"            executeHooks(hooks.shutdown, [eventHolder]);\n" \
"        }\n" \
"\n" \
"        function setTransformationHelpers(axis) {\n" \
"            // set helper functions on the axis, assumes plot area\n" \
"            // has been computed already\n" \
"\n" \
"            function identity(x) { return x; }\n" \
"\n" \
"            var s, m, t = axis.options.transform || identity,\n" \
"                it = axis.options.inverseTransform;\n" \
"\n" \
"            // precompute how much the axis is scaling a point\n" \
"            // in canvas space\n" \
"            if (axis.direction == \"x\") {\n" \
"                s = axis.scale = plotWidth / Math.abs(t(axis.max) - t(axis.min));\n" \
"                m = Math.min(t(axis.max), t(axis.min));\n" \
"            }\n" \
"            else {\n" \
"                s = axis.scale = plotHeight / Math.abs(t(axis.max) - t(axis.min));\n" \
"                s = -s;\n" \
"                m = Math.max(t(axis.max), t(axis.min));\n" \
"            }\n" \
"\n" \
"            // data point to canvas coordinate\n" \
"            if (t == identity) // slight optimization\n" \
"                axis.p2c = function (p) { return (p - m) * s; };\n" \
"            else\n" \
"                axis.p2c = function (p) { return (t(p) - m) * s; };\n" \
"            // canvas coordinate to data point\n" \
"            if (!it)\n" \
"                axis.c2p = function (c) { return m + c / s; };\n" \
"            else\n" \
"                axis.c2p = function (c) { return it(m + c / s); };\n" \
"        }\n" \
"\n" \
"        function measureTickLabels(axis) {\n" \
"\n" \
"            var opts = axis.options,\n" \
"                ticks = axis.ticks || [],\n" \
"                labelWidth = opts.labelWidth || 0,\n" \
"                labelHeight = opts.labelHeight || 0,\n" \
"                maxWidth = labelWidth || (axis.direction == \"x\" ? Math.floor(surface.width / (ticks.length || 1)) : null),\n" \
"                legacyStyles = axis.direction + \"Axis \" + axis.direction + axis.n + \"Axis\",\n" \
"                layer = \"flot-\" + axis.direction + \"-axis flot-\" + axis.direction + axis.n + \"-axis \" + legacyStyles,\n" \
"                font = opts.font || \"flot-tick-label tickLabel\";\n" \
"\n" \
"            for (var i = 0; i < ticks.length; ++i) {\n" \
"\n" \
"                var t = ticks[i];\n" \
"\n" \
"                if (!t.label)\n" \
"                    continue;\n" \
"\n" \
"                var info = surface.getTextInfo(layer, t.label, font, null, maxWidth);\n" \
"\n" \
"                labelWidth = Math.max(labelWidth, info.width);\n" \
"                labelHeight = Math.max(labelHeight, info.height);\n" \
"            }\n" \
"\n" \
"            axis.labelWidth = opts.labelWidth || labelWidth;\n" \
"            axis.labelHeight = opts.labelHeight || labelHeight;\n" \
"        }\n" \
"\n" \
"        function allocateAxisBoxFirstPhase(axis) {\n" \
"            // find the bounding box of the axis by looking at label\n" \
"            // widths/heights and ticks, make room by diminishing the\n" \
"            // plotOffset; this first phase only looks at one\n" \
"            // dimension per axis, the other dimension depends on the\n" \
"            // other axes so will have to wait\n" \
"\n" \
"            var lw = axis.labelWidth,\n" \
"                lh = axis.labelHeight,\n" \
"                pos = axis.options.position,\n" \
"                isXAxis = axis.direction === \"x\",\n" \
"                tickLength = axis.options.tickLength,\n" \
"                axisMargin = options.grid.axisMargin,\n" \
"                padding = options.grid.labelMargin,\n" \
"                innermost = true,\n" \
"                outermost = true,\n" \
"                first = true,\n" \
"                found = false;\n" \
"\n" \
"            // Determine the axis's position in its direction and on its side\n" \
"\n" \
"            $.each(isXAxis ? xaxes : yaxes, function(i, a) {\n" \
"                if (a && (a.show || a.reserveSpace)) {\n" \
"                    if (a === axis) {\n" \
"                        found = true;\n" \
"                    } else if (a.options.position === pos) {\n" \
"                        if (found) {\n" \
"                            outermost = false;\n" \
"                        } else {\n" \
"                            innermost = false;\n" \
"                        }\n" \
"                    }\n" \
"                    if (!found) {\n" \
"                        first = false;\n" \
"                    }\n" \
"                }\n" \
"            });\n" \
"\n" \
"            // The outermost axis on each side has no margin\n" \
"\n" \
"            if (outermost) {\n" \
"                axisMargin = 0;\n" \
"            }\n" \
"\n" \
"            // The ticks for the first axis in each direction stretch across\n" \
"\n" \
"            if (tickLength == null) {\n" \
"                tickLength = first ? \"full\" : 5;\n" \
"            }\n" \
"\n" \
"            if (!isNaN(+tickLength))\n" \
"                padding += +tickLength;\n" \
"\n" \
"            if (isXAxis) {\n" \
"                lh += padding;\n" \
"\n" \
"                if (pos == \"bottom\") {\n" \
"                    plotOffset.bottom += lh + axisMargin;\n" \
"                    axis.box = { top: surface.height - plotOffset.bottom, height: lh };\n" \
"                }\n" \
"                else {\n" \
"                    axis.box = { top: plotOffset.top + axisMargin, height: lh };\n" \
"                    plotOffset.top += lh + axisMargin;\n" \
"                }\n" \
"            }\n" \
"            else {\n" \
"                lw += padding;\n" \
"\n" \
"                if (pos == \"left\") {\n" \
"                    axis.box = { left: plotOffset.left + axisMargin, width: lw };\n" \
"                    plotOffset.left += lw + axisMargin;\n" \
"                }\n" \
"                else {\n" \
"                    plotOffset.right += lw + axisMargin;\n" \
"                    axis.box = { left: surface.width - plotOffset.right, width: lw };\n" \
"                }\n" \
"            }\n" \
"\n" \
"             // save for future reference\n" \
"            axis.position = pos;\n" \
"            axis.tickLength = tickLength;\n" \
"            axis.box.padding = padding;\n" \
"            axis.innermost = innermost;\n" \
"        }\n" \
"\n" \
"        function allocateAxisBoxSecondPhase(axis) {\n" \
"            // now that all axis boxes have been placed in one\n" \
"            // dimension, we can set the remaining dimension coordinates\n" \
"            if (axis.direction == \"x\") {\n" \
"                axis.box.left = plotOffset.left - axis.labelWidth / 2;\n" \
"                axis.box.width = surface.width - plotOffset.left - plotOffset.right + axis.labelWidth;\n" \
"            }\n" \
"            else {\n" \
"                axis.box.top = plotOffset.top - axis.labelHeight / 2;\n" \
"                axis.box.height = surface.height - plotOffset.bottom - plotOffset.top + axis.labelHeight;\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function adjustLayoutForThingsStickingOut() {\n" \
"            // possibly adjust plot offset to ensure everything stays\n" \
"            // inside the canvas and isn't clipped off\n" \
"\n" \
"            var minMargin = options.grid.minBorderMargin,\n" \
"                axis, i;\n" \
"\n" \
"            // check stuff from the plot (FIXME: this should just read\n" \
"            // a value from the series, otherwise it's impossible to\n" \
"            // customize)\n" \
"            if (minMargin == null) {\n" \
"                minMargin = 0;\n" \
"                for (i = 0; i < series.length; ++i)\n" \
"                    minMargin = Math.max(minMargin, 2 * (series[i].points.radius + series[i].points.lineWidth/2));\n" \
"            }\n" \
"\n" \
"            var margins = {\n" \
"                left: minMargin,\n" \
"                right: minMargin,\n" \
"                top: minMargin,\n" \
"                bottom: minMargin\n" \
"            };\n" \
"\n" \
"            // check axis labels, note we don't check the actual\n" \
"            // labels but instead use the overall width/height to not\n" \
"            // jump as much around with replots\n" \
"            $.each(allAxes(), function (_, axis) {\n" \
"                if (axis.reserveSpace && axis.ticks && axis.ticks.length) {\n" \
"                    if (axis.direction === \"x\") {\n" \
"                        margins.left = Math.max(margins.left, axis.labelWidth / 2);\n" \
"                        margins.right = Math.max(margins.right, axis.labelWidth / 2);\n" \
"                    } else {\n" \
"                        margins.bottom = Math.max(margins.bottom, axis.labelHeight / 2);\n" \
"                        margins.top = Math.max(margins.top, axis.labelHeight / 2);\n" \
"                    }\n" \
"                }\n" \
"            });\n" \
"\n" \
"            plotOffset.left = Math.ceil(Math.max(margins.left, plotOffset.left));\n" \
"            plotOffset.right = Math.ceil(Math.max(margins.right, plotOffset.right));\n" \
"            plotOffset.top = Math.ceil(Math.max(margins.top, plotOffset.top));\n" \
"            plotOffset.bottom = Math.ceil(Math.max(margins.bottom, plotOffset.bottom));\n" \
"        }\n" \
"\n" \
"        function setupGrid() {\n" \
"            var i, axes = allAxes(), showGrid = options.grid.show;\n" \
"\n" \
"            // Initialize the plot's offset from the edge of the canvas\n" \
"\n" \
"            for (var a in plotOffset) {\n" \
"                var margin = options.grid.margin || 0;\n" \
"                plotOffset[a] = typeof margin == \"number\" ? margin : margin[a] || 0;\n" \
"            }\n" \
"\n" \
"            executeHooks(hooks.processOffset, [plotOffset]);\n" \
"\n" \
"            // If the grid is visible, add its border width to the offset\n" \
"\n" \
"            for (var a in plotOffset) {\n" \
"                if(typeof(options.grid.borderWidth) == \"object\") {\n" \
"                    plotOffset[a] += showGrid ? options.grid.borderWidth[a] : 0;\n" \
"                }\n" \
"                else {\n" \
"                    plotOffset[a] += showGrid ? options.grid.borderWidth : 0;\n" \
"                }\n" \
"            }\n" \
"\n" \
"            $.each(axes, function (_, axis) {\n" \
"                var axisOpts = axis.options;\n" \
"                axis.show = axisOpts.show == null ? axis.used : axisOpts.show;\n" \
"                axis.reserveSpace = axisOpts.reserveSpace == null ? axis.show : axisOpts.reserveSpace;\n" \
"                setRange(axis);\n" \
"            });\n" \
"\n" \
"            if (showGrid) {\n" \
"\n" \
"                var allocatedAxes = $.grep(axes, function (axis) {\n" \
"                    return axis.show || axis.reserveSpace;\n" \
"                });\n" \
"\n" \
"                $.each(allocatedAxes, function (_, axis) {\n" \
"                    // make the ticks\n" \
"                    setupTickGeneration(axis);\n" \
"                    setTicks(axis);\n" \
"                    snapRangeToTicks(axis, axis.ticks);\n" \
"                    // find labelWidth/Height for axis\n" \
"                    measureTickLabels(axis);\n" \
"                });\n" \
"\n" \
"                // with all dimensions calculated, we can compute the\n" \
"                // axis bounding boxes, start from the outside\n" \
"                // (reverse order)\n" \
"                for (i = allocatedAxes.length - 1; i >= 0; --i)\n" \
"                    allocateAxisBoxFirstPhase(allocatedAxes[i]);\n" \
"\n" \
"                // make sure we've got enough space for things that\n" \
"                // might stick out\n" \
"                adjustLayoutForThingsStickingOut();\n" \
"\n" \
"                $.each(allocatedAxes, function (_, axis) {\n" \
"                    allocateAxisBoxSecondPhase(axis);\n" \
"                });\n" \
"            }\n" \
"\n" \
"            plotWidth = surface.width - plotOffset.left - plotOffset.right;\n" \
"            plotHeight = surface.height - plotOffset.bottom - plotOffset.top;\n" \
"\n" \
"            // now we got the proper plot dimensions, we can compute the scaling\n" \
"            $.each(axes, function (_, axis) {\n" \
"                setTransformationHelpers(axis);\n" \
"            });\n" \
"\n" \
"            if (showGrid) {\n" \
"                drawAxisLabels();\n" \
"            }\n" \
"\n" \
"            insertLegend();\n" \
"        }\n" \
"\n" \
"        function setRange(axis) {\n" \
"            var opts = axis.options,\n" \
"                min = +(opts.min != null ? opts.min : axis.datamin),\n" \
"                max = +(opts.max != null ? opts.max : axis.datamax),\n" \
"                delta = max - min;\n" \
"\n" \
"            if (delta == 0.0) {\n" \
"                // degenerate case\n" \
"                var widen = max == 0 ? 1 : 0.01;\n" \
"\n" \
"                if (opts.min == null)\n" \
"                    min -= widen;\n" \
"                // always widen max if we couldn't widen min to ensure we\n" \
"                // don't fall into min == max which doesn't work\n" \
"                if (opts.max == null || opts.min != null)\n" \
"                    max += widen;\n" \
"            }\n" \
"            else {\n" \
"                // consider autoscaling\n" \
"                var margin = opts.autoscaleMargin;\n" \
"                if (margin != null) {\n" \
"                    if (opts.min == null) {\n" \
"                        min -= delta * margin;\n" \
"                        // make sure we don't go below zero if all values\n" \
"                        // are positive\n" \
"                        if (min < 0 && axis.datamin != null && axis.datamin >= 0)\n" \
"                            min = 0;\n" \
"                    }\n" \
"                    if (opts.max == null) {\n" \
"                        max += delta * margin;\n" \
"                        if (max > 0 && axis.datamax != null && axis.datamax <= 0)\n" \
"                            max = 0;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"            axis.min = min;\n" \
"            axis.max = max;\n" \
"        }\n" \
"\n" \
"        function setupTickGeneration(axis) {\n" \
"            var opts = axis.options;\n" \
"\n" \
"            // estimate number of ticks\n" \
"            var noTicks;\n" \
"            if (typeof opts.ticks == \"number\" && opts.ticks > 0)\n" \
"                noTicks = opts.ticks;\n" \
"            else\n" \
"                // heuristic based on the model a*sqrt(x) fitted to\n" \
"                // some data points that seemed reasonable\n" \
"                noTicks = 0.3 * Math.sqrt(axis.direction == \"x\" ? surface.width : surface.height);\n" \
"\n" \
"            var delta = (axis.max - axis.min) / noTicks,\n" \
"                dec = -Math.floor(Math.log(delta) / Math.LN10),\n" \
"                maxDec = opts.tickDecimals;\n" \
"\n" \
"            if (maxDec != null && dec > maxDec) {\n" \
"                dec = maxDec;\n" \
"            }\n" \
"\n" \
"            var magn = Math.pow(10, -dec),\n" \
"                norm = delta / magn, // norm is between 1.0 and 10.0\n" \
"                size;\n" \
"\n" \
"            if (norm < 1.5) {\n" \
"                size = 1;\n" \
"            } else if (norm < 3) {\n" \
"                size = 2;\n" \
"                // special case for 2.5, requires an extra decimal\n" \
"                if (norm > 2.25 && (maxDec == null || dec + 1 <= maxDec)) {\n" \
"                    size = 2.5;\n" \
"                    ++dec;\n" \
"                }\n" \
"            } else if (norm < 7.5) {\n" \
"                size = 5;\n" \
"            } else {\n" \
"                size = 10;\n" \
"            }\n" \
"\n" \
"            size *= magn;\n" \
"\n" \
"            if (opts.minTickSize != null && size < opts.minTickSize) {\n" \
"                size = opts.minTickSize;\n" \
"            }\n" \
"\n" \
"            axis.delta = delta;\n" \
"            axis.tickDecimals = Math.max(0, maxDec != null ? maxDec : dec);\n" \
"            axis.tickSize = opts.tickSize || size;\n" \
"\n" \
"            // Time mode was moved to a plug-in in 0.8, and since so many people use it\n" \
"            // we'll add an especially friendly reminder to make sure they included it.\n" \
"\n" \
"            if (opts.mode == \"time\" && !axis.tickGenerator) {\n" \
"                throw new Error(\"Time mode requires the flot.time plugin.\");\n" \
"            }\n" \
"\n" \
"            // Flot supports base-10 axes; any other mode else is handled by a plug-in,\n" \
"            // like flot.time.js.\n" \
"\n" \
"            if (!axis.tickGenerator) {\n" \
"\n" \
"                axis.tickGenerator = function (axis) {\n" \
"\n" \
"                    var ticks = [],\n" \
"                        start = floorInBase(axis.min, axis.tickSize),\n" \
"                        i = 0,\n" \
"                        v = Number.NaN,\n" \
"                        prev;\n" \
"\n" \
"                    do {\n" \
"                        prev = v;\n" \
"                        v = start + i * axis.tickSize;\n" \
"                        ticks.push(v);\n" \
"                        ++i;\n" \
"                    } while (v < axis.max && v != prev);\n" \
"                    return ticks;\n" \
"                };\n" \
"\n" \
"				axis.tickFormatter = function (value, axis) {\n" \
"\n" \
"					var factor = axis.tickDecimals ? Math.pow(10, axis.tickDecimals) : 1;\n" \
"					var formatted = \"\" + Math.round(value * factor) / factor;\n" \
"\n" \
"					// If tickDecimals was specified, ensure that we have exactly that\n" \
"					// much precision; otherwise default to the value's own precision.\n" \
"\n" \
"					if (axis.tickDecimals != null) {\n" \
"						var decimal = formatted.indexOf(\".\");\n" \
"						var precision = decimal == -1 ? 0 : formatted.length - decimal - 1;\n" \
"						if (precision < axis.tickDecimals) {\n" \
"							return (precision ? formatted : formatted + \".\") + (\"\" + factor).substr(1, axis.tickDecimals - precision);\n" \
"						}\n" \
"					}\n" \
"\n" \
"                    return formatted;\n" \
"                };\n" \
"            }\n" \
"\n" \
"            if ($.isFunction(opts.tickFormatter))\n" \
"                axis.tickFormatter = function (v, axis) { return \"\" + opts.tickFormatter(v, axis); };\n" \
"\n" \
"            if (opts.alignTicksWithAxis != null) {\n" \
"                var otherAxis = (axis.direction == \"x\" ? xaxes : yaxes)[opts.alignTicksWithAxis - 1];\n" \
"                if (otherAxis && otherAxis.used && otherAxis != axis) {\n" \
"                    // consider snapping min/max to outermost nice ticks\n" \
"                    var niceTicks = axis.tickGenerator(axis);\n" \
"                    if (niceTicks.length > 0) {\n" \
"                        if (opts.min == null)\n" \
"                            axis.min = Math.min(axis.min, niceTicks[0]);\n" \
"                        if (opts.max == null && niceTicks.length > 1)\n" \
"                            axis.max = Math.max(axis.max, niceTicks[niceTicks.length - 1]);\n" \
"                    }\n" \
"\n" \
"                    axis.tickGenerator = function (axis) {\n" \
"                        // copy ticks, scaled to this axis\n" \
"                        var ticks = [], v, i;\n" \
"                        for (i = 0; i < otherAxis.ticks.length; ++i) {\n" \
"                            v = (otherAxis.ticks[i].v - otherAxis.min) / (otherAxis.max - otherAxis.min);\n" \
"                            v = axis.min + v * (axis.max - axis.min);\n" \
"                            ticks.push(v);\n" \
"                        }\n" \
"                        return ticks;\n" \
"                    };\n" \
"\n" \
"                    // we might need an extra decimal since forced\n" \
"                    // ticks don't necessarily fit naturally\n" \
"                    if (!axis.mode && opts.tickDecimals == null) {\n" \
"                        var extraDec = Math.max(0, -Math.floor(Math.log(axis.delta) / Math.LN10) + 1),\n" \
"                            ts = axis.tickGenerator(axis);\n" \
"\n" \
"                        // only proceed if the tick interval rounded\n" \
"                        // with an extra decimal doesn't give us a\n" \
"                        // zero at end\n" \
"                        if (!(ts.length > 1 && /\\..*0$/.test((ts[1] - ts[0]).toFixed(extraDec))))\n" \
"                            axis.tickDecimals = extraDec;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function setTicks(axis) {\n" \
"            var oticks = axis.options.ticks, ticks = [];\n" \
"            if (oticks == null || (typeof oticks == \"number\" && oticks > 0))\n" \
"                ticks = axis.tickGenerator(axis);\n" \
"            else if (oticks) {\n" \
"                if ($.isFunction(oticks))\n" \
"                    // generate the ticks\n" \
"                    ticks = oticks(axis);\n" \
"                else\n" \
"                    ticks = oticks;\n" \
"            }\n" \
"\n" \
"            // clean up/labelify the supplied ticks, copy them over\n" \
"            var i, v;\n" \
"            axis.ticks = [];\n" \
"            for (i = 0; i < ticks.length; ++i) {\n" \
"                var label = null;\n" \
"                var t = ticks[i];\n" \
"                if (typeof t == \"object\") {\n" \
"                    v = +t[0];\n" \
"                    if (t.length > 1)\n" \
"                        label = t[1];\n" \
"                }\n" \
"                else\n" \
"                    v = +t;\n" \
"                if (label == null)\n" \
"                    label = axis.tickFormatter(v, axis);\n" \
"                if (!isNaN(v))\n" \
"                    axis.ticks.push({ v: v, label: label });\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function snapRangeToTicks(axis, ticks) {\n" \
"            if (axis.options.autoscaleMargin && ticks.length > 0) {\n" \
"                // snap to ticks\n" \
"                if (axis.options.min == null)\n" \
"                    axis.min = Math.min(axis.min, ticks[0].v);\n" \
"                if (axis.options.max == null && ticks.length > 1)\n" \
"                    axis.max = Math.max(axis.max, ticks[ticks.length - 1].v);\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function draw() {\n" \
"\n" \
"            surface.clear();\n" \
"\n" \
"            executeHooks(hooks.drawBackground, [ctx]);\n" \
"\n" \
"            var grid = options.grid;\n" \
"\n" \
"            // draw background, if any\n" \
"            if (grid.show && grid.backgroundColor)\n" \
"                drawBackground();\n" \
"\n" \
"            if (grid.show && !grid.aboveData) {\n" \
"                drawGrid();\n" \
"            }\n" \
"\n" \
"            for (var i = 0; i < series.length; ++i) {\n" \
"                executeHooks(hooks.drawSeries, [ctx, series[i]]);\n" \
"                drawSeries(series[i]);\n" \
"            }\n" \
"\n" \
"            executeHooks(hooks.draw, [ctx]);\n" \
"\n" \
"            if (grid.show && grid.aboveData) {\n" \
"                drawGrid();\n" \
"            }\n" \
"\n" \
"            surface.render();\n" \
"\n" \
"            // A draw implies that either the axes or data have changed, so we\n" \
"            // should probably update the overlay highlights as well.\n" \
"\n" \
"            triggerRedrawOverlay();\n" \
"        }\n" \
"\n" \
"        function extractRange(ranges, coord) {\n" \
"            var axis, from, to, key, axes = allAxes();\n" \
"\n" \
"            for (var i = 0; i < axes.length; ++i) {\n" \
"                axis = axes[i];\n" \
"                if (axis.direction == coord) {\n" \
"                    key = coord + axis.n + \"axis\";\n" \
"                    if (!ranges[key] && axis.n == 1)\n" \
"                        key = coord + \"axis\"; // support x1axis as xaxis\n" \
"                    if (ranges[key]) {\n" \
"                        from = ranges[key].from;\n" \
"                        to = ranges[key].to;\n" \
"                        break;\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // backwards-compat stuff - to be removed in future\n" \
"            if (!ranges[key]) {\n" \
"                axis = coord == \"x\" ? xaxes[0] : yaxes[0];\n" \
"                from = ranges[coord + \"1\"];\n" \
"                to = ranges[coord + \"2\"];\n" \
"            }\n" \
"\n" \
"            // auto-reverse as an added bonus\n" \
"            if (from != null && to != null && from > to) {\n" \
"                var tmp = from;\n" \
"                from = to;\n" \
"                to = tmp;\n" \
"            }\n" \
"\n" \
"            return { from: from, to: to, axis: axis };\n" \
"        }\n" \
"\n" \
"        function drawBackground() {\n" \
"            ctx.save();\n" \
"            ctx.translate(plotOffset.left, plotOffset.top);\n" \
"\n" \
"            ctx.fillStyle = getColorOrGradient(options.grid.backgroundColor, plotHeight, 0, \"rgba(255, 255, 255, 0)\");\n" \
"            ctx.fillRect(0, 0, plotWidth, plotHeight);\n" \
"            ctx.restore();\n" \
"        }\n" \
"\n" \
"        function drawGrid() {\n" \
"            var i, axes, bw, bc;\n" \
"\n" \
"            ctx.save();\n" \
"            ctx.translate(plotOffset.left, plotOffset.top);\n" \
"\n" \
"            // draw markings\n" \
"            var markings = options.grid.markings;\n" \
"            if (markings) {\n" \
"                if ($.isFunction(markings)) {\n" \
"                    axes = plot.getAxes();\n" \
"                    // xmin etc. is backwards compatibility, to be\n" \
"                    // removed in the future\n" \
"                    axes.xmin = axes.xaxis.min;\n" \
"                    axes.xmax = axes.xaxis.max;\n" \
"                    axes.ymin = axes.yaxis.min;\n" \
"                    axes.ymax = axes.yaxis.max;\n" \
"\n" \
"                    markings = markings(axes);\n" \
"                }\n" \
"\n" \
"                for (i = 0; i < markings.length; ++i) {\n" \
"                    var m = markings[i],\n" \
"                        xrange = extractRange(m, \"x\"),\n" \
"                        yrange = extractRange(m, \"y\");\n" \
"\n" \
"                    // fill in missing\n" \
"                    if (xrange.from == null)\n" \
"                        xrange.from = xrange.axis.min;\n" \
"                    if (xrange.to == null)\n" \
"                        xrange.to = xrange.axis.max;\n" \
"                    if (yrange.from == null)\n" \
"                        yrange.from = yrange.axis.min;\n" \
"                    if (yrange.to == null)\n" \
"                        yrange.to = yrange.axis.max;\n" \
"\n" \
"                    // clip\n" \
"                    if (xrange.to < xrange.axis.min || xrange.from > xrange.axis.max ||\n" \
"                        yrange.to < yrange.axis.min || yrange.from > yrange.axis.max)\n" \
"                        continue;\n" \
"\n" \
"                    xrange.from = Math.max(xrange.from, xrange.axis.min);\n" \
"                    xrange.to = Math.min(xrange.to, xrange.axis.max);\n" \
"                    yrange.from = Math.max(yrange.from, yrange.axis.min);\n" \
"                    yrange.to = Math.min(yrange.to, yrange.axis.max);\n" \
"\n" \
"                    var xequal = xrange.from === xrange.to,\n" \
"                        yequal = yrange.from === yrange.to;\n" \
"\n" \
"                    if (xequal && yequal) {\n" \
"                        continue;\n" \
"                    }\n" \
"\n" \
"                    // then draw\n" \
"                    xrange.from = Math.floor(xrange.axis.p2c(xrange.from));\n" \
"                    xrange.to = Math.floor(xrange.axis.p2c(xrange.to));\n" \
"                    yrange.from = Math.floor(yrange.axis.p2c(yrange.from));\n" \
"                    yrange.to = Math.floor(yrange.axis.p2c(yrange.to));\n" \
"\n" \
"                    if (xequal || yequal) {\n" \
"                        var lineWidth = m.lineWidth || options.grid.markingsLineWidth,\n" \
"                            subPixel = lineWidth % 2 ? 0.5 : 0;\n" \
"                        ctx.beginPath();\n" \
"                        ctx.strokeStyle = m.color || options.grid.markingsColor;\n" \
"                        ctx.lineWidth = lineWidth;\n" \
"                        if (xequal) {\n" \
"                            ctx.moveTo(xrange.to + subPixel, yrange.from);\n" \
"                            ctx.lineTo(xrange.to + subPixel, yrange.to);\n" \
"                        } else {\n" \
"                            ctx.moveTo(xrange.from, yrange.to + subPixel);\n" \
"                            ctx.lineTo(xrange.to, yrange.to + subPixel);                            \n" \
"                        }\n" \
"                        ctx.stroke();\n" \
"                    } else {\n" \
"                        ctx.fillStyle = m.color || options.grid.markingsColor;\n" \
"                        ctx.fillRect(xrange.from, yrange.to,\n" \
"                                     xrange.to - xrange.from,\n" \
"                                     yrange.from - yrange.to);\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // draw the ticks\n" \
"            axes = allAxes();\n" \
"            bw = options.grid.borderWidth;\n" \
"\n" \
"            for (var j = 0; j < axes.length; ++j) {\n" \
"                var axis = axes[j], box = axis.box,\n" \
"                    t = axis.tickLength, x, y, xoff, yoff;\n" \
"                if (!axis.show || axis.ticks.length == 0)\n" \
"                    continue;\n" \
"\n" \
"                ctx.lineWidth = 1;\n" \
"\n" \
"                // find the edges\n" \
"                if (axis.direction == \"x\") {\n" \
"                    x = 0;\n" \
"                    if (t == \"full\")\n" \
"                        y = (axis.position == \"top\" ? 0 : plotHeight);\n" \
"                    else\n" \
"                        y = box.top - plotOffset.top + (axis.position == \"top\" ? box.height : 0);\n" \
"                }\n" \
"                else {\n" \
"                    y = 0;\n" \
"                    if (t == \"full\")\n" \
"                        x = (axis.position == \"left\" ? 0 : plotWidth);\n" \
"                    else\n" \
"                        x = box.left - plotOffset.left + (axis.position == \"left\" ? box.width : 0);\n" \
"                }\n" \
"\n" \
"                // draw tick bar\n" \
"                if (!axis.innermost) {\n" \
"                    ctx.strokeStyle = axis.options.color;\n" \
"                    ctx.beginPath();\n" \
"                    xoff = yoff = 0;\n" \
"                    if (axis.direction == \"x\")\n" \
"                        xoff = plotWidth + 1;\n" \
"                    else\n" \
"                        yoff = plotHeight + 1;\n" \
"\n" \
"                    if (ctx.lineWidth == 1) {\n" \
"                        if (axis.direction == \"x\") {\n" \
"                            y = Math.floor(y) + 0.5;\n" \
"                        } else {\n" \
"                            x = Math.floor(x) + 0.5;\n" \
"                        }\n" \
"                    }\n" \
"\n" \
"                    ctx.moveTo(x, y);\n" \
"                    ctx.lineTo(x + xoff, y + yoff);\n" \
"                    ctx.stroke();\n" \
"                }\n" \
"\n" \
"                // draw ticks\n" \
"\n" \
"                ctx.strokeStyle = axis.options.tickColor;\n" \
"\n" \
"                ctx.beginPath();\n" \
"                for (i = 0; i < axis.ticks.length; ++i) {\n" \
"                    var v = axis.ticks[i].v;\n" \
"\n" \
"                    xoff = yoff = 0;\n" \
"\n" \
"                    if (isNaN(v) || v < axis.min || v > axis.max\n" \
"                        // skip those lying on the axes if we got a border\n" \
"                        || (t == \"full\"\n" \
"                            && ((typeof bw == \"object\" && bw[axis.position] > 0) || bw > 0)\n" \
"                            && (v == axis.min || v == axis.max)))\n" \
"                        continue;\n" \
"\n" \
"                    if (axis.direction == \"x\") {\n" \
"                        x = axis.p2c(v);\n" \
"                        yoff = t == \"full\" ? -plotHeight : t;\n" \
"\n" \
"                        if (axis.position == \"top\")\n" \
"                            yoff = -yoff;\n" \
"                    }\n" \
"                    else {\n" \
"                        y = axis.p2c(v);\n" \
"                        xoff = t == \"full\" ? -plotWidth : t;\n" \
"\n" \
"                        if (axis.position == \"left\")\n" \
"                            xoff = -xoff;\n" \
"                    }\n" \
"\n" \
"                    if (ctx.lineWidth == 1) {\n" \
"                        if (axis.direction == \"x\")\n" \
"                            x = Math.floor(x) + 0.5;\n" \
"                        else\n" \
"                            y = Math.floor(y) + 0.5;\n" \
"                    }\n" \
"\n" \
"                    ctx.moveTo(x, y);\n" \
"                    ctx.lineTo(x + xoff, y + yoff);\n" \
"                }\n" \
"\n" \
"                ctx.stroke();\n" \
"            }\n" \
"\n" \
"\n" \
"            // draw border\n" \
"            if (bw) {\n" \
"                // If either borderWidth or borderColor is an object, then draw the border\n" \
"                // line by line instead of as one rectangle\n" \
"                bc = options.grid.borderColor;\n" \
"                if(typeof bw == \"object\" || typeof bc == \"object\") {\n" \
"                    if (typeof bw !== \"object\") {\n" \
"                        bw = {top: bw, right: bw, bottom: bw, left: bw};\n" \
"                    }\n" \
"                    if (typeof bc !== \"object\") {\n" \
"                        bc = {top: bc, right: bc, bottom: bc, left: bc};\n" \
"                    }\n" \
"\n" \
"                    if (bw.top > 0) {\n" \
"                        ctx.strokeStyle = bc.top;\n" \
"                        ctx.lineWidth = bw.top;\n" \
"                        ctx.beginPath();\n" \
"                        ctx.moveTo(0 - bw.left, 0 - bw.top/2);\n" \
"                        ctx.lineTo(plotWidth, 0 - bw.top/2);\n" \
"                        ctx.stroke();\n" \
"                    }\n" \
"\n" \
"                    if (bw.right > 0) {\n" \
"                        ctx.strokeStyle = bc.right;\n" \
"                        ctx.lineWidth = bw.right;\n" \
"                        ctx.beginPath();\n" \
"                        ctx.moveTo(plotWidth + bw.right / 2, 0 - bw.top);\n" \
"                        ctx.lineTo(plotWidth + bw.right / 2, plotHeight);\n" \
"                        ctx.stroke();\n" \
"                    }\n" \
"\n" \
"                    if (bw.bottom > 0) {\n" \
"                        ctx.strokeStyle = bc.bottom;\n" \
"                        ctx.lineWidth = bw.bottom;\n" \
"                        ctx.beginPath();\n" \
"                        ctx.moveTo(plotWidth + bw.right, plotHeight + bw.bottom / 2);\n" \
"                        ctx.lineTo(0, plotHeight + bw.bottom / 2);\n" \
"                        ctx.stroke();\n" \
"                    }\n" \
"\n" \
"                    if (bw.left > 0) {\n" \
"                        ctx.strokeStyle = bc.left;\n" \
"                        ctx.lineWidth = bw.left;\n" \
"                        ctx.beginPath();\n" \
"                        ctx.moveTo(0 - bw.left/2, plotHeight + bw.bottom);\n" \
"                        ctx.lineTo(0- bw.left/2, 0);\n" \
"                        ctx.stroke();\n" \
"                    }\n" \
"                }\n" \
"                else {\n" \
"                    ctx.lineWidth = bw;\n" \
"                    ctx.strokeStyle = options.grid.borderColor;\n" \
"                    ctx.strokeRect(-bw/2, -bw/2, plotWidth + bw, plotHeight + bw);\n" \
"                }\n" \
"            }\n" \
"\n" \
"            ctx.restore();\n" \
"        }\n" \
"\n" \
"        function drawAxisLabels() {\n" \
"\n" \
"            $.each(allAxes(), function (_, axis) {\n" \
"                var box = axis.box,\n" \
"                    legacyStyles = axis.direction + \"Axis \" + axis.direction + axis.n + \"Axis\",\n" \
"                    layer = \"flot-\" + axis.direction + \"-axis flot-\" + axis.direction + axis.n + \"-axis \" + legacyStyles,\n" \
"                    font = axis.options.font || \"flot-tick-label tickLabel\",\n" \
"                    tick, x, y, halign, valign;\n" \
"\n" \
"                // Remove text before checking for axis.show and ticks.length;\n" \
"                // otherwise plugins, like flot-tickrotor, that draw their own\n" \
"                // tick labels will end up with both theirs and the defaults.\n" \
"\n" \
"                surface.removeText(layer);\n" \
"\n" \
"                if (!axis.show || axis.ticks.length == 0)\n" \
"                    return;\n" \
"\n" \
"                for (var i = 0; i < axis.ticks.length; ++i) {\n" \
"\n" \
"                    tick = axis.ticks[i];\n" \
"                    if (!tick.label || tick.v < axis.min || tick.v > axis.max)\n" \
"                        continue;\n" \
"\n" \
"                    if (axis.direction == \"x\") {\n" \
"                        halign = \"center\";\n" \
"                        x = plotOffset.left + axis.p2c(tick.v);\n" \
"                        if (axis.position == \"bottom\") {\n" \
"                            y = box.top + box.padding;\n" \
"                        } else {\n" \
"                            y = box.top + box.height - box.padding;\n" \
"                            valign = \"bottom\";\n" \
"                        }\n" \
"                    } else {\n" \
"                        valign = \"middle\";\n" \
"                        y = plotOffset.top + axis.p2c(tick.v);\n" \
"                        if (axis.position == \"left\") {\n" \
"                            x = box.left + box.width - box.padding;\n" \
"                            halign = \"right\";\n" \
"                        } else {\n" \
"                            x = box.left + box.padding;\n" \
"                        }\n" \
"                    }\n" \
"\n" \
"                    surface.addText(layer, x, y, tick.label, font, null, null, halign, valign);\n" \
"                }\n" \
"            });\n" \
"        }\n" \
"\n" \
"        function drawSeries(series) {\n" \
"            if (series.lines.show)\n" \
"                drawSeriesLines(series);\n" \
"            if (series.bars.show)\n" \
"                drawSeriesBars(series);\n" \
"            if (series.points.show)\n" \
"                drawSeriesPoints(series);\n" \
"        }\n" \
"\n" \
"        function drawSeriesLines(series) {\n" \
"            function plotLine(datapoints, xoffset, yoffset, axisx, axisy) {\n" \
"                var points = datapoints.points,\n" \
"                    ps = datapoints.pointsize,\n" \
"                    prevx = null, prevy = null;\n" \
"\n" \
"                ctx.beginPath();\n" \
"                for (var i = ps; i < points.length; i += ps) {\n" \
"                    var x1 = points[i - ps], y1 = points[i - ps + 1],\n" \
"                        x2 = points[i], y2 = points[i + 1];\n" \
"\n" \
"                    if (x1 == null || x2 == null)\n" \
"                        continue;\n" \
"\n" \
"                    // clip with ymin\n" \
"                    if (y1 <= y2 && y1 < axisy.min) {\n" \
"                        if (y2 < axisy.min)\n" \
"                            continue;   // line segment is outside\n" \
"                        // compute new intersection point\n" \
"                        x1 = (axisy.min - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y1 = axisy.min;\n" \
"                    }\n" \
"                    else if (y2 <= y1 && y2 < axisy.min) {\n" \
"                        if (y1 < axisy.min)\n" \
"                            continue;\n" \
"                        x2 = (axisy.min - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y2 = axisy.min;\n" \
"                    }\n" \
"\n" \
"                    // clip with ymax\n" \
"                    if (y1 >= y2 && y1 > axisy.max) {\n" \
"                        if (y2 > axisy.max)\n" \
"                            continue;\n" \
"                        x1 = (axisy.max - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y1 = axisy.max;\n" \
"                    }\n" \
"                    else if (y2 >= y1 && y2 > axisy.max) {\n" \
"                        if (y1 > axisy.max)\n" \
"                            continue;\n" \
"                        x2 = (axisy.max - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y2 = axisy.max;\n" \
"                    }\n" \
"\n" \
"                    // clip with xmin\n" \
"                    if (x1 <= x2 && x1 < axisx.min) {\n" \
"                        if (x2 < axisx.min)\n" \
"                            continue;\n" \
"                        y1 = (axisx.min - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x1 = axisx.min;\n" \
"                    }\n" \
"                    else if (x2 <= x1 && x2 < axisx.min) {\n" \
"                        if (x1 < axisx.min)\n" \
"                            continue;\n" \
"                        y2 = (axisx.min - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x2 = axisx.min;\n" \
"                    }\n" \
"\n" \
"                    // clip with xmax\n" \
"                    if (x1 >= x2 && x1 > axisx.max) {\n" \
"                        if (x2 > axisx.max)\n" \
"                            continue;\n" \
"                        y1 = (axisx.max - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x1 = axisx.max;\n" \
"                    }\n" \
"                    else if (x2 >= x1 && x2 > axisx.max) {\n" \
"                        if (x1 > axisx.max)\n" \
"                            continue;\n" \
"                        y2 = (axisx.max - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x2 = axisx.max;\n" \
"                    }\n" \
"\n" \
"                    if (x1 != prevx || y1 != prevy)\n" \
"                        ctx.moveTo(axisx.p2c(x1) + xoffset, axisy.p2c(y1) + yoffset);\n" \
"\n" \
"                    prevx = x2;\n" \
"                    prevy = y2;\n" \
"                    ctx.lineTo(axisx.p2c(x2) + xoffset, axisy.p2c(y2) + yoffset);\n" \
"                }\n" \
"                ctx.stroke();\n" \
"            }\n" \
"\n" \
"            function plotLineArea(datapoints, axisx, axisy) {\n" \
"                var points = datapoints.points,\n" \
"                    ps = datapoints.pointsize,\n" \
"                    bottom = Math.min(Math.max(0, axisy.min), axisy.max),\n" \
"                    i = 0, top, areaOpen = false,\n" \
"                    ypos = 1, segmentStart = 0, segmentEnd = 0;\n" \
"\n" \
"                // we process each segment in two turns, first forward\n" \
"                // direction to sketch out top, then once we hit the\n" \
"                // end we go backwards to sketch the bottom\n" \
"                while (true) {\n" \
"                    if (ps > 0 && i > points.length + ps)\n" \
"                        break;\n" \
"\n" \
"                    i += ps; // ps is negative if going backwards\n" \
"\n" \
"                    var x1 = points[i - ps],\n" \
"                        y1 = points[i - ps + ypos],\n" \
"                        x2 = points[i], y2 = points[i + ypos];\n" \
"\n" \
"                    if (areaOpen) {\n" \
"                        if (ps > 0 && x1 != null && x2 == null) {\n" \
"                            // at turning point\n" \
"                            segmentEnd = i;\n" \
"                            ps = -ps;\n" \
"                            ypos = 2;\n" \
"                            continue;\n" \
"                        }\n" \
"\n" \
"                        if (ps < 0 && i == segmentStart + ps) {\n" \
"                            // done with the reverse sweep\n" \
"                            ctx.fill();\n" \
"                            areaOpen = false;\n" \
"                            ps = -ps;\n" \
"                            ypos = 1;\n" \
"                            i = segmentStart = segmentEnd + ps;\n" \
"                            continue;\n" \
"                        }\n" \
"                    }\n" \
"\n" \
"                    if (x1 == null || x2 == null)\n" \
"                        continue;\n" \
"\n" \
"                    // clip x values\n" \
"\n" \
"                    // clip with xmin\n" \
"                    if (x1 <= x2 && x1 < axisx.min) {\n" \
"                        if (x2 < axisx.min)\n" \
"                            continue;\n" \
"                        y1 = (axisx.min - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x1 = axisx.min;\n" \
"                    }\n" \
"                    else if (x2 <= x1 && x2 < axisx.min) {\n" \
"                        if (x1 < axisx.min)\n" \
"                            continue;\n" \
"                        y2 = (axisx.min - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x2 = axisx.min;\n" \
"                    }\n" \
"\n" \
"                    // clip with xmax\n" \
"                    if (x1 >= x2 && x1 > axisx.max) {\n" \
"                        if (x2 > axisx.max)\n" \
"                            continue;\n" \
"                        y1 = (axisx.max - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x1 = axisx.max;\n" \
"                    }\n" \
"                    else if (x2 >= x1 && x2 > axisx.max) {\n" \
"                        if (x1 > axisx.max)\n" \
"                            continue;\n" \
"                        y2 = (axisx.max - x1) / (x2 - x1) * (y2 - y1) + y1;\n" \
"                        x2 = axisx.max;\n" \
"                    }\n" \
"\n" \
"                    if (!areaOpen) {\n" \
"                        // open area\n" \
"                        ctx.beginPath();\n" \
"                        ctx.moveTo(axisx.p2c(x1), axisy.p2c(bottom));\n" \
"                        areaOpen = true;\n" \
"                    }\n" \
"\n" \
"                    // now first check the case where both is outside\n" \
"                    if (y1 >= axisy.max && y2 >= axisy.max) {\n" \
"                        ctx.lineTo(axisx.p2c(x1), axisy.p2c(axisy.max));\n" \
"                        ctx.lineTo(axisx.p2c(x2), axisy.p2c(axisy.max));\n" \
"                        continue;\n" \
"                    }\n" \
"                    else if (y1 <= axisy.min && y2 <= axisy.min) {\n" \
"                        ctx.lineTo(axisx.p2c(x1), axisy.p2c(axisy.min));\n" \
"                        ctx.lineTo(axisx.p2c(x2), axisy.p2c(axisy.min));\n" \
"                        continue;\n" \
"                    }\n" \
"\n" \
"                    // else it's a bit more complicated, there might\n" \
"                    // be a flat maxed out rectangle first, then a\n" \
"                    // triangular cutout or reverse; to find these\n" \
"                    // keep track of the current x values\n" \
"                    var x1old = x1, x2old = x2;\n" \
"\n" \
"                    // clip the y values, without shortcutting, we\n" \
"                    // go through all cases in turn\n" \
"\n" \
"                    // clip with ymin\n" \
"                    if (y1 <= y2 && y1 < axisy.min && y2 >= axisy.min) {\n" \
"                        x1 = (axisy.min - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y1 = axisy.min;\n" \
"                    }\n" \
"                    else if (y2 <= y1 && y2 < axisy.min && y1 >= axisy.min) {\n" \
"                        x2 = (axisy.min - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y2 = axisy.min;\n" \
"                    }\n" \
"\n" \
"                    // clip with ymax\n" \
"                    if (y1 >= y2 && y1 > axisy.max && y2 <= axisy.max) {\n" \
"                        x1 = (axisy.max - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y1 = axisy.max;\n" \
"                    }\n" \
"                    else if (y2 >= y1 && y2 > axisy.max && y1 <= axisy.max) {\n" \
"                        x2 = (axisy.max - y1) / (y2 - y1) * (x2 - x1) + x1;\n" \
"                        y2 = axisy.max;\n" \
"                    }\n" \
"\n" \
"                    // if the x value was changed we got a rectangle\n" \
"                    // to fill\n" \
"                    if (x1 != x1old) {\n" \
"                        ctx.lineTo(axisx.p2c(x1old), axisy.p2c(y1));\n" \
"                        // it goes to (x1, y1), but we fill that below\n" \
"                    }\n" \
"\n" \
"                    // fill triangular section, this sometimes result\n" \
"                    // in redundant points if (x1, y1) hasn't changed\n" \
"                    // from previous line to, but we just ignore that\n" \
"                    ctx.lineTo(axisx.p2c(x1), axisy.p2c(y1));\n" \
"                    ctx.lineTo(axisx.p2c(x2), axisy.p2c(y2));\n" \
"\n" \
"                    // fill the other rectangle if it's there\n" \
"                    if (x2 != x2old) {\n" \
"                        ctx.lineTo(axisx.p2c(x2), axisy.p2c(y2));\n" \
"                        ctx.lineTo(axisx.p2c(x2old), axisy.p2c(y2));\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            ctx.save();\n" \
"            ctx.translate(plotOffset.left, plotOffset.top);\n" \
"            ctx.lineJoin = \"round\";\n" \
"\n" \
"            var lw = series.lines.lineWidth,\n" \
"                sw = series.shadowSize;\n" \
"            // FIXME: consider another form of shadow when filling is turned on\n" \
"            if (lw > 0 && sw > 0) {\n" \
"                // draw shadow as a thick and thin line with transparency\n" \
"                ctx.lineWidth = sw;\n" \
"                ctx.strokeStyle = \"rgba(0,0,0,0.1)\";\n" \
"                // position shadow at angle from the mid of line\n" \
"                var angle = Math.PI/18;\n" \
"                plotLine(series.datapoints, Math.sin(angle) * (lw/2 + sw/2), Math.cos(angle) * (lw/2 + sw/2), series.xaxis, series.yaxis);\n" \
"                ctx.lineWidth = sw/2;\n" \
"                plotLine(series.datapoints, Math.sin(angle) * (lw/2 + sw/4), Math.cos(angle) * (lw/2 + sw/4), series.xaxis, series.yaxis);\n" \
"            }\n" \
"\n" \
"            ctx.lineWidth = lw;\n" \
"            ctx.strokeStyle = series.color;\n" \
"            var fillStyle = getFillStyle(series.lines, series.color, 0, plotHeight);\n" \
"            if (fillStyle) {\n" \
"                ctx.fillStyle = fillStyle;\n" \
"                plotLineArea(series.datapoints, series.xaxis, series.yaxis);\n" \
"            }\n" \
"\n" \
"            if (lw > 0)\n" \
"                plotLine(series.datapoints, 0, 0, series.xaxis, series.yaxis);\n" \
"            ctx.restore();\n" \
"        }\n" \
"\n" \
"        function drawSeriesPoints(series) {\n" \
"            function plotPoints(datapoints, radius, fillStyle, offset, shadow, axisx, axisy, symbol) {\n" \
"                var points = datapoints.points, ps = datapoints.pointsize;\n" \
"\n" \
"                for (var i = 0; i < points.length; i += ps) {\n" \
"                    var x = points[i], y = points[i + 1];\n" \
"                    if (x == null || x < axisx.min || x > axisx.max || y < axisy.min || y > axisy.max)\n" \
"                        continue;\n" \
"\n" \
"                    ctx.beginPath();\n" \
"                    x = axisx.p2c(x);\n" \
"                    y = axisy.p2c(y) + offset;\n" \
"                    if (symbol == \"circle\")\n" \
"                        ctx.arc(x, y, radius, 0, shadow ? Math.PI : Math.PI * 2, false);\n" \
"                    else\n" \
"                        symbol(ctx, x, y, radius, shadow);\n" \
"                    ctx.closePath();\n" \
"\n" \
"                    if (fillStyle) {\n" \
"                        ctx.fillStyle = fillStyle;\n" \
"                        ctx.fill();\n" \
"                    }\n" \
"                    ctx.stroke();\n" \
"                }\n" \
"            }\n" \
"\n" \
"            ctx.save();\n" \
"            ctx.translate(plotOffset.left, plotOffset.top);\n" \
"\n" \
"            var lw = series.points.lineWidth,\n" \
"                sw = series.shadowSize,\n" \
"                radius = series.points.radius,\n" \
"                symbol = series.points.symbol;\n" \
"\n" \
"            // If the user sets the line width to 0, we change it to a very \n" \
"            // small value. A line width of 0 seems to force the default of 1.\n" \
"            // Doing the conditional here allows the shadow setting to still be \n" \
"            // optional even with a lineWidth of 0.\n" \
"\n" \
"            if( lw == 0 )\n" \
"                lw = 0.0001;\n" \
"\n" \
"            if (lw > 0 && sw > 0) {\n" \
"                // draw shadow in two steps\n" \
"                var w = sw / 2;\n" \
"                ctx.lineWidth = w;\n" \
"                ctx.strokeStyle = \"rgba(0,0,0,0.1)\";\n" \
"                plotPoints(series.datapoints, radius, null, w + w/2, true,\n" \
"                           series.xaxis, series.yaxis, symbol);\n" \
"\n" \
"                ctx.strokeStyle = \"rgba(0,0,0,0.2)\";\n" \
"                plotPoints(series.datapoints, radius, null, w/2, true,\n" \
"                           series.xaxis, series.yaxis, symbol);\n" \
"            }\n" \
"\n" \
"            ctx.lineWidth = lw;\n" \
"            ctx.strokeStyle = series.color;\n" \
"            plotPoints(series.datapoints, radius,\n" \
"                       getFillStyle(series.points, series.color), 0, false,\n" \
"                       series.xaxis, series.yaxis, symbol);\n" \
"            ctx.restore();\n" \
"        }\n" \
"\n" \
"        function drawBar(x, y, b, barLeft, barRight, fillStyleCallback, axisx, axisy, c, horizontal, lineWidth) {\n" \
"            var left, right, bottom, top,\n" \
"                drawLeft, drawRight, drawTop, drawBottom,\n" \
"                tmp;\n" \
"\n" \
"            // in horizontal mode, we start the bar from the left\n" \
"            // instead of from the bottom so it appears to be\n" \
"            // horizontal rather than vertical\n" \
"            if (horizontal) {\n" \
"                drawBottom = drawRight = drawTop = true;\n" \
"                drawLeft = false;\n" \
"                left = b;\n" \
"                right = x;\n" \
"                top = y + barLeft;\n" \
"                bottom = y + barRight;\n" \
"\n" \
"                // account for negative bars\n" \
"                if (right < left) {\n" \
"                    tmp = right;\n" \
"                    right = left;\n" \
"                    left = tmp;\n" \
"                    drawLeft = true;\n" \
"                    drawRight = false;\n" \
"                }\n" \
"            }\n" \
"            else {\n" \
"                drawLeft = drawRight = drawTop = true;\n" \
"                drawBottom = false;\n" \
"                left = x + barLeft;\n" \
"                right = x + barRight;\n" \
"                bottom = b;\n" \
"                top = y;\n" \
"\n" \
"                // account for negative bars\n" \
"                if (top < bottom) {\n" \
"                    tmp = top;\n" \
"                    top = bottom;\n" \
"                    bottom = tmp;\n" \
"                    drawBottom = true;\n" \
"                    drawTop = false;\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // clip\n" \
"            if (right < axisx.min || left > axisx.max ||\n" \
"                top < axisy.min || bottom > axisy.max)\n" \
"                return;\n" \
"\n" \
"            if (left < axisx.min) {\n" \
"                left = axisx.min;\n" \
"                drawLeft = false;\n" \
"            }\n" \
"\n" \
"            if (right > axisx.max) {\n" \
"                right = axisx.max;\n" \
"                drawRight = false;\n" \
"            }\n" \
"\n" \
"            if (bottom < axisy.min) {\n" \
"                bottom = axisy.min;\n" \
"                drawBottom = false;\n" \
"            }\n" \
"\n" \
"            if (top > axisy.max) {\n" \
"                top = axisy.max;\n" \
"                drawTop = false;\n" \
"            }\n" \
"\n" \
"            left = axisx.p2c(left);\n" \
"            bottom = axisy.p2c(bottom);\n" \
"            right = axisx.p2c(right);\n" \
"            top = axisy.p2c(top);\n" \
"\n" \
"            // fill the bar\n" \
"            if (fillStyleCallback) {\n" \
"                c.fillStyle = fillStyleCallback(bottom, top);\n" \
"                c.fillRect(left, top, right - left, bottom - top)\n" \
"            }\n" \
"\n" \
"            // draw outline\n" \
"            if (lineWidth > 0 && (drawLeft || drawRight || drawTop || drawBottom)) {\n" \
"                c.beginPath();\n" \
"\n" \
"                // FIXME: inline moveTo is buggy with excanvas\n" \
"                c.moveTo(left, bottom);\n" \
"                if (drawLeft)\n" \
"                    c.lineTo(left, top);\n" \
"                else\n" \
"                    c.moveTo(left, top);\n" \
"                if (drawTop)\n" \
"                    c.lineTo(right, top);\n" \
"                else\n" \
"                    c.moveTo(right, top);\n" \
"                if (drawRight)\n" \
"                    c.lineTo(right, bottom);\n" \
"                else\n" \
"                    c.moveTo(right, bottom);\n" \
"                if (drawBottom)\n" \
"                    c.lineTo(left, bottom);\n" \
"                else\n" \
"                    c.moveTo(left, bottom);\n" \
"                c.stroke();\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function drawSeriesBars(series) {\n" \
"            function plotBars(datapoints, barLeft, barRight, fillStyleCallback, axisx, axisy) {\n" \
"                var points = datapoints.points, ps = datapoints.pointsize;\n" \
"\n" \
"                for (var i = 0; i < points.length; i += ps) {\n" \
"                    if (points[i] == null)\n" \
"                        continue;\n" \
"                    drawBar(points[i], points[i + 1], points[i + 2], barLeft, barRight, fillStyleCallback, axisx, axisy, ctx, series.bars.horizontal, series.bars.lineWidth);\n" \
"                }\n" \
"            }\n" \
"\n" \
"            ctx.save();\n" \
"            ctx.translate(plotOffset.left, plotOffset.top);\n" \
"\n" \
"            // FIXME: figure out a way to add shadows (for instance along the right edge)\n" \
"            ctx.lineWidth = series.bars.lineWidth;\n" \
"            ctx.strokeStyle = series.color;\n" \
"\n" \
"            var barLeft;\n" \
"\n" \
"            switch (series.bars.align) {\n" \
"                case \"left\":\n" \
"                    barLeft = 0;\n" \
"                    break;\n" \
"                case \"right\":\n" \
"                    barLeft = -series.bars.barWidth;\n" \
"                    break;\n" \
"                default:\n" \
"                    barLeft = -series.bars.barWidth / 2;\n" \
"            }\n" \
"\n" \
"            var fillStyleCallback = series.bars.fill ? function (bottom, top) { return getFillStyle(series.bars, series.color, bottom, top); } : null;\n" \
"            plotBars(series.datapoints, barLeft, barLeft + series.bars.barWidth, fillStyleCallback, series.xaxis, series.yaxis);\n" \
"            ctx.restore();\n" \
"        }\n" \
"\n" \
"        function getFillStyle(filloptions, seriesColor, bottom, top) {\n" \
"            var fill = filloptions.fill;\n" \
"            if (!fill)\n" \
"                return null;\n" \
"\n" \
"            if (filloptions.fillColor)\n" \
"                return getColorOrGradient(filloptions.fillColor, bottom, top, seriesColor);\n" \
"\n" \
"            var c = $.color.parse(seriesColor);\n" \
"            c.a = typeof fill == \"number\" ? fill : 0.4;\n" \
"            c.normalize();\n" \
"            return c.toString();\n" \
"        }\n" \
"\n" \
"        function insertLegend() {\n" \
"\n" \
"            if (options.legend.container != null) {\n" \
"                $(options.legend.container).html(\"\");\n" \
"            } else {\n" \
"                placeholder.find(\".legend\").remove();\n" \
"            }\n" \
"\n" \
"            if (!options.legend.show) {\n" \
"                return;\n" \
"            }\n" \
"\n" \
"            var fragments = [], entries = [], rowStarted = false,\n" \
"                lf = options.legend.labelFormatter, s, label;\n" \
"\n" \
"            // Build a list of legend entries, with each having a label and a color\n" \
"\n" \
"            for (var i = 0; i < series.length; ++i) {\n" \
"                s = series[i];\n" \
"                if (s.label) {\n" \
"                    label = lf ? lf(s.label, s) : s.label;\n" \
"                    if (label) {\n" \
"                        entries.push({\n" \
"                            label: label,\n" \
"                            color: s.color\n" \
"                        });\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // Sort the legend using either the default or a custom comparator\n" \
"\n" \
"            if (options.legend.sorted) {\n" \
"                if ($.isFunction(options.legend.sorted)) {\n" \
"                    entries.sort(options.legend.sorted);\n" \
"                } else if (options.legend.sorted == \"reverse\") {\n" \
"                	entries.reverse();\n" \
"                } else {\n" \
"                    var ascending = options.legend.sorted != \"descending\";\n" \
"                    entries.sort(function(a, b) {\n" \
"                        return a.label == b.label ? 0 : (\n" \
"                            (a.label < b.label) != ascending ? 1 : -1   // Logical XOR\n" \
"                        );\n" \
"                    });\n" \
"                }\n" \
"            }\n" \
"\n" \
"            // Generate markup for the list of entries, in their final order\n" \
"\n" \
"            for (var i = 0; i < entries.length; ++i) {\n" \
"\n" \
"                var entry = entries[i];\n" \
"\n" \
"                if (i % options.legend.noColumns == 0) {\n" \
"                    if (rowStarted)\n" \
"                        fragments.push('</tr>');\n" \
"                    fragments.push('<tr>');\n" \
"                    rowStarted = true;\n" \
"                }\n" \
"\n" \
"                fragments.push(\n" \
"                    '<td class=\"legendColorBox\"><div style=\"border:1px solid ' + options.legend.labelBoxBorderColor + ';padding:1px\"><div style=\"width:4px;height:0;border:5px solid ' + entry.color + ';overflow:hidden\"></div></div></td>' +\n" \
"                    '<td class=\"legendLabel\">' + entry.label + '</td>'\n" \
"                );\n" \
"            }\n" \
"\n" \
"            if (rowStarted)\n" \
"                fragments.push('</tr>');\n" \
"\n" \
"            if (fragments.length == 0)\n" \
"                return;\n" \
"\n" \
"            var table = '<table style=\"font-size:smaller;color:' + options.grid.color + '\">' + fragments.join(\"\") + '</table>';\n" \
"            if (options.legend.container != null)\n" \
"                $(options.legend.container).html(table);\n" \
"            else {\n" \
"                var pos = \"\",\n" \
"                    p = options.legend.position,\n" \
"                    m = options.legend.margin;\n" \
"                if (m[0] == null)\n" \
"                    m = [m, m];\n" \
"                if (p.charAt(0) == \"n\")\n" \
"                    pos += 'top:' + (m[1] + plotOffset.top) + 'px;';\n" \
"                else if (p.charAt(0) == \"s\")\n" \
"                    pos += 'bottom:' + (m[1] + plotOffset.bottom) + 'px;';\n" \
"                if (p.charAt(1) == \"e\")\n" \
"                    pos += 'right:' + (m[0] + plotOffset.right) + 'px;';\n" \
"                else if (p.charAt(1) == \"w\")\n" \
"                    pos += 'left:' + (m[0] + plotOffset.left) + 'px;';\n" \
"                var legend = $('<div class=\"legend\">' + table.replace('style=\"', 'style=\"position:absolute;' + pos +';') + '</div>').appendTo(placeholder);\n" \
"                if (options.legend.backgroundOpacity != 0.0) {\n" \
"                    // put in the transparent background\n" \
"                    // separately to avoid blended labels and\n" \
"                    // label boxes\n" \
"                    var c = options.legend.backgroundColor;\n" \
"                    if (c == null) {\n" \
"                        c = options.grid.backgroundColor;\n" \
"                        if (c && typeof c == \"string\")\n" \
"                            c = $.color.parse(c);\n" \
"                        else\n" \
"                            c = $.color.extract(legend, 'background-color');\n" \
"                        c.a = 1;\n" \
"                        c = c.toString();\n" \
"                    }\n" \
"                    var div = legend.children();\n" \
"                    $('<div style=\"position:absolute;width:' + div.width() + 'px;height:' + div.height() + 'px;' + pos +'background-color:' + c + ';\"> </div>').prependTo(legend).css('opacity', options.legend.backgroundOpacity);\n" \
"                }\n" \
"            }\n" \
"        }\n" \
"\n" \
"\n" \
"        // interactive features\n" \
"\n" \
"        var highlights = [],\n" \
"            redrawTimeout = null;\n" \
"\n" \
"        // returns the data item the mouse is over, or null if none is found\n" \
"        function findNearbyItem(mouseX, mouseY, seriesFilter) {\n" \
"            var maxDistance = options.grid.mouseActiveRadius,\n" \
"                smallestDistance = maxDistance * maxDistance + 1,\n" \
"                item = null, foundPoint = false, i, j, ps;\n" \
"\n" \
"            for (i = series.length - 1; i >= 0; --i) {\n" \
"                if (!seriesFilter(series[i]))\n" \
"                    continue;\n" \
"\n" \
"                var s = series[i],\n" \
"                    axisx = s.xaxis,\n" \
"                    axisy = s.yaxis,\n" \
"                    points = s.datapoints.points,\n" \
"                    mx = axisx.c2p(mouseX), // precompute some stuff to make the loop faster\n" \
"                    my = axisy.c2p(mouseY),\n" \
"                    maxx = maxDistance / axisx.scale,\n" \
"                    maxy = maxDistance / axisy.scale;\n" \
"\n" \
"                ps = s.datapoints.pointsize;\n" \
"                // with inverse transforms, we can't use the maxx/maxy\n" \
"                // optimization, sadly\n" \
"                if (axisx.options.inverseTransform)\n" \
"                    maxx = Number.MAX_VALUE;\n" \
"                if (axisy.options.inverseTransform)\n" \
"                    maxy = Number.MAX_VALUE;\n" \
"\n" \
"                if (s.lines.show || s.points.show) {\n" \
"                    for (j = 0; j < points.length; j += ps) {\n" \
"                        var x = points[j], y = points[j + 1];\n" \
"                        if (x == null)\n" \
"                            continue;\n" \
"\n" \
"                        // For points and lines, the cursor must be within a\n" \
"                        // certain distance to the data point\n" \
"                        if (x - mx > maxx || x - mx < -maxx ||\n" \
"                            y - my > maxy || y - my < -maxy)\n" \
"                            continue;\n" \
"\n" \
"                        // We have to calculate distances in pixels, not in\n" \
"                        // data units, because the scales of the axes may be different\n" \
"                        var dx = Math.abs(axisx.p2c(x) - mouseX),\n" \
"                            dy = Math.abs(axisy.p2c(y) - mouseY),\n" \
"                            dist = dx * dx + dy * dy; // we save the sqrt\n" \
"\n" \
"                        // use <= to ensure last point takes precedence\n" \
"                        // (last generally means on top of)\n" \
"                        if (dist < smallestDistance) {\n" \
"                            smallestDistance = dist;\n" \
"                            item = [i, j / ps];\n" \
"                        }\n" \
"                    }\n" \
"                }\n" \
"\n" \
"                if (s.bars.show && !item) { // no other point can be nearby\n" \
"\n" \
"                    var barLeft, barRight;\n" \
"\n" \
"                    switch (s.bars.align) {\n" \
"                        case \"left\":\n" \
"                            barLeft = 0;\n" \
"                            break;\n" \
"                        case \"right\":\n" \
"                            barLeft = -s.bars.barWidth;\n" \
"                            break;\n" \
"                        default:\n" \
"                            barLeft = -s.bars.barWidth / 2;\n" \
"                    }\n" \
"\n" \
"                    barRight = barLeft + s.bars.barWidth;\n" \
"\n" \
"                    for (j = 0; j < points.length; j += ps) {\n" \
"                        var x = points[j], y = points[j + 1], b = points[j + 2];\n" \
"                        if (x == null)\n" \
"                            continue;\n" \
"\n" \
"                        // for a bar graph, the cursor must be inside the bar\n" \
"                        if (series[i].bars.horizontal ?\n" \
"                            (mx <= Math.max(b, x) && mx >= Math.min(b, x) &&\n" \
"                             my >= y + barLeft && my <= y + barRight) :\n" \
"                            (mx >= x + barLeft && mx <= x + barRight &&\n" \
"                             my >= Math.min(b, y) && my <= Math.max(b, y)))\n" \
"                                item = [i, j / ps];\n" \
"                    }\n" \
"                }\n" \
"            }\n" \
"\n" \
"            if (item) {\n" \
"                i = item[0];\n" \
"                j = item[1];\n" \
"                ps = series[i].datapoints.pointsize;\n" \
"\n" \
"                return { datapoint: series[i].datapoints.points.slice(j * ps, (j + 1) * ps),\n" \
"                         dataIndex: j,\n" \
"                         series: series[i],\n" \
"                         seriesIndex: i };\n" \
"            }\n" \
"\n" \
"            return null;\n" \
"        }\n" \
"\n" \
"        function onMouseMove(e) {\n" \
"            if (options.grid.hoverable)\n" \
"                triggerClickHoverEvent(\"plothover\", e,\n" \
"                                       function (s) { return s[\"hoverable\"] != false; });\n" \
"        }\n" \
"\n" \
"        function onMouseLeave(e) {\n" \
"            if (options.grid.hoverable)\n" \
"                triggerClickHoverEvent(\"plothover\", e,\n" \
"                                       function (s) { return false; });\n" \
"        }\n" \
"\n" \
"        function onClick(e) {\n" \
"            triggerClickHoverEvent(\"plotclick\", e,\n" \
"                                   function (s) { return s[\"clickable\"] != false; });\n" \
"        }\n" \
"\n" \
"        // trigger click or hover event (they send the same parameters\n" \
"        // so we share their code)\n" \
"        function triggerClickHoverEvent(eventname, event, seriesFilter) {\n" \
"            var offset = eventHolder.offset(),\n" \
"                canvasX = event.pageX - offset.left - plotOffset.left,\n" \
"                canvasY = event.pageY - offset.top - plotOffset.top,\n" \
"            pos = canvasToAxisCoords({ left: canvasX, top: canvasY });\n" \
"\n" \
"            pos.pageX = event.pageX;\n" \
"            pos.pageY = event.pageY;\n" \
"\n" \
"            var item = findNearbyItem(canvasX, canvasY, seriesFilter);\n" \
"\n" \
"            if (item) {\n" \
"                // fill in mouse pos for any listeners out there\n" \
"                item.pageX = parseInt(item.series.xaxis.p2c(item.datapoint[0]) + offset.left + plotOffset.left, 10);\n" \
"                item.pageY = parseInt(item.series.yaxis.p2c(item.datapoint[1]) + offset.top + plotOffset.top, 10);\n" \
"            }\n" \
"\n" \
"            if (options.grid.autoHighlight) {\n" \
"                // clear auto-highlights\n" \
"                for (var i = 0; i < highlights.length; ++i) {\n" \
"                    var h = highlights[i];\n" \
"                    if (h.auto == eventname &&\n" \
"                        !(item && h.series == item.series &&\n" \
"                          h.point[0] == item.datapoint[0] &&\n" \
"                          h.point[1] == item.datapoint[1]))\n" \
"                        unhighlight(h.series, h.point);\n" \
"                }\n" \
"\n" \
"                if (item)\n" \
"                    highlight(item.series, item.datapoint, eventname);\n" \
"            }\n" \
"\n" \
"            placeholder.trigger(eventname, [ pos, item ]);\n" \
"        }\n" \
"\n" \
"        function triggerRedrawOverlay() {\n" \
"            var t = options.interaction.redrawOverlayInterval;\n" \
"            if (t == -1) {      // skip event queue\n" \
"                drawOverlay();\n" \
"                return;\n" \
"            }\n" \
"\n" \
"            if (!redrawTimeout)\n" \
"                redrawTimeout = setTimeout(drawOverlay, t);\n" \
"        }\n" \
"\n" \
"        function drawOverlay() {\n" \
"            redrawTimeout = null;\n" \
"\n" \
"            // draw highlights\n" \
"            octx.save();\n" \
"            overlay.clear();\n" \
"            octx.translate(plotOffset.left, plotOffset.top);\n" \
"\n" \
"            var i, hi;\n" \
"            for (i = 0; i < highlights.length; ++i) {\n" \
"                hi = highlights[i];\n" \
"\n" \
"                if (hi.series.bars.show)\n" \
"                    drawBarHighlight(hi.series, hi.point);\n" \
"                else\n" \
"                    drawPointHighlight(hi.series, hi.point);\n" \
"            }\n" \
"            octx.restore();\n" \
"\n" \
"            executeHooks(hooks.drawOverlay, [octx]);\n" \
"        }\n" \
"\n" \
"        function highlight(s, point, auto) {\n" \
"            if (typeof s == \"number\")\n" \
"                s = series[s];\n" \
"\n" \
"            if (typeof point == \"number\") {\n" \
"                var ps = s.datapoints.pointsize;\n" \
"                point = s.datapoints.points.slice(ps * point, ps * (point + 1));\n" \
"            }\n" \
"\n" \
"            var i = indexOfHighlight(s, point);\n" \
"            if (i == -1) {\n" \
"                highlights.push({ series: s, point: point, auto: auto });\n" \
"\n" \
"                triggerRedrawOverlay();\n" \
"            }\n" \
"            else if (!auto)\n" \
"                highlights[i].auto = false;\n" \
"        }\n" \
"\n" \
"        function unhighlight(s, point) {\n" \
"            if (s == null && point == null) {\n" \
"                highlights = [];\n" \
"                triggerRedrawOverlay();\n" \
"                return;\n" \
"            }\n" \
"\n" \
"            if (typeof s == \"number\")\n" \
"                s = series[s];\n" \
"\n" \
"            if (typeof point == \"number\") {\n" \
"                var ps = s.datapoints.pointsize;\n" \
"                point = s.datapoints.points.slice(ps * point, ps * (point + 1));\n" \
"            }\n" \
"\n" \
"            var i = indexOfHighlight(s, point);\n" \
"            if (i != -1) {\n" \
"                highlights.splice(i, 1);\n" \
"\n" \
"                triggerRedrawOverlay();\n" \
"            }\n" \
"        }\n" \
"\n" \
"        function indexOfHighlight(s, p) {\n" \
"            for (var i = 0; i < highlights.length; ++i) {\n" \
"                var h = highlights[i];\n" \
"                if (h.series == s && h.point[0] == p[0]\n" \
"                    && h.point[1] == p[1])\n" \
"                    return i;\n" \
"            }\n" \
"            return -1;\n" \
"        }\n" \
"\n" \
"        function drawPointHighlight(series, point) {\n" \
"            var x = point[0], y = point[1],\n" \
"                axisx = series.xaxis, axisy = series.yaxis,\n" \
"                highlightColor = (typeof series.highlightColor === \"string\") ? series.highlightColor : $.color.parse(series.color).scale('a', 0.5).toString();\n" \
"\n" \
"            if (x < axisx.min || x > axisx.max || y < axisy.min || y > axisy.max)\n" \
"                return;\n" \
"\n" \
"            var pointRadius = series.points.radius + series.points.lineWidth / 2;\n" \
"            octx.lineWidth = pointRadius;\n" \
"            octx.strokeStyle = highlightColor;\n" \
"            var radius = 1.5 * pointRadius;\n" \
"            x = axisx.p2c(x);\n" \
"            y = axisy.p2c(y);\n" \
"\n" \
"            octx.beginPath();\n" \
"            if (series.points.symbol == \"circle\")\n" \
"                octx.arc(x, y, radius, 0, 2 * Math.PI, false);\n" \
"            else\n" \
"                series.points.symbol(octx, x, y, radius, false);\n" \
"            octx.closePath();\n" \
"            octx.stroke();\n" \
"        }\n" \
"\n" \
"        function drawBarHighlight(series, point) {\n" \
"            var highlightColor = (typeof series.highlightColor === \"string\") ? series.highlightColor : $.color.parse(series.color).scale('a', 0.5).toString(),\n" \
"                fillStyle = highlightColor,\n" \
"                barLeft;\n" \
"\n" \
"            switch (series.bars.align) {\n" \
"                case \"left\":\n" \
"                    barLeft = 0;\n" \
"                    break;\n" \
"                case \"right\":\n" \
"                    barLeft = -series.bars.barWidth;\n" \
"                    break;\n" \
"                default:\n" \
"                    barLeft = -series.bars.barWidth / 2;\n" \
"            }\n" \
"\n" \
"            octx.lineWidth = series.bars.lineWidth;\n" \
"            octx.strokeStyle = highlightColor;\n" \
"\n" \
"            drawBar(point[0], point[1], point[2] || 0, barLeft, barLeft + series.bars.barWidth,\n" \
"                    function () { return fillStyle; }, series.xaxis, series.yaxis, octx, series.bars.horizontal, series.bars.lineWidth);\n" \
"        }\n" \
"\n" \
"        function getColorOrGradient(spec, bottom, top, defaultColor) {\n" \
"            if (typeof spec == \"string\")\n" \
"                return spec;\n" \
"            else {\n" \
"                // assume this is a gradient spec; IE currently only\n" \
"                // supports a simple vertical gradient properly, so that's\n" \
"                // what we support too\n" \
"                var gradient = ctx.createLinearGradient(0, top, 0, bottom);\n" \
"\n" \
"                for (var i = 0, l = spec.colors.length; i < l; ++i) {\n" \
"                    var c = spec.colors[i];\n" \
"                    if (typeof c != \"string\") {\n" \
"                        var co = $.color.parse(defaultColor);\n" \
"                        if (c.brightness != null)\n" \
"                            co = co.scale('rgb', c.brightness);\n" \
"                        if (c.opacity != null)\n" \
"                            co.a *= c.opacity;\n" \
"                        c = co.toString();\n" \
"                    }\n" \
"                    gradient.addColorStop(i / (l - 1), c);\n" \
"                }\n" \
"\n" \
"                return gradient;\n" \
"            }\n" \
"        }\n" \
"    }\n" \
"\n" \
"    // Add the plot function to the top level of the jQuery object\n" \
"\n" \
"    $.plot = function(placeholder, data, options) {\n" \
"        //var t0 = new Date();\n" \
"        var plot = new Plot($(placeholder), data, options, $.plot.plugins);\n" \
"        //(window.console ? console.log : alert)(\"time used (msecs): \" + ((new Date()).getTime() - t0.getTime()));\n" \
"        return plot;\n" \
"    };\n" \
"\n" \
"    $.plot.version = \"0.8.3\";\n" \
"\n" \
"    $.plot.plugins = [];\n" \
"\n" \
"    // Also add the plot function as a chainable property\n" \
"\n" \
"    $.fn.plot = function(data, options) {\n" \
"        return this.each(function() {\n" \
"            $.plot(this, data, options);\n" \
"        });\n" \
"    };\n" \
"\n" \
"    // round to nearby lower multiple of base\n" \
"    function floorInBase(n, base) {\n" \
"        return base * Math.floor(n / base);\n" \
"    }\n" \
"\n" \
"})(jQuery);\n" \


#define DATA_LEN_1 "122971"

#define DATA_2  \
"/* The MIT License\n" \
"\n" \
" Copyright (c) 2011 by Michael Zinsmaier and nergal.dev\n" \
" Copyright (c) 2012 by Thomas Ritou\n" \
"\n" \
" Permission is hereby granted, free of charge, to any person obtaining a copy\n" \
" of this software and associated documentation files (the \"Software\"), to deal\n" \
" in the Software without restriction, including without limitation the rights\n" \
" to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n" \
" copies of the Software, and to permit persons to whom the Software is\n" \
" furnished to do so, subject to the following conditions:\n" \
"\n" \
" The above copyright notice and this permission notice shall be included in\n" \
" all copies or substantial portions of the Software.\n" \
"\n" \
" THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n" \
" IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n" \
" FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n" \
" AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n" \
" LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n" \
" OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n" \
" THE SOFTWARE.\n" \
"*/\n" \
"\n" \
"/*\n" \
"____________________________________________________\n" \
"\n" \
" what it is:\n" \
" ____________________________________________________\n" \
"\n" \
" curvedLines is a plugin for flot, that tries to display lines in a smoother way.\n" \
" This is achieved through adding of more data points. The plugin is a data processor and can thus be used\n" \
" in combination with standard line / point rendering options.\n" \
"\n" \
" => 1) with large data sets you may get trouble\n" \
" => 2) if you want to display the points too, you have to plot them as 2nd data series over the lines\n" \
" => 3) consecutive x data points are not allowed to have the same value\n" \
"\n" \
" Feel free to further improve the code\n" \
"\n" \
" ____________________________________________________\n" \
"\n" \
" how to use it:\n" \
" ____________________________________________________\n" \
"\n" \
" var d1 = [[5,5],[7,3],[9,12]];\n" \
"\n" \
" var options = { series: { curvedLines: {  active: true }}};\n" \
"\n" \
" $.plot($(\"#placeholder\"), [{data: d1, lines: { show: true}, curvedLines: {apply: true}}], options);\n" \
"\n" \
" _____________________________________________________\n" \
"\n" \
" options:\n" \
" _____________________________________________________\n" \
"\n" \
" active:           bool true => plugin can be used\n" \
" apply:            bool true => series will be drawn as curved line\n" \
" monotonicFit:	   bool true => uses monotone cubic interpolation (preserve monotonicity)\n" \
" tension:          int          defines the tension parameter of the hermite spline interpolation (no effect if monotonicFit is set)\n" \
" nrSplinePoints:   int 			defines the number of sample points (of the spline) in between two consecutive points\n" \
"\n" \
" deprecated options from flot prior to 1.0.0:\n" \
" ------------------------------------------------\n" \
" legacyOverride	   bool true => use old default\n" \
"    OR\n" \
" legacyOverride    optionArray\n" \
" {\n" \
" 	fit: 	             bool true => forces the max,mins of the curve to be on the datapoints\n" \
" 	curvePointFactor	 int  		  defines how many \"virtual\" points are used per \"real\" data point to\n" \
" 									  emulate the curvedLines (points total = real points * curvePointFactor)\n" \
" 	fitPointDist: 	     int  		  defines the x axis distance of the additional two points that are used\n" \
" }						   		   	  to enforce the min max condition.\n" \
" */\n" \
"\n" \
"/*\n" \
" *  v0.1   initial commit\n" \
" *  v0.15  negative values should work now (outcommented a negative -> 0 hook hope it does no harm)\n" \
" *  v0.2   added fill option (thanks to monemihir) and multi axis support (thanks to soewono effendi)\n" \
" *  v0.3   improved saddle handling and added basic handling of Dates\n" \
" *  v0.4   rewritten fill option (thomas ritou) mostly from original flot code (now fill between points rather than to graph bottom), corrected fill Opacity bug\n" \
" *  v0.5   rewritten instead of implementing a own draw function CurvedLines is now based on the processDatapoints flot hook (credits go to thomas ritou).\n" \
" * 		   This change breakes existing code however CurvedLines are now just many tiny straight lines to flot and therefore all flot lines options (like gradient fill,\n" \
" * 	       shadow) are now supported out of the box\n" \
" *  v0.6   flot 0.8 compatibility and some bug fixes\n" \
" *  v0.6.x changed versioning schema\n" \
" *\n" \
" *  v1.0.0 API Break marked existing implementation/options as deprecated\n" \
" *  v1.1.0 added the new curved line calculations based on hermite splines\n" \
" *  v1.1.1 added a rough parameter check to make sure the new options are used\n" \
" */\n" \
"\n" \
"(function($) {\n" \
"\n" \
"	var options = {\n" \
"		series : {\n" \
"			curvedLines : {\n" \
"				active : false,\n" \
"				apply : false,\n" \
"				monotonicFit : false,\n" \
"				tension : 0.5,\n" \
"				nrSplinePoints : 20,\n" \
"				legacyOverride : undefined\n" \
"			}\n" \
"		}\n" \
"	};\n" \
"\n" \
"	function init(plot) {\n" \
"\n" \
"		plot.hooks.processOptions.push(processOptions);\n" \
"\n" \
"		//if the plugin is active register processDatapoints method\n" \
"		function processOptions(plot, options) {\n" \
"			if (options.series.curvedLines.active) {\n" \
"				plot.hooks.processDatapoints.unshift(processDatapoints);\n" \
"			}\n" \
"		}\n" \
"\n" \
"		//only if the plugin is active\n" \
"		function processDatapoints(plot, series, datapoints) {\n" \
"			var nrPoints = datapoints.points.length / datapoints.pointsize;\n" \
"			var EPSILON = 0.005;\n" \
"\n" \
"			//detects missplaced legacy parameters (prior v1.x.x) in the options object\n" \
"			//this can happen if somebody upgrades to v1.x.x without adjusting the parameters or uses old examples\n" \
"            var invalidLegacyOptions = hasInvalidParameters(series.curvedLines);\n" \
"\n" \
"			if (!invalidLegacyOptions && series.curvedLines.apply == true && series.originSeries === undefined && nrPoints > (1 + EPSILON)) {\n" \
"				if (series.lines.fill) {\n" \
"\n" \
"					var pointsTop = calculateCurvePoints(datapoints, series.curvedLines, 1);\n" \
"					var pointsBottom = calculateCurvePoints(datapoints, series.curvedLines, 2);\n" \
"					//flot makes sure for us that we've got a second y point if fill is true !\n" \
"\n" \
"					//Merge top and bottom curve\n" \
"					datapoints.pointsize = 3;\n" \
"					datapoints.points = [];\n" \
"					var j = 0;\n" \
"					var k = 0;\n" \
"					var i = 0;\n" \
"					var ps = 2;\n" \
"					while (i < pointsTop.length || j < pointsBottom.length) {\n" \
"						if (pointsTop[i] == pointsBottom[j]) {\n" \
"							datapoints.points[k] = pointsTop[i];\n" \
"							datapoints.points[k + 1] = pointsTop[i + 1];\n" \
"							datapoints.points[k + 2] = pointsBottom[j + 1];\n" \
"							j += ps;\n" \
"							i += ps;\n" \
"\n" \
"						} else if (pointsTop[i] < pointsBottom[j]) {\n" \
"							datapoints.points[k] = pointsTop[i];\n" \
"							datapoints.points[k + 1] = pointsTop[i + 1];\n" \
"							datapoints.points[k + 2] = k > 0 ? datapoints.points[k - 1] : null;\n" \
"							i += ps;\n" \
"						} else {\n" \
"							datapoints.points[k] = pointsBottom[j];\n" \
"							datapoints.points[k + 1] = k > 1 ? datapoints.points[k - 2] : null;\n" \
"							datapoints.points[k + 2] = pointsBottom[j + 1];\n" \
"							j += ps;\n" \
"						}\n" \
"						k += 3;\n" \
"					}\n" \
"				} else if (series.lines.lineWidth > 0) {\n" \
"					datapoints.points = calculateCurvePoints(datapoints, series.curvedLines, 1);\n" \
"					datapoints.pointsize = 2;\n" \
"				}\n" \
"			}\n" \
"		}\n" \
"\n" \
"		function calculateCurvePoints(datapoints, curvedLinesOptions, yPos) {\n" \
"			if ( typeof curvedLinesOptions.legacyOverride != 'undefined' && curvedLinesOptions.legacyOverride != false) {\n" \
"				var defaultOptions = {\n" \
"					fit : false,\n" \
"					curvePointFactor : 20,\n" \
"					fitPointDist : undefined\n" \
"				};\n" \
"				var legacyOptions = jQuery.extend(defaultOptions, curvedLinesOptions.legacyOverride);\n" \
"				return calculateLegacyCurvePoints(datapoints, legacyOptions, yPos);\n" \
"			}\n" \
"\n" \
"			return calculateSplineCurvePoints(datapoints, curvedLinesOptions, yPos);\n" \
"		}\n" \
"\n" \
"		function calculateSplineCurvePoints(datapoints, curvedLinesOptions, yPos) {\n" \
"			var points = datapoints.points;\n" \
"			var ps = datapoints.pointsize;\n" \
"			\n" \
"			//create interpolant fuction\n" \
"			var splines = createHermiteSplines(datapoints, curvedLinesOptions, yPos);\n" \
"			var result = [];\n" \
"\n" \
"			//sample the function\n" \
"			// (the result is intependent from the input data =>\n" \
"			//	it is ok to alter the input after this method)\n" \
"			var j = 0;\n" \
"			for (var i = 0; i < points.length - ps; i += ps) {\n" \
"				var curX = i;\n" \
"				var curY = i + yPos;	\n" \
"				\n" \
"				var xStart = points[curX];\n" \
"				var xEnd = points[curX + ps];\n" \
"				var xStep = (xEnd - xStart) / Number(curvedLinesOptions.nrSplinePoints);\n" \
"\n" \
"				//add point\n" \
"				result.push(points[curX]);\n" \
"				result.push(points[curY]);\n" \
"\n" \
"				//add curve point\n" \
"				for (var x = (xStart += xStep); x < xEnd; x += xStep) {\n" \
"					result.push(x);\n" \
"					result.push(splines[j](x));\n" \
"				}\n" \
"				\n" \
"				j++;\n" \
"			}\n" \
"\n" \
"			//add last point\n" \
"			result.push(points[points.length - ps]);\n" \
"			result.push(points[points.length - ps + yPos]);\n" \
"\n" \
"			return result;\n" \
"		}\n" \
"\n" \
"\n" \
"\n" \
"		// Creates an array of splines, one for each segment of the original curve. Algorithm based on the wikipedia articles: \n" \
"		//\n" \
"		// http://de.wikipedia.org/w/index.php?title=Kubisch_Hermitescher_Spline&oldid=130168003 and \n" \
"		// http://en.wikipedia.org/w/index.php?title=Monotone_cubic_interpolation&oldid=622341725 and the description of Fritsch-Carlson from\n" \
"		// http://math.stackexchange.com/questions/45218/implementation-of-monotone-cubic-interpolation\n" \
"		// for a detailed description see https://github.com/MichaelZinsmaier/CurvedLines/docu\n" \
"		function createHermiteSplines(datapoints, curvedLinesOptions, yPos) {\n" \
"			var points = datapoints.points;\n" \
"			var ps = datapoints.pointsize;\n" \
"			\n" \
"			// preparation get length (x_{k+1} - x_k) and slope s=(p_{k+1} - p_k) / (x_{k+1} - x_k) of the segments\n" \
"			var segmentLengths = [];\n" \
"			var segmentSlopes = [];\n" \
"\n" \
"			for (var i = 0; i < points.length - ps; i += ps) {\n" \
"				var curX = i;\n" \
"				var curY = i + yPos;			\n" \
"				var dx = points[curX + ps] - points[curX];\n" \
"				var dy = points[curY + ps] - points[curY];\n" \
"							\n" \
"				segmentLengths.push(dx);\n" \
"				segmentSlopes.push(dy / dx);\n" \
"			}\n" \
"\n" \
"			//get the values for the desired gradients  m_k for all points k\n" \
"			//depending on the used method the formula is different\n" \
"			var gradients = [segmentSlopes[0]];	\n" \
"			if (curvedLinesOptions.monotonicFit) {\n" \
"				// Fritsch Carlson\n" \
"				for (var i = 1; i < segmentLengths.length; i++) {\n" \
"					var slope = segmentSlopes[i];\n" \
"					var prev_slope = segmentSlopes[i - 1];\n" \
"					if (slope * prev_slope <= 0) { // sign(prev_slope) != sign(slpe)\n" \
"						gradients.push(0);\n" \
"					} else {\n" \
"						var length = segmentLengths[i];\n" \
"						var prev_length = segmentLengths[i - 1];\n" \
"						var common = length + prev_length;\n" \
"						//m = 3 (prev_length + length) / ((2 length + prev_length) / prev_slope + (length + 2 prev_length) / slope)\n" \
"						gradients.push(3 * common / ((common + length) / prev_slope + (common + prev_length) / slope));\n" \
"					}\n" \
"				}\n" \
"			} else {\n" \
"				// Cardinal spline with t € [0,1]\n" \
"				// Catmull-Rom for t = 0\n" \
"				for (var i = ps; i < points.length - ps; i += ps) {\n" \
"					var curX = i;\n" \
"					var curY = i + yPos;	\n" \
"					gradients.push(Number(curvedLinesOptions.tension) * (points[curY + ps] - points[curY - ps]) / (points[curX + ps] - points[curX - ps]));\n" \
"				}\n" \
"			}\n" \
"			gradients.push(segmentSlopes[segmentSlopes.length - 1]);\n" \
"\n" \
"			//get the two major coefficients (c'_{oef1} and c'_{oef2}) for each segment spline\n" \
"			var coefs1 = [];\n" \
"			var coefs2 = [];\n" \
"			for (i = 0; i < segmentLengths.length; i++) {\n" \
"				var m_k = gradients[i];\n" \
"				var m_k_plus = gradients[i + 1];\n" \
"				var slope = segmentSlopes[i];\n" \
"				var invLength = 1 / segmentLengths[i];\n" \
"				var common = m_k + m_k_plus - slope - slope;\n" \
"				\n" \
"				coefs1.push(common * invLength * invLength);\n" \
"				coefs2.push((slope - common - m_k) * invLength);\n" \
"			}\n" \
"\n" \
"			//create functions with from the coefficients and capture the parameters\n" \
"			var ret = [];\n" \
"			for (var i = 0; i < segmentLengths.length; i ++) {\n" \
"				var spline = function (x_k, coef1, coef2, coef3, coef4) {\n" \
"					// spline for a segment\n" \
"					return function (x) {									\n" \
"						var diff = x - x_k;\n" \
"						var diffSq = diff * diff;\n" \
"						return coef1 * diff * diffSq + coef2 * diffSq + coef3 * diff + coef4;\n" \
"					};\n" \
"				};			\n" \
"		\n" \
"				ret.push(spline(points[i * ps], coefs1[i], coefs2[i], gradients[i], points[i * ps + yPos]));\n" \
"			}\n" \
"			\n" \
"			return ret;\n" \
"		};\n" \
"\n" \
"		//no real idea whats going on here code mainly from https://code.google.com/p/flot/issues/detail?id=226\n" \
"		//if fit option is selected additional datapoints get inserted before the curve calculations in nergal.dev s code.\n" \
"		function calculateLegacyCurvePoints(datapoints, curvedLinesOptions, yPos) {\n" \
"\n" \
"			var points = datapoints.points;\n" \
"			var ps = datapoints.pointsize;\n" \
"			var num = Number(curvedLinesOptions.curvePointFactor) * (points.length / ps);\n" \
"\n" \
"			var xdata = new Array;\n" \
"			var ydata = new Array;\n" \
"\n" \
"			var curX = -1;\n" \
"			var curY = -1;\n" \
"			var j = 0;\n" \
"\n" \
"			if (curvedLinesOptions.fit) {\n" \
"				//insert a point before and after the \"real\" data point to force the line\n" \
"				//to have a max,min at the data point.\n" \
"\n" \
"				var fpDist;\n" \
"				if ( typeof curvedLinesOptions.fitPointDist == 'undefined') {\n" \
"					//estimate it\n" \
"					var minX = points[0];\n" \
"					var maxX = points[points.length - ps];\n" \
"					fpDist = (maxX - minX) / (500 * 100);\n" \
"					//x range / (estimated pixel length of placeholder * factor)\n" \
"				} else {\n" \
"					//use user defined value\n" \
"					fpDist = Number(curvedLinesOptions.fitPointDist);\n" \
"				}\n" \
"\n" \
"				for (var i = 0; i < points.length; i += ps) {\n" \
"\n" \
"					var frontX;\n" \
"					var backX;\n" \
"					curX = i;\n" \
"					curY = i + yPos;\n" \
"\n" \
"					//add point X s\n" \
"					frontX = points[curX] - fpDist;\n" \
"					backX = points[curX] + fpDist;\n" \
"\n" \
"					var factor = 2;\n" \
"					while (frontX == points[curX] || backX == points[curX]) {\n" \
"						//inside the ulp\n" \
"						frontX = points[curX] - (fpDist * factor);\n" \
"						backX = points[curX] + (fpDist * factor);\n" \
"						factor++;\n" \
"					}\n" \
"\n" \
"					//add curve points\n" \
"					xdata[j] = frontX;\n" \
"					ydata[j] = points[curY];\n" \
"					j++;\n" \
"\n" \
"					xdata[j] = points[curX];\n" \
"					ydata[j] = points[curY];\n" \
"					j++;\n" \
"\n" \
"					xdata[j] = backX;\n" \
"					ydata[j] = points[curY];\n" \
"					j++;\n" \
"				}\n" \
"			} else {\n" \
"				//just use the datapoints\n" \
"				for (var i = 0; i < points.length; i += ps) {\n" \
"					curX = i;\n" \
"					curY = i + yPos;\n" \
"\n" \
"					xdata[j] = points[curX];\n" \
"					ydata[j] = points[curY];\n" \
"					j++;\n" \
"				}\n" \
"			}\n" \
"\n" \
"			var n = xdata.length;\n" \
"\n" \
"			var y2 = new Array();\n" \
"			var delta = new Array();\n" \
"			y2[0] = 0;\n" \
"			y2[n - 1] = 0;\n" \
"			delta[0] = 0;\n" \
"\n" \
"			for (var i = 1; i < n - 1; ++i) {\n" \
"				var d = (xdata[i + 1] - xdata[i - 1]);\n" \
"				if (d == 0) {\n" \
"					//point before current point and after current point need some space in between\n" \
"					return [];\n" \
"				}\n" \
"\n" \
"				var s = (xdata[i] - xdata[i - 1]) / d;\n" \
"				var p = s * y2[i - 1] + 2;\n" \
"				y2[i] = (s - 1) / p;\n" \
"				delta[i] = (ydata[i + 1] - ydata[i]) / (xdata[i + 1] - xdata[i]) - (ydata[i] - ydata[i - 1]) / (xdata[i] - xdata[i - 1]);\n" \
"				delta[i] = (6 * delta[i] / (xdata[i + 1] - xdata[i - 1]) - s * delta[i - 1]) / p;\n" \
"			}\n" \
"\n" \
"			for (var j = n - 2; j >= 0; --j) {\n" \
"				y2[j] = y2[j] * y2[j + 1] + delta[j];\n" \
"			}\n" \
"\n" \
"			//   xmax  - xmin  / #points\n" \
"			var step = (xdata[n - 1] - xdata[0]) / (num - 1);\n" \
"\n" \
"			var xnew = new Array;\n" \
"			var ynew = new Array;\n" \
"			var result = new Array;\n" \
"\n" \
"			xnew[0] = xdata[0];\n" \
"			ynew[0] = ydata[0];\n" \
"\n" \
"			result.push(xnew[0]);\n" \
"			result.push(ynew[0]);\n" \
"\n" \
"			for ( j = 1; j < num; ++j) {\n" \
"				//new x point (sampling point for the created curve)\n" \
"				xnew[j] = xnew[0] + j * step;\n" \
"\n" \
"				var max = n - 1;\n" \
"				var min = 0;\n" \
"\n" \
"				while (max - min > 1) {\n" \
"					var k = Math.round((max + min) / 2);\n" \
"					if (xdata[k] > xnew[j]) {\n" \
"						max = k;\n" \
"					} else {\n" \
"						min = k;\n" \
"					}\n" \
"				}\n" \
"\n" \
"				//found point one to the left and one to the right of generated new point\n" \
"				var h = (xdata[max] - xdata[min]);\n" \
"\n" \
"				if (h == 0) {\n" \
"					//similar to above two points from original x data need some space between them\n" \
"					return [];\n" \
"				}\n" \
"\n" \
"				var a = (xdata[max] - xnew[j]) / h;\n" \
"				var b = (xnew[j] - xdata[min]) / h;\n" \
"\n" \
"				ynew[j] = a * ydata[min] + b * ydata[max] + ((a * a * a - a) * y2[min] + (b * b * b - b) * y2[max]) * (h * h) / 6;\n" \
"\n" \
"				result.push(xnew[j]);\n" \
"				result.push(ynew[j]);\n" \
"			}\n" \
"\n" \
"			return result;\n" \
"		}\n" \
"		\n" \
"		function hasInvalidParameters(curvedLinesOptions) {\n" \
"			if (typeof curvedLinesOptions.fit != 'undefined' ||\n" \
"			    typeof curvedLinesOptions.curvePointFactor != 'undefined' ||\n" \
"			    typeof curvedLinesOptions.fitPointDist != 'undefined') {\n" \
"			    	throw new Error(\"CurvedLines detected illegal parameters. The CurvedLines API changed with version 1.0.0 please check the options object.\");\n" \
"			    	return true;\n" \
"			    }\n" \
"			return false;\n" \
"		}\n" \
"		\n" \
"\n" \
"	}//end init\n" \
"\n" \
"\n" \
"	$.plot.plugins.push({\n" \
"		init : init,\n" \
"		options : options,\n" \
"		name : 'curvedLines',\n" \
"		version : '1.1.1'\n" \
"	});\n" \
"\n" \
"})(jQuery);\n" \
"\n" \


#define DATA_LEN_2 "16336"

#define DATA_3  \
"/*\n" \
"Axis Labels Plugin for flot.\n" \
"http://github.com/markrcote/flot-axislabels\n" \
"\n" \
"Original code is Copyright (c) 2010 Xuan Luo.\n" \
"Original code was released under the GPLv3 license by Xuan Luo, September 2010.\n" \
"Original code was rereleased under the MIT license by Xuan Luo, April 2012.\n" \
"\n" \
"Permission is hereby granted, free of charge, to any person obtaining\n" \
"a copy of this software and associated documentation files (the\n" \
"\"Software\"), to deal in the Software without restriction, including\n" \
"without limitation the rights to use, copy, modify, merge, publish,\n" \
"distribute, sublicense, and/or sell copies of the Software, and to\n" \
"permit persons to whom the Software is furnished to do so, subject to\n" \
"the following conditions:\n" \
"\n" \
"The above copyright notice and this permission notice shall be\n" \
"included in all copies or substantial portions of the Software.\n" \
"\n" \
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,\n" \
"EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF\n" \
"MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND\n" \
"NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE\n" \
"LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION\n" \
"OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION\n" \
"WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n" \
" */\n" \
"\n" \
"(function ($) {\n" \
"    var options = {\n" \
"      axisLabels: {\n" \
"        show: true\n" \
"      }\n" \
"    };\n" \
"\n" \
"    function canvasSupported() {\n" \
"        return !!document.createElement('canvas').getContext;\n" \
"    }\n" \
"\n" \
"    function canvasTextSupported() {\n" \
"        if (!canvasSupported()) {\n" \
"            return false;\n" \
"        }\n" \
"        var dummy_canvas = document.createElement('canvas');\n" \
"        var context = dummy_canvas.getContext('2d');\n" \
"        return typeof context.fillText == 'function';\n" \
"    }\n" \
"\n" \
"    function css3TransitionSupported() {\n" \
"        var div = document.createElement('div');\n" \
"        return typeof div.style.MozTransition != 'undefined'    // Gecko\n" \
"            || typeof div.style.OTransition != 'undefined'      // Opera\n" \
"            || typeof div.style.webkitTransition != 'undefined' // WebKit\n" \
"            || typeof div.style.transition != 'undefined';\n" \
"    }\n" \
"\n" \
"\n" \
"    function AxisLabel(axisName, position, padding, plot, opts) {\n" \
"        this.axisName = axisName;\n" \
"        this.position = position;\n" \
"        this.padding = padding;\n" \
"        this.plot = plot;\n" \
"        this.opts = opts;\n" \
"        this.width = 0;\n" \
"        this.height = 0;\n" \
"    }\n" \
"\n" \
"    AxisLabel.prototype.cleanup = function() {\n" \
"    };\n" \
"\n" \
"\n" \
"    CanvasAxisLabel.prototype = new AxisLabel();\n" \
"    CanvasAxisLabel.prototype.constructor = CanvasAxisLabel;\n" \
"    function CanvasAxisLabel(axisName, position, padding, plot, opts) {\n" \
"        AxisLabel.prototype.constructor.call(this, axisName, position, padding,\n" \
"                                             plot, opts);\n" \
"    }\n" \
"\n" \
"    CanvasAxisLabel.prototype.calculateSize = function() {\n" \
"        if (!this.opts.axisLabelFontSizePixels)\n" \
"            this.opts.axisLabelFontSizePixels = 14;\n" \
"        if (!this.opts.axisLabelFontFamily)\n" \
"            this.opts.axisLabelFontFamily = 'sans-serif';\n" \
"\n" \
"        var textWidth = this.opts.axisLabelFontSizePixels + this.padding;\n" \
"        var textHeight = this.opts.axisLabelFontSizePixels + this.padding;\n" \
"        if (this.position == 'left' || this.position == 'right') {\n" \
"            this.width = this.opts.axisLabelFontSizePixels + this.padding;\n" \
"            this.height = 0;\n" \
"        } else {\n" \
"            this.width = 0;\n" \
"            this.height = this.opts.axisLabelFontSizePixels + this.padding;\n" \
"        }\n" \
"    };\n" \
"\n" \
"    CanvasAxisLabel.prototype.draw = function(box) {\n" \
"        if (!this.opts.axisLabelColour)\n" \
"            this.opts.axisLabelColour = 'black';\n" \
"        var ctx = this.plot.getCanvas().getContext('2d');\n" \
"        ctx.save();\n" \
"        ctx.font = this.opts.axisLabelFontSizePixels + 'px ' +\n" \
"            this.opts.axisLabelFontFamily;\n" \
"        ctx.fillStyle = this.opts.axisLabelColour;\n" \
"        var width = ctx.measureText(this.opts.axisLabel).width;\n" \
"        var height = this.opts.axisLabelFontSizePixels;\n" \
"        var x, y, angle = 0;\n" \
"        if (this.position == 'top') {\n" \
"            x = box.left + box.width/2 - width/2;\n" \
"            y = box.top + height*0.72;\n" \
"        } else if (this.position == 'bottom') {\n" \
"            x = box.left + box.width/2 - width/2;\n" \
"            y = box.top + box.height - height*0.72;\n" \
"        } else if (this.position == 'left') {\n" \
"            x = box.left + height*0.72;\n" \
"            y = box.height/2 + box.top + width/2;\n" \
"            angle = -Math.PI/2;\n" \
"        } else if (this.position == 'right') {\n" \
"            x = box.left + box.width - height*0.72;\n" \
"            y = box.height/2 + box.top - width/2;\n" \
"            angle = Math.PI/2;\n" \
"        }\n" \
"        ctx.translate(x, y);\n" \
"        ctx.rotate(angle);\n" \
"        ctx.fillText(this.opts.axisLabel, 0, 0);\n" \
"        ctx.restore();\n" \
"    };\n" \
"\n" \
"\n" \
"    HtmlAxisLabel.prototype = new AxisLabel();\n" \
"    HtmlAxisLabel.prototype.constructor = HtmlAxisLabel;\n" \
"    function HtmlAxisLabel(axisName, position, padding, plot, opts) {\n" \
"        AxisLabel.prototype.constructor.call(this, axisName, position,\n" \
"                                             padding, plot, opts);\n" \
"        this.elem = null;\n" \
"    }\n" \
"\n" \
"    HtmlAxisLabel.prototype.calculateSize = function() {\n" \
"        var elem = $('<div class=\"axisLabels\" style=\"position:absolute;\">' +\n" \
"                     this.opts.axisLabel + '</div>');\n" \
"        this.plot.getPlaceholder().append(elem);\n" \
"        // store height and width of label itself, for use in draw()\n" \
"        this.labelWidth = elem.outerWidth(true);\n" \
"        this.labelHeight = elem.outerHeight(true);\n" \
"        elem.remove();\n" \
"\n" \
"        this.width = this.height = 0;\n" \
"        if (this.position == 'left' || this.position == 'right') {\n" \
"            this.width = this.labelWidth + this.padding;\n" \
"        } else {\n" \
"            this.height = this.labelHeight + this.padding;\n" \
"        }\n" \
"    };\n" \
"\n" \
"    HtmlAxisLabel.prototype.cleanup = function() {\n" \
"        if (this.elem) {\n" \
"            this.elem.remove();\n" \
"        }\n" \
"    };\n" \
"\n" \
"    HtmlAxisLabel.prototype.draw = function(box) {\n" \
"        this.plot.getPlaceholder().find('#' + this.axisName + 'Label').remove();\n" \
"        this.elem = $('<div id=\"' + this.axisName +\n" \
"                      'Label\" \" class=\"axisLabels\" style=\"position:absolute;\">'\n" \
"                      + this.opts.axisLabel + '</div>');\n" \
"        this.plot.getPlaceholder().append(this.elem);\n" \
"        if (this.position == 'top') {\n" \
"            this.elem.css('left', box.left + box.width/2 - this.labelWidth/2 +\n" \
"                          'px');\n" \
"            this.elem.css('top', box.top + 'px');\n" \
"        } else if (this.position == 'bottom') {\n" \
"            this.elem.css('left', box.left + box.width/2 - this.labelWidth/2 +\n" \
"                          'px');\n" \
"            this.elem.css('top', box.top + box.height - this.labelHeight +\n" \
"                          'px');\n" \
"        } else if (this.position == 'left') {\n" \
"            this.elem.css('top', box.top + box.height/2 - this.labelHeight/2 +\n" \
"                          'px');\n" \
"            this.elem.css('left', box.left + 'px');\n" \
"        } else if (this.position == 'right') {\n" \
"            this.elem.css('top', box.top + box.height/2 - this.labelHeight/2 +\n" \
"                          'px');\n" \
"            this.elem.css('left', box.left + box.width - this.labelWidth +\n" \
"                          'px');\n" \
"        }\n" \
"    };\n" \
"\n" \
"\n" \
"    CssTransformAxisLabel.prototype = new HtmlAxisLabel();\n" \
"    CssTransformAxisLabel.prototype.constructor = CssTransformAxisLabel;\n" \
"    function CssTransformAxisLabel(axisName, position, padding, plot, opts) {\n" \
"        HtmlAxisLabel.prototype.constructor.call(this, axisName, position,\n" \
"                                                 padding, plot, opts);\n" \
"    }\n" \
"\n" \
"    CssTransformAxisLabel.prototype.calculateSize = function() {\n" \
"        HtmlAxisLabel.prototype.calculateSize.call(this);\n" \
"        this.width = this.height = 0;\n" \
"        if (this.position == 'left' || this.position == 'right') {\n" \
"            this.width = this.labelHeight + this.padding;\n" \
"        } else {\n" \
"            this.height = this.labelHeight + this.padding;\n" \
"        }\n" \
"    };\n" \
"\n" \
"    CssTransformAxisLabel.prototype.transforms = function(degrees, x, y) {\n" \
"        var stransforms = {\n" \
"            '-moz-transform': '',\n" \
"            '-webkit-transform': '',\n" \
"            '-o-transform': '',\n" \
"            '-ms-transform': ''\n" \
"        };\n" \
"        if (x != 0 || y != 0) {\n" \
"            var stdTranslate = ' translate(' + x + 'px, ' + y + 'px)';\n" \
"            stransforms['-moz-transform'] += stdTranslate;\n" \
"            stransforms['-webkit-transform'] += stdTranslate;\n" \
"            stransforms['-o-transform'] += stdTranslate;\n" \
"            stransforms['-ms-transform'] += stdTranslate;\n" \
"        }\n" \
"        if (degrees != 0) {\n" \
"            var rotation = degrees / 90;\n" \
"            var stdRotate = ' rotate(' + degrees + 'deg)';\n" \
"            stransforms['-moz-transform'] += stdRotate;\n" \
"            stransforms['-webkit-transform'] += stdRotate;\n" \
"            stransforms['-o-transform'] += stdRotate;\n" \
"            stransforms['-ms-transform'] += stdRotate;\n" \
"        }\n" \
"        var s = 'top: 0; left: 0; ';\n" \
"        for (var prop in stransforms) {\n" \
"            if (stransforms[prop]) {\n" \
"                s += prop + ':' + stransforms[prop] + ';';\n" \
"            }\n" \
"        }\n" \
"        s += ';';\n" \
"        return s;\n" \
"    };\n" \
"\n" \
"    CssTransformAxisLabel.prototype.calculateOffsets = function(box) {\n" \
"        var offsets = { x: 0, y: 0, degrees: 0 };\n" \
"        if (this.position == 'bottom') {\n" \
"            offsets.x = box.left + box.width/2 - this.labelWidth/2;\n" \
"            offsets.y = box.top + box.height - this.labelHeight;\n" \
"        } else if (this.position == 'top') {\n" \
"            offsets.x = box.left + box.width/2 - this.labelWidth/2;\n" \
"            offsets.y = box.top;\n" \
"        } else if (this.position == 'left') {\n" \
"            offsets.degrees = -90;\n" \
"            offsets.x = box.left - this.labelWidth/2 + this.labelHeight/2;\n" \
"            offsets.y = box.height/2 + box.top;\n" \
"        } else if (this.position == 'right') {\n" \
"            offsets.degrees = 90;\n" \
"            offsets.x = box.left + box.width - this.labelWidth/2\n" \
"                        - this.labelHeight/2;\n" \
"            offsets.y = box.height/2 + box.top;\n" \
"        }\n" \
"        offsets.x = Math.round(offsets.x);\n" \
"        offsets.y = Math.round(offsets.y);\n" \
"\n" \
"        return offsets;\n" \
"    };\n" \
"\n" \
"    CssTransformAxisLabel.prototype.draw = function(box) {\n" \
"        this.plot.getPlaceholder().find(\".\" + this.axisName + \"Label\").remove();\n" \
"        var offsets = this.calculateOffsets(box);\n" \
"        this.elem = $('<div class=\"axisLabels ' + this.axisName +\n" \
"                      'Label\" style=\"position:absolute; ' +\n" \
"                      this.transforms(offsets.degrees, offsets.x, offsets.y) +\n" \
"                      '\">' + this.opts.axisLabel + '</div>');\n" \
"        this.plot.getPlaceholder().append(this.elem);\n" \
"    };\n" \
"\n" \
"\n" \
"    IeTransformAxisLabel.prototype = new CssTransformAxisLabel();\n" \
"    IeTransformAxisLabel.prototype.constructor = IeTransformAxisLabel;\n" \
"    function IeTransformAxisLabel(axisName, position, padding, plot, opts) {\n" \
"        CssTransformAxisLabel.prototype.constructor.call(this, axisName,\n" \
"                                                         position, padding,\n" \
"                                                         plot, opts);\n" \
"        this.requiresResize = false;\n" \
"    }\n" \
"\n" \
"    IeTransformAxisLabel.prototype.transforms = function(degrees, x, y) {\n" \
"        // I didn't feel like learning the crazy Matrix stuff, so this uses\n" \
"        // a combination of the rotation transform and CSS positioning.\n" \
"        var s = '';\n" \
"        if (degrees != 0) {\n" \
"            var rotation = degrees/90;\n" \
"            while (rotation < 0) {\n" \
"                rotation += 4;\n" \
"            }\n" \
"            s += ' filter: progid:DXImageTransform.Microsoft.BasicImage(rotation=' + rotation + '); ';\n" \
"            // see below\n" \
"            this.requiresResize = (this.position == 'right');\n" \
"        }\n" \
"        if (x != 0) {\n" \
"            s += 'left: ' + x + 'px; ';\n" \
"        }\n" \
"        if (y != 0) {\n" \
"            s += 'top: ' + y + 'px; ';\n" \
"        }\n" \
"        return s;\n" \
"    };\n" \
"\n" \
"    IeTransformAxisLabel.prototype.calculateOffsets = function(box) {\n" \
"        var offsets = CssTransformAxisLabel.prototype.calculateOffsets.call(\n" \
"                          this, box);\n" \
"        // adjust some values to take into account differences between\n" \
"        // CSS and IE rotations.\n" \
"        if (this.position == 'top') {\n" \
"            // FIXME: not sure why, but placing this exactly at the top causes\n" \
"            // the top axis label to flip to the bottom...\n" \
"            offsets.y = box.top + 1;\n" \
"        } else if (this.position == 'left') {\n" \
"            offsets.x = box.left;\n" \
"            offsets.y = box.height/2 + box.top - this.labelWidth/2;\n" \
"        } else if (this.position == 'right') {\n" \
"            offsets.x = box.left + box.width - this.labelHeight;\n" \
"            offsets.y = box.height/2 + box.top - this.labelWidth/2;\n" \
"        }\n" \
"        return offsets;\n" \
"    };\n" \
"\n" \
"    IeTransformAxisLabel.prototype.draw = function(box) {\n" \
"        CssTransformAxisLabel.prototype.draw.call(this, box);\n" \
"        if (this.requiresResize) {\n" \
"            this.elem = this.plot.getPlaceholder().find(\".\" + this.axisName +\n" \
"                                                        \"Label\");\n" \
"            // Since we used CSS positioning instead of transforms for\n" \
"            // translating the element, and since the positioning is done\n" \
"            // before any rotations, we have to reset the width and height\n" \
"            // in case the browser wrapped the text (specifically for the\n" \
"            // y2axis).\n" \
"            this.elem.css('width', this.labelWidth);\n" \
"            this.elem.css('height', this.labelHeight);\n" \
"        }\n" \
"    };\n" \
"\n" \
"\n" \
"    function init(plot) {\n" \
"        plot.hooks.processOptions.push(function (plot, options) {\n" \
"\n" \
"            if (!options.axisLabels.show)\n" \
"                return;\n" \
"\n" \
"            // This is kind of a hack. There are no hooks in Flot between\n" \
"            // the creation and measuring of the ticks (setTicks, measureTickLabels\n" \
"            // in setupGrid() ) and the drawing of the ticks and plot box\n" \
"            // (insertAxisLabels in setupGrid() ).\n" \
"            //\n" \
"            // Therefore, we use a trick where we run the draw routine twice:\n" \
"            // the first time to get the tick measurements, so that we can change\n" \
"            // them, and then have it draw it again.\n" \
"            var secondPass = false;\n" \
"\n" \
"            var axisLabels = {};\n" \
"            var axisOffsetCounts = { left: 0, right: 0, top: 0, bottom: 0 };\n" \
"\n" \
"            var defaultPadding = 2;  // padding between axis and tick labels\n" \
"            plot.hooks.draw.push(function (plot, ctx) {\n" \
"                var hasAxisLabels = false;\n" \
"                if (!secondPass) {\n" \
"                    // MEASURE AND SET OPTIONS\n" \
"                    $.each(plot.getAxes(), function(axisName, axis) {\n" \
"                        var opts = axis.options // Flot 0.7\n" \
"                            || plot.getOptions()[axisName]; // Flot 0.6\n" \
"\n" \
"                        // Handle redraws initiated outside of this plug-in.\n" \
"                        if (axisName in axisLabels) {\n" \
"                            axis.labelHeight = axis.labelHeight -\n" \
"                                axisLabels[axisName].height;\n" \
"                            axis.labelWidth = axis.labelWidth -\n" \
"                                axisLabels[axisName].width;\n" \
"                            opts.labelHeight = axis.labelHeight;\n" \
"                            opts.labelWidth = axis.labelWidth;\n" \
"                            axisLabels[axisName].cleanup();\n" \
"                            delete axisLabels[axisName];\n" \
"                        }\n" \
"\n" \
"                        if (!opts || !opts.axisLabel || !axis.show)\n" \
"                            return;\n" \
"\n" \
"                        hasAxisLabels = true;\n" \
"                        var renderer = null;\n" \
"\n" \
"                        if (!opts.axisLabelUseHtml &&\n" \
"                            navigator.appName == 'Microsoft Internet Explorer') {\n" \
"                            var ua = navigator.userAgent;\n" \
"                            var re  = new RegExp(\"MSIE ([0-9]{1,}[\\.0-9]{0,})\");\n" \
"                            if (re.exec(ua) != null) {\n" \
"                                rv = parseFloat(RegExp.$1);\n" \
"                            }\n" \
"                            if (rv >= 9 && !opts.axisLabelUseCanvas && !opts.axisLabelUseHtml) {\n" \
"                                renderer = CssTransformAxisLabel;\n" \
"                            } else if (!opts.axisLabelUseCanvas && !opts.axisLabelUseHtml) {\n" \
"                                renderer = IeTransformAxisLabel;\n" \
"                            } else if (opts.axisLabelUseCanvas) {\n" \
"                                renderer = CanvasAxisLabel;\n" \
"                            } else {\n" \
"                                renderer = HtmlAxisLabel;\n" \
"                            }\n" \
"                        } else {\n" \
"                            if (opts.axisLabelUseHtml || (!css3TransitionSupported() && !canvasTextSupported()) && !opts.axisLabelUseCanvas) {\n" \
"                                renderer = HtmlAxisLabel;\n" \
"                            } else if (opts.axisLabelUseCanvas || !css3TransitionSupported()) {\n" \
"                                renderer = CanvasAxisLabel;\n" \
"                            } else {\n" \
"                                renderer = CssTransformAxisLabel;\n" \
"                            }\n" \
"                        }\n" \
"\n" \
"                        var padding = opts.axisLabelPadding === undefined ?\n" \
"                                      defaultPadding : opts.axisLabelPadding;\n" \
"\n" \
"                        axisLabels[axisName] = new renderer(axisName,\n" \
"                                                            axis.position, padding,\n" \
"                                                            plot, opts);\n" \
"\n" \
"                        // flot interprets axis.labelHeight and .labelWidth as\n" \
"                        // the height and width of the tick labels. We increase\n" \
"                        // these values to make room for the axis label and\n" \
"                        // padding.\n" \
"\n" \
"                        axisLabels[axisName].calculateSize();\n" \
"\n" \
"                        // AxisLabel.height and .width are the size of the\n" \
"                        // axis label and padding.\n" \
"                        // Just set opts here because axis will be sorted out on\n" \
"                        // the redraw.\n" \
"\n" \
"                        opts.labelHeight = axis.labelHeight +\n" \
"                            axisLabels[axisName].height;\n" \
"                        opts.labelWidth = axis.labelWidth +\n" \
"                            axisLabels[axisName].width;\n" \
"                    });\n" \
"\n" \
"                    // If there are axis labels, re-draw with new label widths and\n" \
"                    // heights.\n" \
"\n" \
"                    if (hasAxisLabels) {\n" \
"                        secondPass = true;\n" \
"                        plot.setupGrid();\n" \
"                        plot.draw();\n" \
"                    }\n" \
"                } else {\n" \
"                    secondPass = false;\n" \
"                    // DRAW\n" \
"                    $.each(plot.getAxes(), function(axisName, axis) {\n" \
"                        var opts = axis.options // Flot 0.7\n" \
"                            || plot.getOptions()[axisName]; // Flot 0.6\n" \
"                        if (!opts || !opts.axisLabel || !axis.show)\n" \
"                            return;\n" \
"\n" \
"                        axisLabels[axisName].draw(axis.box);\n" \
"                    });\n" \
"                }\n" \
"            });\n" \
"        });\n" \
"    }\n" \
"\n" \
"\n" \
"    $.plot.plugins.push({\n" \
"        init: init,\n" \
"        options: options,\n" \
"        name: 'axisLabels',\n" \
"        version: '2.0'\n" \
"    });\n" \
"})(jQuery);\n" \


#define DATA_LEN_3 "19542"

#define DATA_4  \
"/*\n" \
"    A simple jQuery modal (http://github.com/kylefox/jquery-modal)\n" \
"    Version 0.9.1\n" \
"*/\n" \
"!function(o){\"object\"==typeof module&&\"object\"==typeof module.exports?o(require(\"jquery\"),window,document):o(jQuery,window,document)}(function(o,t,i,e){var s=[],l=function(){return s.length?s[s.length-1]:null},n=function(){var o,t=!1;for(o=s.length-1;o>=0;o--)s[o].$blocker&&(s[o].$blocker.toggleClass(\"current\",!t).toggleClass(\"behind\",t),t=!0)};o.modal=function(t,i){var e,n;if(this.$body=o(\"body\"),this.options=o.extend({},o.modal.defaults,i),this.options.doFade=!isNaN(parseInt(this.options.fadeDuration,10)),this.$blocker=null,this.options.closeExisting)for(;o.modal.isActive();)o.modal.close();if(s.push(this),t.is(\"a\"))if(n=t.attr(\"href\"),this.anchor=t,/^#/.test(n)){if(this.$elm=o(n),1!==this.$elm.length)return null;this.$body.append(this.$elm),this.open()}else this.$elm=o(\"<div>\"),this.$body.append(this.$elm),e=function(o,t){t.elm.remove()},this.showSpinner(),t.trigger(o.modal.AJAX_SEND),o.get(n).done(function(i){if(o.modal.isActive()){t.trigger(o.modal.AJAX_SUCCESS);var s=l();s.$elm.empty().append(i).on(o.modal.CLOSE,e),s.hideSpinner(),s.open(),t.trigger(o.modal.AJAX_COMPLETE)}}).fail(function(){t.trigger(o.modal.AJAX_FAIL);var i=l();i.hideSpinner(),s.pop(),t.trigger(o.modal.AJAX_COMPLETE)});else this.$elm=t,this.anchor=t,this.$body.append(this.$elm),this.open()},o.modal.prototype={constructor:o.modal,open:function(){var t=this;this.block(),this.anchor.blur(),this.options.doFade?setTimeout(function(){t.show()},this.options.fadeDuration*this.options.fadeDelay):this.show(),o(i).off(\"keydown.modal\").on(\"keydown.modal\",function(o){var t=l();27===o.which&&t.options.escapeClose&&t.close()}),this.options.clickClose&&this.$blocker.click(function(t){t.target===this&&o.modal.close()})},close:function(){s.pop(),this.unblock(),this.hide(),o.modal.isActive()||o(i).off(\"keydown.modal\")},block:function(){this.$elm.trigger(o.modal.BEFORE_BLOCK,[this._ctx()]),this.$body.css(\"overflow\",\"hidden\"),this.$blocker=o('<div class=\"'+this.options.blockerClass+' blocker current\"></div>').appendTo(this.$body),n(),this.options.doFade&&this.$blocker.css(\"opacity\",0).animate({opacity:1},this.options.fadeDuration),this.$elm.trigger(o.modal.BLOCK,[this._ctx()])},unblock:function(t){!t&&this.options.doFade?this.$blocker.fadeOut(this.options.fadeDuration,this.unblock.bind(this,!0)):(this.$blocker.children().appendTo(this.$body),this.$blocker.remove(),this.$blocker=null,n(),o.modal.isActive()||this.$body.css(\"overflow\",\"\"))},show:function(){this.$elm.trigger(o.modal.BEFORE_OPEN,[this._ctx()]),this.options.showClose&&(this.closeButton=o('<a href=\"#close-modal\" rel=\"modal:close\" class=\"close-modal '+this.options.closeClass+'\">'+this.options.closeText+\"</a>\"),this.$elm.append(this.closeButton)),this.$elm.addClass(this.options.modalClass).appendTo(this.$blocker),this.options.doFade?this.$elm.css({opacity:0,display:\"inline-block\"}).animate({opacity:1},this.options.fadeDuration):this.$elm.css(\"display\",\"inline-block\"),this.$elm.trigger(o.modal.OPEN,[this._ctx()])},hide:function(){this.$elm.trigger(o.modal.BEFORE_CLOSE,[this._ctx()]),this.closeButton&&this.closeButton.remove();var t=this;this.options.doFade?this.$elm.fadeOut(this.options.fadeDuration,function(){t.$elm.trigger(o.modal.AFTER_CLOSE,[t._ctx()])}):this.$elm.hide(0,function(){t.$elm.trigger(o.modal.AFTER_CLOSE,[t._ctx()])}),this.$elm.trigger(o.modal.CLOSE,[this._ctx()])},showSpinner:function(){this.options.showSpinner&&(this.spinner=this.spinner||o('<div class=\"'+this.options.modalClass+'-spinner\"></div>').append(this.options.spinnerHtml),this.$body.append(this.spinner),this.spinner.show())},hideSpinner:function(){this.spinner&&this.spinner.remove()},_ctx:function(){return{elm:this.$elm,$elm:this.$elm,$blocker:this.$blocker,options:this.options}}},o.modal.close=function(t){if(o.modal.isActive()){t&&t.preventDefault();var i=l();return i.close(),i.$elm}},o.modal.isActive=function(){return s.length>0},o.modal.getCurrent=l,o.modal.defaults={closeExisting:!0,escapeClose:!0,clickClose:!0,closeText:\"Close\",closeClass:\"\",modalClass:\"modal\",blockerClass:\"jquery-modal\",spinnerHtml:'<div class=\"rect1\"></div><div class=\"rect2\"></div><div class=\"rect3\"></div><div class=\"rect4\"></div>',showSpinner:!0,showClose:!0,fadeDuration:null,fadeDelay:1},o.modal.BEFORE_BLOCK=\"modal:before-block\",o.modal.BLOCK=\"modal:block\",o.modal.BEFORE_OPEN=\"modal:before-open\",o.modal.OPEN=\"modal:open\",o.modal.BEFORE_CLOSE=\"modal:before-close\",o.modal.CLOSE=\"modal:close\",o.modal.AFTER_CLOSE=\"modal:after-close\",o.modal.AJAX_SEND=\"modal:ajax:send\",o.modal.AJAX_SUCCESS=\"modal:ajax:success\",o.modal.AJAX_FAIL=\"modal:ajax:fail\",o.modal.AJAX_COMPLETE=\"modal:ajax:complete\",o.fn.modal=function(t){return 1===this.length&&new o.modal(this,t),this},o(i).on(\"click.modal\",'a[rel~=\"modal:close\"]',o.modal.close),o(i).on(\"click.modal\",'a[rel~=\"modal:open\"]',function(t){t.preventDefault(),o(this).modal()})});" \


#define DATA_LEN_4 "4953"

#define DATA_5  \
".blocker{position:fixed;top:0;right:0;bottom:0;left:0;width:100%;height:100%;overflow:auto;z-index:1;padding:20px;box-sizing:border-box;background-color:#000;background-color:rgba(0,0,0,0.75);text-align:center}.blocker:before{content:\"\";display:inline-block;height:100%;vertical-align:middle;margin-right:-0.05em}.blocker.behind{background-color:transparent}.modal{display:none;vertical-align:middle;position:relative;z-index:2;max-width:500px;box-sizing:border-box;width:90%;background:#fff;padding:15px 30px;-webkit-border-radius:8px;-moz-border-radius:8px;-o-border-radius:8px;-ms-border-radius:8px;border-radius:8px;-webkit-box-shadow:0 0 10px #000;-moz-box-shadow:0 0 10px #000;-o-box-shadow:0 0 10px #000;-ms-box-shadow:0 0 10px #000;box-shadow:0 0 10px #000;text-align:left}.modal a.close-modal{position:absolute;top:-12.5px;right:-12.5px;display:block;width:30px;height:30px;text-indent:-9999px;background-size:contain;background-repeat:no-repeat;background-position:center center;background-image:url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADwAAAA8CAYAAAA6/NlyAAAAAXNSR0IArs4c6QAAA3hJREFUaAXlm8+K00Acx7MiCIJH/yw+gA9g25O49SL4AO3Bp1jw5NvktC+wF88qevK4BU97EmzxUBCEolK/n5gp3W6TTJPfpNPNF37MNsl85/vN/DaTmU6PknC4K+pniqeKJ3k8UnkvDxXJzzy+q/yaxxeVHxW/FNHjgRSeKt4rFoplzaAuHHDBGR2eS9G54reirsmienDCTRt7xwsp+KAoEmt9nLaGitZxrBbPFNaGfPloGw2t4JVamSt8xYW6Dg1oCYo3Yv+rCGViV160oMkcd8SYKnYV1Nb1aEOjCe6L5ZOiLfF120EjWhuBu3YIZt1NQmujnk5F4MgOpURzLfAwOBSTmzp3fpDxuI/pabxpqOoz2r2HLAb0GMbZKlNV5/Hg9XJypguryA7lPF5KMdTZQzHjqxNPhWhzIuAruOl1eNqKEx1tSh5rfbxdw7mOxCq4qS68ZTjKS1YVvilu559vWvFHhh4rZrdyZ69Vmpgdj8fJbDZLJpNJ0uv1cnr/gjrUhQMuI+ANjyuwftQ0bbL6Erp0mM/ny8Fg4M3LtdRxgMtKl3jwmIHVxYXChFy94/Rmpa/pTbNUhstKV+4Rr8lLQ9KlUvJKLyG8yvQ2s9SBy1Jb7jV5a0yapfF6apaZLjLLcWtd4sNrmJUMHyM+1xibTjH82Zh01TNlhsrOhdKTe00uAzZQmN6+KW+sDa/JD2PSVQ873m29yf+1Q9VDzfEYlHi1G5LKBBWZbtEsHbFwb1oYDwr1ZiF/2bnCSg1OBE/pfr9/bWx26UxJL3ONPISOLKUvQza0LZUxSKyjpdTGa/vDEr25rddbMM0Q3O6Lx3rqFvU+x6UrRKQY7tyrZecmD9FODy8uLizTmilwNj0kraNcAJhOp5aGVwsAGD5VmJBrWWbJSgWT9zrzWepQF47RaGSiKfeGx6Szi3gzmX/HHbihwBser4B9UJYpFBNX4R6vTn3VQnez0SymnrHQMsRYGTr1dSk34ljRqS/EMd2pLQ8YBp3a1PLfcqCpo8gtHkZFHKkTX6fs3MY0blKnth66rKCnU0VRGu37ONrQaA4eZDFtWAu2fXj9zjFkxTBOo8F7t926gTp/83Kyzzcy2kZD6xiqxTYnHLRFm3vHiRSwNSjkz3hoIzo8lCKWUlg/YtGs7tObunDAZfpDLbfEI15zsEIY3U/x/gHHc/G1zltnAgAAAABJRU5ErkJggg==')}.modal-spinner{display:none;position:fixed;top:50%;left:50%;transform:translateY(-50%) translateX(-50%);padding:12px 16px;border-radius:5px;background-color:#111;height:20px}.modal-spinner>div{border-radius:100px;background-color:#fff;height:20px;width:2px;margin:0 1px;display:inline-block;-webkit-animation:sk-stretchdelay 1.2s infinite ease-in-out;animation:sk-stretchdelay 1.2s infinite ease-in-out}.modal-spinner .rect2{-webkit-animation-delay:-1.1s;animation-delay:-1.1s}.modal-spinner .rect3{-webkit-animation-delay:-1.0s;animation-delay:-1.0s}.modal-spinner .rect4{-webkit-animation-delay:-0.9s;animation-delay:-0.9s}@-webkit-keyframes sk-stretchdelay{0%,40%,100%{-webkit-transform:scaleY(0.5)}20%{-webkit-transform:scaleY(1.0)}}@keyframes sk-stretchdelay{0%,40%,100%{transform:scaleY(0.5);-webkit-transform:scaleY(0.5)}20%{transform:scaleY(1.0);-webkit-transform:scaleY(1.0)}}" \


#define DATA_LEN_5 "3201"

#define DATA_6  \
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n" \
"<html>\n" \
"<head>\n" \
"    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n" \
"    <title>Network Activity</title>\n" \
"    <!-- <link href=\"flot/examples/examples.css\" rel=\"stylesheet\" type=\"text/css\"> -->\n" \
"    <script language=\"javascript\" type=\"text/javascript\" src=\"flot/jquery.js\"></script>\n" \
"    <script language=\"javascript\" type=\"text/javascript\" src=\"flot/jquery.flot.js\"></script>\n" \
"    <!-- <script src=\"https://cdn.rawgit.com/MichaelZinsmaier/CurvedLines/1.1.1/curvedLines.js\"></script> -->\n" \
"    <script src=\"plugin/curvedLines.js\"></script>\n" \
"    <script type=\"text/javascript\" src=\"plugin/jquery.flot.axislabels.js\"></script>\n" \
"    <script src=\"plugin/jquery.modal.min.js\"></script>\n" \
"    <link rel=\"stylesheet\" href=\"plugin/jquery.modal.min.css\" />\n" \
"    <style>\n" \
"\n" \
"    input.infoInput{\n" \
"        border: none;\n" \
"        border-bottom: transparent thin solid;\n" \
"    }\n" \
"    /*input.infoInput:hover{\n" \
"        border-bottom: gray thin solid;\n" \
"    }*/\n" \
"    input.infoInput:focus{\n" \
"        border-bottom: gray thin solid;\n" \
"    }\n" \
"    .placeholderparent{\n" \
"        /*width: 610px; */\n" \
"        /*height: 340px; */\n" \
"        margin: 5px;\n" \
"        border: 2px solid black;\n" \
"        padding: 5px;\n" \
"        float: left;\n" \
"    }\n" \
"    .legends{\n" \
"        width: 530px\n" \
"    }\n" \
"    .yaxis_width{\n" \
"        width: 30px;\n" \
"    }\n" \
"    .placeholder_tx {\n" \
"        width: 500px;\n" \
"        height: 150px;\n" \
"        overflow: hidden;\n" \
"        /*border: 2px solid black*/\n" \
"    }\n" \
"    .placeholder_rx {\n" \
"        width: 500px;\n" \
"        height: 150px;\n" \
"        /*overflow: hidden;*/\n" \
"        /*border: 2px solid black*/\n" \
"    }\n" \
"    .rx_tx_bytes_holder{\n" \
"        margin-left: 20px;\n" \
"        font-family: \"Courier New\", Courier, monospace;\n" \
"    }\n" \
"    .legendBox{\n" \
"        width:40px;\n" \
"        height:20px;\n" \
"    }\n" \
"    .block_view{\n" \
"        display: block;\n" \
"        float: left;\n" \
"    }\n" \
"    .flot-x-axis, .flot-x-axis .flot-tick-label{\n" \
"        height: 21px;\n" \
"        padding: 0;\n" \
"        margin: 0;\n" \
"    }\n" \
"    .yaxis{\n" \
"        -moz-transform: rotate(-90deg);\n" \
"        -webkit-transform: rotate(-90deg);\n" \
"        -o-transform: rotate(-90deg);\n" \
"        -ms-transform: rotate(-90deg);\n" \
"        transform: rotate(-90deg);\n" \
"        -moz-transform-origin: 0px 0px 0px;\n" \
"        -webkit-transform-origin: 0px 0px 0px;\n" \
"        -o-transform-origin: 0px 0px 0px;\n" \
"        -ms-transform-origin: 0px 0px 0px;\n" \
"        transform-origin: 0px 0px 0px;\n" \
"        position: absolute;\n" \
"        width: 300px;\n" \
"        text-align: center;\n" \
"\n" \
"    }\n" \
"    .xtick, .ytick {\n" \
"        font-size: 12px;\n" \
"        font-weight: bold;\n" \
"        height: 21px\n" \
"    }\n" \
"    .xtick_tx{\n" \
"        color: #fff;\n" \
"    }\n" \
"    tr, td{\n" \
"        padding: 0;\n" \
"    }\n" \
"    </style>\n" \
"</head>\n" \
"<body>\n" \
"    <!-- <div id=\"demotitle\" ><center><h1>Viscous: An End to End Protocol for Ubiquitous Communication Over Internet of Everything</h1><h2>Abhijit Mondal, Sandip Chakraborty</h2><h2>Dept of CSE, IIT Kharagpur, India 721302</h2><h2>Email: abhimondal@iitkgp.ac.in</h2></center></div> -->\n" \
"    <div id=\"demotitle\" ><center><h1>Remote Network Activity Monitor</h1></center></div>\n" \
"    <div id=\"container\"></div>\n" \
"    <div style=\"position: absolute; display: block; top: 10px; left: 10px\">\n" \
"        <button id=\"addServer\" title=\"Add a new server\">&#x2605;</button>\n" \
"        <!-- <select id=\"serverList\" title=\"Select Server\">\n" \
"            <option selected=\"selected\" value=0><tt>&#9776;</tt></option>\n" \
"            <option value=\"T1\" server=\"http://192.168.1.51:8998\">T1</option>\n" \
"            <option value=\"R1\" server=\"http://192.168.2.1:8998\">R1</option>\n" \
"            <option value=\"R2\" server=\"http://192.168.2.52:8998\">R2</option>\n" \
"            <option value=\"R3\" server=\"http://192.168.2.53:8998\">R3</option>\n" \
"            <option value=\"RW1\" server=\"http://192.168.2.54:8998\">RW1</option>\n" \
"            <option value=\"T2\" server=\"http://192.168.7.62:8998\">T2</option>\n" \
"        </select>\n" \
"        <button id=\"selectServer\" title=\"Add selected server from the list\">&#x2795;</button>\n" \
"        <button id=\"addAllServer\" title=\"Add all server from the list\">&#x0229E;</button> -->\n" \
"        <button id=\"livePlayPause\" title=\"Toggle play/pause\">&#9654;/&#9646;&#9646;</button>\n" \
"        <button id=\"removeLocalStorage\" title=\"Remove all servers\">&#x2716;</button>\n" \
"        <button id=\"allowdot\" title=\"Toggle dot in plot\">&#x25EF;</button>\n" \
"        <select id=\"timespan\">\n" \
"            <option value=10>10 Sec</option>\n" \
"            <option value=20>20 Sec</option>\n" \
"            <option value=30>30 Sec</option>\n" \
"            <option value=40>40 Sec</option>\n" \
"            <option value=50>50 Sec</option>\n" \
"        </select>\n" \
"    </div>\n" \
"    <div style=\"position: absolute; display: block; top: 10px; right: 10px\">\n" \
"        <button id=\"exportConfig\" title=\"Export current config\">&#x1F4BE;</button>\n" \
"        <button id=\"importConfig\" title=\"Import previously stored config\">&#x1f4c2;</button>\n" \
"    </div>\n" \
"    <!-- <div class=\"placeholderparent\">\n" \
"    <div id=\"placeholder\" class=\"placeholder\"></div>\n" \
"    </div> -->\n" \
"    <div id=\"new-server\" class=\"modal\">\n" \
"        <table width=\"100%\">\n" \
"            <tr><td>Name:</td><td><input type=\"text\" id=\"newservername\"></td></tr>\n" \
"            <tr><td>Server:</td><td><input type=\"text\" id=\"newserveraddr\"></td></tr>\n" \
"            <tr><td colspan=\"2\"><input type=\"button\" name=\"submit\" value=\"add\" id=\"newserveraddbtn\"></td></tr>\n" \
"        </table>\n" \
"    </div>\n" \
"    <div id=\"editserver\" class=\"modal\">\n" \
"        <table width=\"100%\">\n" \
"            <input type=\"hidden\" id=\"editserverid\">\n" \
"            <tr><td>Name:</td><td><input type=\"text\" id=\"editservername\" class=\"infoInput\"></td></tr>\n" \
"            <tr><td>Server:</td><td><input type=\"text\" id=\"editserveraddr\" class=\"infoInput\"></td></tr>\n" \
"            <tr><td colspan=\"2\"><input type=\"button\" name=\"submit\" value=\"Change\" id=\"editserveraddbtn\"></td></tr>\n" \
"        </table>\n" \
"    </div>\n" \
"\n" \
"    <div id=\"confirmRestore\" class=\"modal\">\n" \
"        <table width=\"100%\">\n" \
"            <tr><td colspan=\"2\">Are you sure? This action will wipe current layout and load the stored one.</td></tr>\n" \
"            <tr>\n" \
"                <td align=\"right\" width=\"50%\">\n" \
"                    <input type=\"button\" name=\"No\" value=\"No\" id=\"confirmRestoreNoBtn\" style=\"background-color: green;color: white;font-weight: bold;border-radius: 10%;padding: 5% 10%;border: none;font-size: 120%;\">\n" \
"                </td>\n" \
"                <td align=\"left\">\n" \
"                    <input type=\"button\" name=\"Yes\" value=\"Yes\" id=\"confirmRestoreYesBtn\" style=\"background-color: red;color: white;font-weight: bold;border-radius: 10%;padding: 5% 10%;border: none;font-size: 120%;\">\n" \
"                </td>\n" \
"            </tr>\n" \
"        </table>\n" \
"    </div>\n" \
"    <!-- <a id=\"configDownload\" style=\"display:none\"></a>\n" \
"    <input id=\"configUpload\" type=\"file\" accept=\"text/plain\" style=\"display: none\"> -->\n" \
"\n" \
"\n" \
"    <script type=\"text/javascript\">\n" \
"    var colornames = {\"aliceblue\":\"#f0f8ff\",\"antiquewhite\":\"#faebd7\",\"aqua\":\"#00ffff\",\"aquamarine\":\"#7fffd4\",\"azure\":\"#f0ffff\",\n" \
"    \"beige\":\"#f5f5dc\",\"bisque\":\"#ffe4c4\",\"black\":\"#000000\",\"blanchedalmond\":\"#ffebcd\",\"blue\":\"#0000ff\",\"blueviolet\":\"#8a2be2\",\"brown\":\"#a52a2a\",\"burlywood\":\"#deb887\",\n" \
"    \"cadetblue\":\"#5f9ea0\",\"chartreuse\":\"#7fff00\",\"chocolate\":\"#d2691e\",\"coral\":\"#ff7f50\",\"cornflowerblue\":\"#6495ed\",\"cornsilk\":\"#fff8dc\",\"crimson\":\"#dc143c\",\"cyan\":\"#00ffff\",\n" \
"    \"darkblue\":\"#00008b\",\"darkcyan\":\"#008b8b\",\"darkgoldenrod\":\"#b8860b\",\"darkgray\":\"#a9a9a9\",\"darkgreen\":\"#006400\",\"darkkhaki\":\"#bdb76b\",\"darkmagenta\":\"#8b008b\",\"darkolivegreen\":\"#556b2f\",\n" \
"    \"darkorange\":\"#ff8c00\",\"darkorchid\":\"#9932cc\",\"darkred\":\"#8b0000\",\"darksalmon\":\"#e9967a\",\"darkseagreen\":\"#8fbc8f\",\"darkslateblue\":\"#483d8b\",\"darkslategray\":\"#2f4f4f\",\"darkturquoise\":\"#00ced1\",\n" \
"    \"darkviolet\":\"#9400d3\",\"deeppink\":\"#ff1493\",\"deepskyblue\":\"#00bfff\",\"dimgray\":\"#696969\",\"dodgerblue\":\"#1e90ff\",\n" \
"    \"firebrick\":\"#b22222\",\"floralwhite\":\"#fffaf0\",\"forestgreen\":\"#228b22\",\"fuchsia\":\"#ff00ff\",\n" \
"    \"gainsboro\":\"#dcdcdc\",\"ghostwhite\":\"#f8f8ff\",\"gold\":\"#ffd700\",\"goldenrod\":\"#daa520\",\"gray\":\"#808080\",\"green\":\"#008000\",\"greenyellow\":\"#adff2f\",\n" \
"    \"honeydew\":\"#f0fff0\",\"hotpink\":\"#ff69b4\",\n" \
"    \"indianred \":\"#cd5c5c\",\"indigo\":\"#4b0082\",\"ivory\":\"#fffff0\",\"khaki\":\"#f0e68c\",\n" \
"    \"lavender\":\"#e6e6fa\",\"lavenderblush\":\"#fff0f5\",\"lawngreen\":\"#7cfc00\",\"lemonchiffon\":\"#fffacd\",\"lightblue\":\"#add8e6\",\"lightcoral\":\"#f08080\",\"lightcyan\":\"#e0ffff\",\"lightgoldenrodyellow\":\"#fafad2\",\n" \
"    \"lightgrey\":\"#d3d3d3\",\"lightgreen\":\"#90ee90\",\"lightpink\":\"#ffb6c1\",\"lightsalmon\":\"#ffa07a\",\"lightseagreen\":\"#20b2aa\",\"lightskyblue\":\"#87cefa\",\"lightslategray\":\"#778899\",\"lightsteelblue\":\"#b0c4de\",\n" \
"    \"lightyellow\":\"#ffffe0\",\"lime\":\"#00ff00\",\"limegreen\":\"#32cd32\",\"linen\":\"#faf0e6\",\n" \
"    \"magenta\":\"#ff00ff\",\"maroon\":\"#800000\",\"mediumaquamarine\":\"#66cdaa\",\"mediumblue\":\"#0000cd\",\"mediumorchid\":\"#ba55d3\",\"mediumpurple\":\"#9370d8\",\"mediumseagreen\":\"#3cb371\",\"mediumslateblue\":\"#7b68ee\",\n" \
"    \"mediumspringgreen\":\"#00fa9a\",\"mediumturquoise\":\"#48d1cc\",\"mediumvioletred\":\"#c71585\",\"midnightblue\":\"#191970\",\"mintcream\":\"#f5fffa\",\"mistyrose\":\"#ffe4e1\",\"moccasin\":\"#ffe4b5\",\n" \
"    \"navajowhite\":\"#ffdead\",\"navy\":\"#000080\",\n" \
"    \"oldlace\":\"#fdf5e6\",\"olive\":\"#808000\",\"olivedrab\":\"#6b8e23\",\"orange\":\"#ffa500\",\"orangered\":\"#ff4500\",\"orchid\":\"#da70d6\",\n" \
"    \"palegoldenrod\":\"#eee8aa\",\"palegreen\":\"#98fb98\",\"paleturquoise\":\"#afeeee\",\"palevioletred\":\"#d87093\",\"papayawhip\":\"#ffefd5\",\"peachpuff\":\"#ffdab9\",\"peru\":\"#cd853f\",\"pink\":\"#ffc0cb\",\"plum\":\"#dda0dd\",\"powderblue\":\"#b0e0e6\",\"purple\":\"#800080\",\n" \
"    \"rebeccapurple\":\"#663399\",\"red\":\"#ff0000\",\"rosybrown\":\"#bc8f8f\",\"royalblue\":\"#4169e1\",\n" \
"    \"saddlebrown\":\"#8b4513\",\"salmon\":\"#fa8072\",\"sandybrown\":\"#f4a460\",\"seagreen\":\"#2e8b57\",\"seashell\":\"#fff5ee\",\"sienna\":\"#a0522d\",\"silver\":\"#c0c0c0\",\"skyblue\":\"#87ceeb\",\"slateblue\":\"#6a5acd\",\"slategray\":\"#708090\",\"snow\":\"#fffafa\",\"springgreen\":\"#00ff7f\",\"steelblue\":\"#4682b4\",\n" \
"    \"tan\":\"#d2b48c\",\"teal\":\"#008080\",\"thistle\":\"#d8bfd8\",\"tomato\":\"#ff6347\",\"turquoise\":\"#40e0d0\",\n" \
"    \"violet\":\"#ee82ee\",\n" \
"    \"wheat\":\"#f5deb3\",\"white\":\"#ffffff\",\"whitesmoke\":\"#f5f5f5\",\n" \
"    \"yellow\":\"#ffff00\",\"yellowgreen\":\"#9acd32\"};\n" \
"    var displayTime = 10\n" \
"    function toHumanReadableBytes(valarg, tickDecimals, divider){\n" \
"        if(tickDecimals === undefined)\n" \
"            tickDecimals = 3\n" \
"        if(divider === undefined)\n" \
"            divider = 1000\n" \
"        var val = Math.abs(valarg)\n" \
"        var sign = \" \"\n" \
"        if(valarg < 0)\n" \
"            sign = \"-\"\n" \
"        var suffix = \" \"\n" \
"        var suffixes = [\" \", \"K\", \"M\", \"G\", \"T\"]\n" \
"        for (var x in suffixes){\n" \
"            suffix = suffixes[x]\n" \
"            if(val < divider)\n" \
"                break\n" \
"            val = val/divider\n" \
"        }\n" \
"        var prefix = \"\"\n" \
"        val = val.toFixed(tickDecimals)\n" \
"        for (var i = val.length; i < (4+tickDecimals); i++) {\n" \
"            prefix += \" \"\n" \
"        }\n" \
"        return  prefix + sign + val + suffix\n" \
"    }\n" \
"    var options = {\n" \
"        series: {\n" \
"            // lines: {show: true},\n" \
"            // points: {show: true},\n" \
"            curvedLines: {active: true},\n" \
"        },\n" \
"        legend: {\n" \
"            show: false,\n" \
"            noColumns: 4,\n" \
"            labelFormatter: function(label, series){return \"<b>\"+label+\"</b>\";},\n" \
"            // container: $(\"#idplacer\")\n" \
"        },\n" \
"        grid: {\n" \
"            borderColor: \"grey\",\n" \
"            verticalLines: false,\n" \
"            hoverable: true,\n" \
"        },\n" \
"        xaxis: {\n" \
"            min: -displayTime,\n" \
"            max: 0,\n" \
"            tickFormatter: function(val, axis){\n" \
"                return \"<pre class='xtick'>\" + val + \"</pre>\"\n" \
"            },\n" \
"            // tickLength: 0,\n" \
"            // labelHeight: 15,\n" \
"        },\n" \
"        yaxis: {\n" \
"            tickDecimals: 1,\n" \
"            tickFormatter: function(valarg, axis) {\n" \
"                var str = toHumanReadableBytes(valarg, axis.tickDecimals)\n" \
"                return \"<pre class='ytick'>\" + str + \"</pre>\"\n" \
"            },\n" \
"            min: 0,\n" \
"        },\n" \
"        axisLabels: {\n" \
"            show: true\n" \
"        },\n" \
"        // xaxes: [{\n" \
"        //     axisLabel: 'foo',\n" \
"        // }],\n" \
"        // yaxes: [{\n" \
"        //     position: 'left',\n" \
"        //     axisLabel: 'bar',\n" \
"        // }, {\n" \
"        //     position: 'right',\n" \
"        //     axisLabel: 'bleem'\n" \
"        // }],\n" \
"        margin: {\n" \
"            left: 20,\n" \
"        },\n" \
"    }\n" \
"    // var data = {}\n" \
"    function trancateData(data, now, time=600){\n" \
"        var maxTime = now\n" \
"        var minTime = maxTime-time\n" \
"        ndata = []\n" \
"        for (var i = 0; i < data.length; i++) {\n" \
"            if(data[i][0] < (minTime-3))\n" \
"                continue\n" \
"            ndata.push(data[i])\n" \
"        }\n" \
"        return ndata;\n" \
"    }\n" \
"    function getTimedData(data, now, time){\n" \
"        if(time == 0)\n" \
"            time = displayTime\n" \
"        var maxTime = now\n" \
"        var minTime = maxTime-time\n" \
"        var xdata = []\n" \
"        var lastData = -1\n" \
"        var lastTime = 0\n" \
"        for (var i = 0; i < data.length; i++) {\n" \
"            var x = data[i][0] - minTime\n" \
"            var y = data[i][1]\n" \
"            if(lastData == -1){\n" \
"                lastData = y\n" \
"                lastTime = x\n" \
"                y = 0\n" \
"            }\n" \
"            else{\n" \
"                z = lastData\n" \
"                lastData = y\n" \
"                y = (y - z)/(x - lastTime)\n" \
"                y = y*8\n" \
"                lastTime = x\n" \
"            }\n" \
"            if(y < 0)\n" \
"                continue\n" \
"            if(data[i][0] < (minTime-3))\n" \
"                continue\n" \
"            xdata.push([x-time, y])\n" \
"        }\n" \
"        return xdata\n" \
"    }\n" \
"\n" \
"    var colors = {\"eth0\":\"red\", \"eth1\":\"green\", \"eth2\":\"black\", \"wlan0\":\"blue\"}\n" \
"    var otherColors = [\"DarkBlue\", \"DarkSalmon\", \"GreenYellow\", \"Cyan\"]; //Object.keys(colornames); //\n" \
"    var otherColorsNum = 0\n" \
"    var colorTable = {}\n" \
"    function onReceive(res){\n" \
"        if(res.query == null || res.query == \"\")\n" \
"            return\n" \
"        var data = serversData[res.query].data\n" \
"        if (data == null)\n" \
"            return\n" \
"\n" \
"        var plotData = {rx:[], tx:[]}\n" \
"        for ( ifc in res[\"ifcs\"]) {\n" \
"            xx = {\"rx\":\"rx_bytes\", \"tx\": \"tx_bytes\"}\n" \
"            if (data[ifc] == null)\n" \
"                data[ifc] = {}\n" \
"            for(px in xx){\n" \
"                if(data[ifc][px] == null)\n" \
"                    data[ifc][px] = []\n" \
"                data[ifc][px].push([res[\"time\"], res[\"ifcs\"][ifc][xx[px]]])\n" \
"                data[ifc][px].sort(function(a,b){return a[0]-b[0];})\n" \
"            }\n" \
"        }\n" \
"        legendCnt = 0\n" \
"        redrawLegend = false\n" \
"        for(var ifc in data){\n" \
"\n" \
"            if (data[ifc][\"rx\"].length == 0 && data[ifc][\"tx\"].length == 0)\n" \
"                continue\n" \
"            if(serversData[res.query].interfaces[ifc] == null){\n" \
"                redrawLegend = true\n" \
"                serversData[res.query].interfaces[ifc] = true\n" \
"            }\n" \
"\n" \
"            if (serversData[res.query].interfaces != null && serversData[res.query].interfaces[ifc] != null && serversData[res.query].interfaces[ifc]==false){\n" \
"                legendCnt ++\n" \
"                continue\n" \
"            }\n" \
"\n" \
"            for(var x in data[ifc]){\n" \
"                var xd = getTimedData(data[ifc][x], res[\"time\"], 0)\n" \
"                var clr = null;\n" \
"                if (colorTable[res.query] && colorTable[res.query][ifc]){\n" \
"                    clr = colorTable[res.query][ifc];\n" \
"                }\n" \
"                if(!clr){\n" \
"                    clr = colors[ifc];\n" \
"                    if(!clr){\n" \
"                        clr = otherColors[otherColorsNum]\n" \
"                        colors[ifc] = clr\n" \
"                        otherColorsNum++\n" \
"                        if(otherColors.length == otherColorsNum)\n" \
"                            otherColorsNum = 0;\n" \
"                    }\n" \
"                    if(!colorTable[res.query]){\n" \
"                        colorTable[res.query] = {}\n" \
"                    }\n" \
"                    if(colornames[clr.toLowerCase()]){\n" \
"                        clr = colornames[clr.toLowerCase()];\n" \
"                    }\n" \
"                    colorTable[res.query][ifc] = clr;\n" \
"                    addColorsToStorage();\n" \
"                }\n" \
"\n" \
"                var nd = {\n" \
"                    label: x,\n" \
"                    data: xd,\n" \
"                    color: clr,\n" \
"                    curvedLines: {\n" \
"                        apply: true,\n" \
"                        monotonicFit: true\n" \
"                    },\n" \
"                    clickable: false,\n" \
"                    hoverable: false\n" \
"                    // hoverable: true\n" \
"                }\n" \
"                plotData[x].push(nd)\n" \
"                if(allowDotInPlot){\n" \
"                    nd2 = {\n" \
"                        label: x,\n" \
"                        data: xd,\n" \
"                        color: clr,\n" \
"                        lines: {show: false},\n" \
"                        points: {show: true},\n" \
"                        clickable: true,\n" \
"                        hoverable: true\n" \
"                    }\n" \
"                    plotData[x].push(nd2)\n" \
"                }\n" \
"                data[ifc][x] = trancateData(data[ifc][x], res[\"time\"], 120)\n" \
"            }\n" \
"            legendCnt++\n" \
"        }\n" \
"        legendCnt = 0\n" \
"        if(redrawLegend){\n" \
"            serversData[res.query].legend_holder.empty()\n" \
"            serversData[res.query].bytes_holder = {}\n" \
"            for(var ifc in data){\n" \
"                var clr = colorTable[res.query][ifc] // colors[ifc]\n" \
"                var lg = $(\"<div>\").css(\"margin-left\", \"20px\").css(\"display\", \"inline-block\")\n" \
"                var lgtxt = $(\"<div>\").text(ifc+\":\").addClass(\"block_view\")\n" \
"                var lgcolorpicker = $(\"<input>\").attr(\"type\", \"color\").css(\"visibility\", \"hidden\").val(clr).attr(\"data-clr-query\", res.query).attr(\"data-clr-ifc\", ifc)\n" \
"                var lgcolor = $(\"<div>\").addClass(\"legendBox\").css(\"background\", clr).addClass(\"block_view\").css(\"margin-left\", \"20px\").append(lgcolorpicker).click(function(){\n" \
"                    // console.log($(this).children())\n" \
"                    $(this).children()[0].click();\n" \
"                })\n" \
"                lgcolorpicker.change(function(){\n" \
"                    // alert(res.query + \" \" + ifc + \" \" + clr + \" \" + JSON.stringify(data))\n" \
"                    var ifc = $(this).attr(\"data-clr-ifc\");\n" \
"                    var query = $(this).attr(\"data-clr-query\");\n" \
"                    var clr = $(this).val();\n" \
"                    // alert(ifc + \" \" + query);\n" \
"                    colorTable[query][ifc] = clr;\n" \
"                    $(this).parent().css(\"background\", clr);\n" \
"                    // alert(clr);\n" \
"                    addColorsToStorage();\n" \
"                    serversData[res.query].bytes_holder[ifc].rx_holder.css(\"color\", clr)\n" \
"                    serversData[res.query].bytes_holder[ifc].tx_holder.css(\"color\", clr)\n" \
"                    // redrawLegend = true;\n" \
"                })\n" \
"                var lgselect = $(\"<input>\").attr(\"type\", \"checkbox\").css(\"float\", \"left\").attr(\"ifcname\", ifc).attr(\"server\", res.query).change(function(){\n" \
"                    server = $(this).attr(\"server\")\n" \
"                    ifc = $(this).attr(\"ifcname\")\n" \
"                    if(serversData[res.query].interfaces[ifc] == true){\n" \
"                        serversData[res.query].interfaces[ifc] = false\n" \
"                    }\n" \
"                    else{\n" \
"                        serversData[res.query].interfaces[ifc] = true\n" \
"                    }\n" \
"                })\n" \
"                if(serversData[res.query].interfaces[ifc]){\n" \
"                    lgselect.attr(\"checked\", \"checked\")\n" \
"                }\n" \
"\n" \
"                var lgc = $(\"<div>\").addClass(\"block_view\")\n" \
"\n" \
"                var tx_bytes = $(\"<span></span>\").css(\"color\", clr)\n" \
"                var tx_holder = $(\"<div></div>\").addClass(\"rx_tx_bytes_holder\").html(\"&uarr;TX:\").append(tx_bytes)//.addClass(\"block_view\")\n" \
"                var rx_bytes = $(\"<span></span>\").css(\"color\", clr)\n" \
"                var rx_holder = $(\"<div></div>\").addClass(\"rx_tx_bytes_holder\").html(\"<bold>&darr;</bold>RX:\").append(rx_bytes)//.addClass(\"block_view\")\n" \
"\n" \
"                lg.append(lgselect).append(lgtxt).append(lgcolor)//.append(lgcolorpicker)\n" \
"                lgc.append(lg).append(tx_holder).append(rx_holder)\n" \
"\n" \
"                serversData[res.query].legend_holder.append(lgc)\n" \
"                serversData[res.query].bytes_holder[ifc] = {rx_holder : rx_bytes, tx_holder: tx_bytes}\n" \
"                legendCnt++\n" \
"            }\n" \
"        }\n" \
"        serversData[res.query].data = data\n" \
"\n" \
"        options.xaxis.tickFormatter = function(val, axis){return \"<pre class='xtick'>\" + val + \"</pre>\"}\n" \
"        $.plot(serversData[res.query].placeholder_rx, plotData.rx, options)\n" \
"\n" \
"        options.xaxis.tickFormatter = function(val, axis){return \"<pre class='xtick xtick_tx'>\" + val + \"</pre>\"}\n" \
"        $.plot(serversData[res.query].placeholder_tx, plotData.tx, options)\n" \
"        if(serversData[res.query].bytes_holder !== undefined){\n" \
"            for ( ifc in res[\"ifcs\"]) {\n" \
"                if(serversData[res.query].bytes_holder[ifc] !== undefined && serversData[res.query].bytes_holder[ifc].rx_holder !== undefined)\n" \
"                    serversData[res.query].bytes_holder[ifc].rx_holder.html(toHumanReadableBytes(res.ifcs[ifc].rx_bytes))\n" \
"\n" \
"                if(serversData[res.query].bytes_holder[ifc] !== undefined && serversData[res.query].bytes_holder[ifc].tx_holder !== undefined)\n" \
"                    serversData[res.query].bytes_holder[ifc].tx_holder.html(toHumanReadableBytes(res.ifcs[ifc].tx_bytes))\n" \
"            }\n" \
"        }\n" \
"    }\n" \
"\n" \
"    var serversData = {}\n" \
"    var runPlotInterval = null\n" \
"\n" \
"    function fetchData(){\n" \
"        for(id in serversData){\n" \
"            $.ajax({\n" \
"                url: serversData[id].server,\n" \
"                data: id,\n" \
"                type: \"GET\",\n" \
"                success: function(res){onReceive(res)}\n" \
"            })\n" \
"        }\n" \
"        // if(run)\n" \
"        //     setTimeout(fetchData, 1000);\n" \
"    }\n" \
"\n" \
"    function playPlot(){\n" \
"        if(runPlotInterval)\n" \
"            return;\n" \
"        runPlotInterval = setInterval(fetchData, 1000)\n" \
"    }\n" \
"\n" \
"    function pausePlot() {\n" \
"        if(!runPlotInterval)\n" \
"            return;\n" \
"        clearInterval(runPlotInterval);\n" \
"        runPlotInterval = null;\n" \
"    }\n" \
"\n" \
"    function closeServer(serverId) {\n" \
"        if(!confirm(\"closing server : \" + serversData[serverId].name)){\n" \
"            return;\n" \
"        }\n" \
"\n" \
"        serversData[serverId].placeholder_parent.remove();\n" \
"        var server = serversData[serverId].server;\n" \
"        var name = serversData[serverId].name;\n" \
"        delete serversData[serverId];\n" \
"        delete colorTable[serverId];\n" \
"        addColorsToStorage();\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            if (localStorage.serverinfo) {\n" \
"                var serverinfo = JSON.parse(localStorage.serverinfo)\n" \
"                var newServerInfo = []\n" \
"                for (var i = 0; i < serverinfo.length; i++) {\n" \
"                    if(serverinfo[i][0] == server && serverinfo[i][1] == name)\n" \
"                        continue\n" \
"                    newServerInfo.push([serverinfo[i][0], serverinfo[i][1], serverinfo[i][2]])\n" \
"                }\n" \
"                localStorage.serverinfo = JSON.stringify(newServerInfo)\n" \
"            }\n" \
"        }\n" \
"\n" \
"    }\n" \
"\n" \
"    function getServerInfo(serverId) {\n" \
"        // console.log(serversData[serverId])\n" \
"        var server = serversData[serverId].server;\n" \
"        var name = serversData[serverId].name;\n" \
"        $(\"#editserveraddr\").val(server)\n" \
"        $(\"#editservername\").val(name)\n" \
"        $(\"#editserverid\").val(serverId)\n" \
"        $('#editserver').modal();\n" \
"    }\n" \
"\n" \
"    $(\"#editserveraddbtn\").click(function(){\n" \
"        var serverId = $(\"#editserverid\").val(); //prompt(\"Server url\")\n" \
"        var oldServer = serversData[serverId].server;\n" \
"        var oldName = serversData[serverId].name;\n" \
"\n" \
"        var newServer = $(\"#editserveraddr\").val(); //prompt(\"Server url\")\n" \
"        var newName= $(\"#editservername\").val(); //prompt(\"name\");\n" \
"\n" \
"        if(oldServer == \"\" || oldServer == null || oldName == \"\" || oldName == null){\n" \
"            alert(\"invalid input\")\n" \
"            return\n" \
"        }\n" \
"\n" \
"        if(!newServer.startsWith(\"https://\") && !newServer.startsWith(\"http://\")){\n" \
"            newServer = \"http://\" + newServer\n" \
"        }\n" \
"\n" \
"        var chngServer = \"\";\n" \
"        if(newServer != oldServer)\n" \
"            chngServer += \"server address from `\" + oldServer + \"` to `\" + newServer + \"`\"\n" \
"        if(newName != oldName) {\n" \
"            if(chngServer != \"\")\n" \
"                chngServer += \" and \"\n" \
"            chngServer += \"server name from `\" + oldName + \"` to `\" + newName + \"`\"\n" \
"        }\n" \
"        if(chngServer != \"\") {\n" \
"            if(!confirm(\"Do you want to change \" + chngServer)){\n" \
"                console.log(\"not confirmed\")\n" \
"                return;\n" \
"            }\n" \
"        }\n" \
"        else{\n" \
"            console.log(\"no change\")\n" \
"            $.modal.close();\n" \
"            return;\n" \
"        }\n" \
"\n" \
"        $(\"#editserveraddr\").val(\"\")\n" \
"        $(\"#editservername\").val(\"\")\n" \
"\n" \
"        serversData[serverId].server = newServer;\n" \
"        serversData[serverId].name = newName;\n" \
"        // console.log(serversData[serverId])\n" \
"        var serverStorageId = serversData[serverId].storageId\n" \
"\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            if (localStorage.serverinfo) {\n" \
"                var serverinfo = JSON.parse(localStorage.serverinfo)\n" \
"                var newServerInfo = []\n" \
"                for (var i = 0; i < serverinfo.length; i++) {\n" \
"                    if(serverinfo[i][2] == serverStorageId) {\n" \
"                        newServerInfo.push([newServer, newName, serverStorageId])\n" \
"                    }\n" \
"                    else {\n" \
"                        newServerInfo.push([serverinfo[i][0], serverinfo[i][1], serverinfo[i][2]])\n" \
"                    }\n" \
"                }\n" \
"                // console.log(newServerInfo)\n" \
"                localStorage.serverinfo = JSON.stringify(newServerInfo)\n" \
"            }\n" \
"        }\n" \
"\n" \
"        $.modal.close();\n" \
"    })\n" \
"\n" \
"    var count = 0\n" \
"    var run = false\n" \
"    var allowDotInPlot = false\n" \
"\n" \
"    function addServer(server, name, id){\n" \
"        var dt = {server:server, name:name, data:{}, id:\"server\"+id, storageId: id}\n" \
"        var container = $(\"<div>\").addClass(\"placeholderparent\")\n" \
"        var info = $(\"<span>&#x1F6C8;</span>\").css(\"float\", \"left\").css(\"cursor\", \"pointer\").css(\"color\", \"green\").click(function(){getServerInfo(\"server\"+id)})\n" \
"        var close = $(\"<span>&#10006;</span>\").css(\"float\", \"right\").css(\"cursor\", \"pointer\").css(\"color\", \"red\").click(function(){closeServer(\"server\"+id)})\n" \
"\n" \
"        var title = $(\"<center><h2 style='margin:0'>\"+name+\"</h2></center>\")\n" \
"        container.append(close)\n" \
"        container.append(info)\n" \
"        container.append(title)\n" \
"        var table = $(\"<table>\")\n" \
"        var row1 = $(\"<tr>\")\n" \
"        var rc1 = $(\"<td>\").addClass(\"yaxis_width\")\n" \
"                            .css(\"vertical-align\", \"bottom\")\n" \
"\n" \
"        var yaxis = $(\"<div>\").addClass(\"yaxis\")\n" \
"                            .html(\"Speed (bps)<br>RX&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TX\")\n" \
"        rc1.append(yaxis)\n" \
"        var parent = $(\"<td>\")\n" \
"        row1.append(rc1).append(parent)\n" \
"        var row2 = $(\"<tr>\").append(\"<td>\")\n" \
"        var xaxis = $(\"<td>\").css(\"text-align\", \"center\").text(\"Time (seconds)\")\n" \
"        row2.append(xaxis)\n" \
"\n" \
"        table.append(row1).append(row2)\n" \
"        container.append(table)\n" \
"\n" \
"        var row3 = $(\"<tr>\")\n" \
"        var legends = $(\"<td>\").addClass(\"legends\").attr(\"colspan\", 2)\n" \
"                            .html(\"&nbsp;\")\n" \
"        row3.append(legends)\n" \
"        table.append(row3)\n" \
"\n" \
"        var placeholder_tx = $(\"<div>\").addClass(\"placeholder_tx\")//.addClass(\"placeholder_width\")\n" \
"        dt[\"placeholder_tx\"] = placeholder_tx\n" \
"        parent.append(placeholder_tx)\n" \
"\n" \
"        var placeholder_rx = $(\"<div>\").addClass(\"placeholder_rx\")\n" \
"        dt[\"placeholder_rx\"] = placeholder_rx\n" \
"        parent.append(placeholder_rx)\n" \
"\n" \
"        dt[\"placeholder_parent\"] = container\n" \
"        dt[\"legend_holder\"] = legends\n" \
"\n" \
"        $(\"#container\").append(container)\n" \
"        dt[\"interfaces\"] = {}\n" \
"        serversData[\"server\"+id] = dt\n" \
"        if(!runPlotInterval)\n" \
"            playPlot()\n" \
"\n" \
"        placeholder_rx.bind(\"plothover\", showToolTip).bind(\"plothovercleanup\", hideToolTip)\n" \
"        placeholder_tx.bind(\"plothover\", showToolTip).bind(\"plothovercleanup\", hideToolTip)\n" \
"\n" \
"    }\n" \
"\n" \
"    function showToolTip(event, pos, item){\n" \
"        if (item) {\n" \
"            var x = item.datapoint[0].toFixed(2),\n" \
"                y = toHumanReadableBytes(item.datapoint[1]);\n" \
"                // console.log(item)\n" \
"\n" \
"            $(\"#tooltip\").html(item.series.label + \": (\" + x + \"=\" + y + \")\")\n" \
"                .css({top: item.pageY+5, left: item.pageX+5})\n" \
"                .fadeIn(200);\n" \
"        } else {\n" \
"            $(\"#tooltip\").hide();\n" \
"        }\n" \
"    }\n" \
"\n" \
"    function hideToolTip(event, pos, item){\n" \
"        $(\"#tooltip\").hide();\n" \
"\n" \
"    }\n" \
"\n" \
"    function add2Storage(server, name, id){\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            if (localStorage.serverinfo) {\n" \
"                var serverinfo = JSON.parse(localStorage.serverinfo)\n" \
"                serverinfo.push([server, name, id])\n" \
"                localStorage.serverinfo = JSON.stringify(serverinfo)\n" \
"            } else {\n" \
"                localStorage.serverinfo = JSON.stringify([[server, name, id]])\n" \
"            }\n" \
"        }\n" \
"    }\n" \
"\n" \
"    function addColorsToStorage(){\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            // if (localStorage.colo) {\n" \
"            //     var serverinfo = JSON.parse(localStorage.serverinfo)\n" \
"            //     serverinfo.push([server, name, id])\n" \
"            //     localStorage.serverinfo = JSON.stringify(serverinfo)\n" \
"            // } else {\n" \
"            localStorage.colorTable = JSON.stringify(colorTable)\n" \
"            // }\n" \
"        }\n" \
"    }\n" \
"\n" \
"    $(\"#addServer\").click(function(){\n" \
"        $('#new-server').modal();\n" \
"        return;\n" \
"    })\n" \
"\n" \
"    $(\"#newserveraddbtn\").click(function(){\n" \
"        var server= $(\"#newserveraddr\").val(); //prompt(\"Server url\")\n" \
"        var name= $(\"#newservername\").val(); //prompt(\"name\");\n" \
"        $(\"#newserveraddr\").val(\"\")\n" \
"        $(\"#newservername\").val(\"\")\n" \
"        if(server == \"\" || server == null || name == \"\" || name == null){\n" \
"            alert(\"invalid input\")\n" \
"            return\n" \
"        }\n" \
"        if(!server.startsWith(\"https://\") && !server.startsWith(\"http://\")){\n" \
"            server = \"http://\"+server\n" \
"        }\n" \
"        var date = new Date()\n" \
"        var id = date.getTime()\n" \
"        addServer(server, name, id)\n" \
"        add2Storage(server, name, id)\n" \
"\n" \
"        $.modal.close();\n" \
"    })\n" \
"\n" \
"    $(document).ready(function(){\n" \
"        $(\"<div id='tooltip'></div>\").css({\n" \
"            position: \"absolute\",\n" \
"            display: \"none\",\n" \
"            border: \"1px solid #fdd\",\n" \
"            padding: \"2px\",\n" \
"            \"background-color\": \"#fee\",\n" \
"            opacity: 0.80\n" \
"        }).appendTo(\"body\");\n" \
"\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            if (localStorage.serverinfo) {\n" \
"                var serverinfo = JSON.parse(localStorage.serverinfo)\n" \
"                for (var i = 0; i < serverinfo.length; i++) {\n" \
"                    addServer(serverinfo[i][0], serverinfo[i][1], serverinfo[i][2])\n" \
"                }\n" \
"            }\n" \
"            if(localStorage.colorTable){\n" \
"                colorTable = JSON.parse(localStorage.colorTable);\n" \
"            }\n" \
"            if(localStorage.displayTime){\n" \
"                displayTime = localStorage.displayTime\n" \
"                $(\"#timespan\").val(displayTime)\n" \
"                options[\"xaxis\"].min = -displayTime\n" \
"            }\n" \
"            else\n" \
"                $(\"#timespan\").val(10)\n" \
"        }\n" \
"        $(\"#serverList\").val(0)\n" \
"\n" \
"        Date.prototype.yyyymmdd = function() {\n" \
"          var mm = this.getMonth() + 1; // getMonth() is zero-based\n" \
"          var dd = this.getDate();\n" \
"          var hh = this.getHours();\n" \
"          var MM = this.getMinutes();\n" \
"          var ss = this.getSeconds();\n" \
"\n" \
"          return [this.getFullYear(),\n" \
"                  (mm>9 ? '' : '0') + mm,\n" \
"                  (dd>9 ? '' : '0') + dd,\n" \
"                  (hh>9 ? '' : '0') + hh,\n" \
"                  (MM>9 ? '' : '0') + MM,\n" \
"                  (ss>9 ? '' : '0') + ss,\n" \
"\n" \
"                 ].join('');\n" \
"        };\n" \
"    })\n" \
"\n" \
"    $(\"#removeLocalStorage\").click(function(){\n" \
"        if(!confirm(\"Do you really want that?\"))\n" \
"            return\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            localStorage.clear()\n" \
"        }\n" \
"        location.reload()\n" \
"    })\n" \
"\n" \
"    $(\"#livePlayPause\").click(function(){\n" \
"        if(runPlotInterval){\n" \
"            pausePlot()\n" \
"        }\n" \
"        else{\n" \
"            playPlot()\n" \
"        }\n" \
"    });\n" \
"\n" \
"    $(\"#timespan\").change(function(){\n" \
"        displayTime = $(\"#timespan\").val()\n" \
"        options[\"xaxis\"].min = -displayTime\n" \
"        localStorage.displayTime = displayTime\n" \
"    })\n" \
"\n" \
"    $(\"#allowdot\").click(function(){\n" \
"        if(allowDotInPlot)\n" \
"            allowDotInPlot = false\n" \
"        else\n" \
"            allowDotInPlot = true\n" \
"    })\n" \
"\n" \
"    $(\"#selectServer\").click(function(){\n" \
"        serverName = $(\"#serverList\").val()\n" \
"        if(serverName == 0){\n" \
"            return\n" \
"        }\n" \
"        address = $(\"#serverList option:selected\").attr(\"server\")\n" \
"        var date = new Date();\n" \
"        addServer(address, serverName, date.getTime())\n" \
"        add2Storage(address, serverName, date.getTime())\n" \
"        $(\"#serverList\").val(0)\n" \
"    })\n" \
"\n" \
"    $(\"#addAllServer\").click(function(){\n" \
"        var count = 0;\n" \
"        var date = new Date()\n" \
"        $(\"#serverList option\").each(function(){\n" \
"            serverName = $(this).val()\n" \
"            address = $(this).attr(\"server\")\n" \
"            if(serverName == 0)\n" \
"                return\n" \
"            addServer(address, serverName, count + date.getTime())\n" \
"            add2Storage(address, serverName, count + date.getTime())\n" \
"            count ++;\n" \
"        })\n" \
"    })\n" \
"\n" \
"    $(\"#exportConfig\").click(function(){\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            var serverinfo = null;\n" \
"            var colorTable = null;\n" \
"            var displayTime = null;\n" \
"            if (localStorage.serverinfo) {\n" \
"                serverinfo = localStorage.serverinfo;\n" \
"            }\n" \
"            if(localStorage.colorTable){\n" \
"                colorTable = localStorage.colorTable;\n" \
"            }\n" \
"            if(localStorage.displayTime){\n" \
"                displayTime = localStorage.displayTime\n" \
"            }\n" \
"\n" \
"            var data = {\n" \
"                serverinfo: serverinfo,\n" \
"                colorTable: colorTable,\n" \
"                displayTime: displayTime\n" \
"            }\n" \
"            var dataStr = JSON.stringify(data)\n" \
"            downloadAsFile(\"config.json\", dataStr, \"json/application\")\n" \
"        }\n" \
"        else{\n" \
"            alert(\"ERROR!! local storage is not supported in your browser\")\n" \
"        }\n" \
"    })\n" \
"\n" \
"    $(\"#importConfig\").click(function(){\n" \
"\n" \
"        if(typeof(Storage) !== \"undefined\") {\n" \
"            $(\"#confirmRestore\").modal()\n" \
"        }\n" \
"        else{\n" \
"            alert(\"ERROR!! local storage is not supported in your browser\")\n" \
"        }\n" \
"    })\n" \
"\n" \
"    $(\"#confirmRestoreNoBtn\").click(function(){\n" \
"        $.modal.close()\n" \
"        return false\n" \
"    })\n" \
"\n" \
"    $(\"#confirmRestoreYesBtn\").click(function(){\n" \
"        var element = document.createElement('input');\n" \
"        // var element = document.querySelector(\"#configUpload\");\n" \
"        element.setAttribute(\"type\", \"file\")\n" \
"        element.setAttribute(\"accept\", \"application/json\")\n" \
"        element.onchange = function(event){\n" \
"            var input = event.target\n" \
"            var reader = new FileReader();\n" \
"            reader.onload = function(){\n" \
"\n" \
"                var text = reader.result;\n" \
"                var jsonData = JSON.parse(text)\n" \
"                if(\"serverinfo\" in jsonData){\n" \
"                    localStorage.serverinfo = jsonData[\"serverinfo\"]\n" \
"                }\n" \
"                if(\"colorTable\" in jsonData){\n" \
"                    localStorage.colorTable = jsonData[\"colorTable\"]\n" \
"                }\n" \
"                if(\"displayTime\" in jsonData){\n" \
"                    localStorage.displayTime = jsonData[\"displayTime\"]\n" \
"                }\n" \
"                console.log(jsonData);\n" \
"                location.reload()\n" \
"            };\n" \
"            reader.readAsText(input.files[0]);\n" \
"        }\n" \
"        document.body.appendChild(element);\n" \
"\n" \
"        element.click();\n" \
"\n" \
"        document.body.removeChild(element);\n" \
"        $.modal.close()\n" \
"        return false\n" \
"    })\n" \
"    function downloadAsFile(filename, text, mime) {\n" \
"        if(typeof(mime) == \"undefined\"){\n" \
"            mime = \"text/plain\"\n" \
"        }\n" \
"        var element = document.createElement('a');\n" \
"        // var element = document.querySelector(\"#configDownload\");\n" \
"        element.setAttribute('href', 'data:' + mime + ';charset=utf-8,' + encodeURIComponent(text));\n" \
"        element.setAttribute('download', filename);\n" \
"\n" \
"        element.style.display = 'none';\n" \
"        document.body.appendChild(element);\n" \
"\n" \
"        element.click();\n" \
"\n" \
"        document.body.removeChild(element);\n" \
"    }\n" \
"    </script>\n" \
"</body>\n" \
"</html>\n" \
"\n" \


#define DATA_LEN_6 "36628"

char *files[][4] = {
	{ "flot/jquery.js", DATA_0 , DATA_LEN_0, "application/javascript" }, 
	{ "flot/jquery.flot.js", DATA_1 , DATA_LEN_1, "application/javascript" }, 
	{ "plugin/curvedLines.js", DATA_2 , DATA_LEN_2, "application/javascript" }, 
	{ "plugin/jquery.flot.axislabels.js", DATA_3 , DATA_LEN_3, "application/javascript" }, 
	{ "plugin/jquery.modal.min.js", DATA_4 , DATA_LEN_4, "application/javascript" }, 
	{ "plugin/jquery.modal.min.css", DATA_5 , DATA_LEN_5, "text/css" }, 
	{ "chart.html", DATA_6 , DATA_LEN_6, "text/html" }, 
	{ NULL, NULL, NULL }
};

