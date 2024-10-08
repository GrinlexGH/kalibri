//
// kbMemberMethods: Member Methods
//

//
// Copyright (c) 2009 Brandon Jones
// Copyright 2011 Li-Cheng (Andy) Tai
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source
//  distribution.
//

#if !defined(_KALIBRI_MEMBER_METHODS_H_)
#define _KALIBRI_MEMBER_METHODS_H_

#include <squirrel.h>
#include "kbtypes.h"

namespace kb {

/// @cond DEV

//
// Squirrel Global Functions
//

template <class C, class R>
class SqMember {
public:

    // Arg Count 0
    template <bool overloaded /*= false*/>
    static SQInteger Func0(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif

        typedef R (C::*M)();
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        R ret = (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <bool overloaded /*= false*/>
    static SQInteger Func0C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)() const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        R ret = (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 1
    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 2
    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 3
    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 4
    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 5
    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 6
    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 7
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 8
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 9
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 10
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded /*= false*/>
    static SQInteger Func10(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded  /*= false*/ >
    static SQInteger Func10C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 11
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 12
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/  >
    static SQInteger Func12(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/>
    static SQInteger Func12C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 13
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 14
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value,
                    a14.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value,
                    a14.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVar(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }
};


//
// reference return specialization
//

template <class C, class R>
class SqMember<C, R&> {
public:

    // Arg Count 0
    template <bool overloaded /*= false*/>
    static SQInteger Func0(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)();
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        R& ret = (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <bool overloaded /*= false*/>
    static SQInteger Func0C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)() const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        R& ret = (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 1
    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 2
    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 3
    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 4
    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 5
    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 6
    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 7
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 8
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 9
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 10
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded /*= false*/>
    static SQInteger Func10(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded  /*= false*/ >
    static SQInteger Func10C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 11
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }


    // Arg Count 12
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/  >
    static SQInteger Func12(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/>
    static SQInteger Func12C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 13
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R&(C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    // Arg Count 14
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value,
                    a14.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef R& (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        R& ret = (ptr->*method)(
                    a1.value,
                    a2.value,
                    a3.value,
                    a4.value,
                    a5.value,
                    a6.value,
                    a7.value,
                    a8.value,
                    a9.value,
                    a10.value,
                    a11.value,
                    a12.value,
                    a13.value,
                    a14.value
                );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        PushVarR(vm, ret);
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 1;
    }

};


//
// void return specialization
//

template <class C>
class SqMember<C, void> {
public:

    // Arg Count 0
    template <bool overloaded /*= false*/>
    static SQInteger Func0(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)();
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <bool overloaded /*= false*/>
    static SQInteger Func0C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 2) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)() const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        (ptr->*method)();
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 1
    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, bool overloaded /*= false*/>
    static SQInteger Func1C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 3) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 2
    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, bool overloaded /*= false*/>
    static SQInteger Func2C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 4) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 3
    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, bool overloaded /*= false*/>
    static SQInteger Func3C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 5) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 4
    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, bool overloaded /*= false*/>
    static SQInteger Func4C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 6) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 5
    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, bool overloaded /*= false*/>
    static SQInteger Func5C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 7) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 6
    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, bool overloaded /*= false*/>
    static SQInteger Func6C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 8) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 7
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, bool overloaded /*= false*/>
    static SQInteger Func7C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 9) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 8
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, bool overloaded /*= false*/>
    static SQInteger Func8C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 10) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 9
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, bool overloaded /*= false*/>
    static SQInteger Func9C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 11) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 10
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded /*= false*/>
    static SQInteger Func10(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, bool overloaded /*= false*/>
    static SQInteger Func10C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 12) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 11
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, bool overloaded /*= false*/>
    static SQInteger Func11C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 13) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 12
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/>
    static SQInteger Func12(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, bool overloaded /*= false*/>
    static SQInteger Func12C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 14) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 13
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value,
            a13.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, bool overloaded /*= false*/>
    static SQInteger Func13C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 15) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value,
            a13.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    // Arg Count 14
    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14);
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value,
            a13.value,
            a14.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

    template <class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14, bool overloaded /*= false*/>
    static SQInteger Func14C(HSQUIRRELVM vm) {

#if !defined (KALIBRI_NO_ERROR_CHECKING)
        if (!KALIBRI_CONST_CONDITION(overloaded) && sq_gettop(vm) != 16) {
            return sq_throwerror(vm, _SC("wrong number of parameters"));
        }
#endif
        typedef void (C::*M)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) const;
        M* methodPtr;
        sq_getuserdata(vm, -1, (SQUserPointer*)&methodPtr, NULL);
        M method = *methodPtr;

        C* ptr;
        SQTRY()
        ptr = Var<C*>(vm, 1).value;
        SQCATCH_NOEXCEPT(vm) {
            SQCLEAR(vm); // clear the previous error
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            assert(0); // may fail because C is not a type bound in the VM
            return sq_throwerror(vm, SQWHAT(vm));
        }

        SQTRY()
        Var<A1> a1(vm, 2);
        Var<A2> a2(vm, 3);
        Var<A3> a3(vm, 4);
        Var<A4> a4(vm, 5);
        Var<A5> a5(vm, 6);
        Var<A6> a6(vm, 7);
        Var<A7> a7(vm, 8);
        Var<A8> a8(vm, 9);
        Var<A9> a9(vm, 10);
        Var<A10> a10(vm, 11);
        Var<A11> a11(vm, 12);
        Var<A12> a12(vm, 13);
        Var<A13> a13(vm, 14);
        Var<A14> a14(vm, 15);
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        (ptr->*method)(
            a1.value,
            a2.value,
            a3.value,
            a4.value,
            a5.value,
            a6.value,
            a7.value,
            a8.value,
            a9.value,
            a10.value,
            a11.value,
            a12.value,
            a13.value,
            a14.value
        );
        SQCATCH_NOEXCEPT(vm) {
            return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
        }
        SQCATCH(vm) {
            return sq_throwerror(vm, SQWHAT(vm));
        }
        return 0;
    }

};


//
// Member Function Resolvers
//

// Arg Count 0
template <class C, class R>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)()) {
    return &SqMember<C, R>::template Func0<false>;
}

template <class C, class R>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)() const) {
    return &SqMember<C, R>::template Func0C<false>;
}

template <class C, class R>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)()) {
    return &SqMember<C, R&>::template Func0<false>;
}

template <class C, class R>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)() const) {
    return &SqMember<C, R&>::template Func0C<false>;
}

// Arg Count 1
template <class C, class R, class A1>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1)) {
    return &SqMember<C, R>::template Func1<A1, false>;
}

template <class C, class R, class A1>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1) const) {
    return &SqMember<C, R>::template Func1C<A1, false>;
}

template <class C, class R, class A1>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1)) {
    return &SqMember<C, R&>::template Func1<A1, false>;
}

template <class C, class R, class A1>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1) const) {
    return &SqMember<C, R&>::template Func1C<A1, false>;
}

// Arg Count 2
template <class C, class R, class A1, class A2>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2)) {
    return &SqMember<C, R>::template Func2<A1, A2, false>;
}

template <class C, class R, class A1, class A2>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2) const) {
    return &SqMember<C, R>::template Func2C<A1, A2, false>;
}

template <class C, class R, class A1, class A2>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2)) {
    return &SqMember<C, R&>::template Func2<A1, A2, false>;
}

template <class C, class R, class A1, class A2>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2) const) {
    return &SqMember<C, R&>::template Func2C<A1, A2, false>;
}

// Arg Count 3
template <class C, class R, class A1, class A2, class A3>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3)) {
    return &SqMember<C, R>::template Func3<A1, A2, A3, false>;
}

template <class C, class R, class A1, class A2, class A3>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3) const) {
    return &SqMember<C, R>::template Func3C<A1, A2, A3, false>;
}

template <class C, class R, class A1, class A2, class A3>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3)) {
    return &SqMember<C, R&>::template Func3<A1, A2, A3, false>;
}

template <class C, class R, class A1, class A2, class A3>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3) const) {
    return &SqMember<C, R&>::template Func3C<A1, A2, A3, false>;
}

// Arg Count 4
template <class C, class R, class A1, class A2, class A3, class A4>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4)) {
    return &SqMember<C, R>::template Func4<A1, A2, A3, A4, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4) const) {
    return &SqMember<C, R>::template Func4C<A1, A2, A3, A4, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4)) {
    return &SqMember<C, R&>::template Func4<A1, A2, A3, A4, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4) const) {
    return &SqMember<C, R&>::template Func4C<A1, A2, A3, A4, false>;
}

// Arg Count 5
template <class C, class R, class A1, class A2, class A3, class A4, class A5>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5)) {
    return &SqMember<C, R>::template Func5<A1, A2, A3, A4, A5, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5) const) {
    return &SqMember<C, R>::template Func5C<A1, A2, A3, A4, A5, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5)) {
    return &SqMember<C, R&>::template Func5<A1, A2, A3, A4, A5, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5>
inline SQFUNCTION SqMemberFunc(R&(C::* /*method*/)(A1, A2, A3, A4, A5) const) {
    return &SqMember<C, R&>::template Func5C<A1, A2, A3, A4, A5, false>;
}

// Arg Count 6
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6)) {
    return &SqMember<C, R>::template Func6<A1, A2, A3, A4, A5, A6, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6) const) {
    return &SqMember<C, R>::template Func6C<A1, A2, A3, A4, A5, A6, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6)) {
    return &SqMember<C, R&>::template Func6<A1, A2, A3, A4, A5, A6, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6) const) {
    return &SqMember<C, R&>::template Func6C<A1, A2, A3, A4, A5, A6, false>;
}

// Arg Count 7
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7)) {
    return &SqMember<C, R>::template Func7<A1, A2, A3, A4, A5, A6, A7, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7) const) {
    return &SqMember<C, R>::template Func7C<A1, A2, A3, A4, A5, A6, A7, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7)) {
    return &SqMember<C, R&>::template Func7<A1, A2, A3, A4, A5, A6, A7, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7) const) {
    return &SqMember<C, R&>::template Func7C<A1, A2, A3, A4, A5, A6, A7, false>;
}

// Arg Count 8
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8)) {
    return &SqMember<C, R>::template Func8<A1, A2, A3, A4, A5, A6, A7, A8, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8) const) {
    return &SqMember<C, R>::template Func8C<A1, A2, A3, A4, A5, A6, A7, A8, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8)) {
    return &SqMember<C, R&>::template Func8<A1, A2, A3, A4, A5, A6, A7, A8, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8) const) {
    return &SqMember<C, R&>::template Func8C<A1, A2, A3, A4, A5, A6, A7, A8, false>;
}

// Arg Count 9
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9)) {
    return &SqMember<C, R>::template Func9<A1, A2, A3, A4, A5, A6, A7, A8, A9, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const) {
    return &SqMember<C, R>::template Func9C<A1, A2, A3, A4, A5, A6, A7, A8, A9, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline SQFUNCTION SqMemberFunc(R&(C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9)) {
    return &SqMember<C, R&>::template Func9<A1, A2, A3, A4, A5, A6, A7, A8, A9, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const) {
    return &SqMember<C, R&>::template Func9C<A1, A2, A3, A4, A5, A6, A7, A8, A9, false>;
}

// Arg Count 10
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)) {
    return &SqMember<C, R>::template Func10<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const) {
    return &SqMember<C, R>::template Func10C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, false>;
}
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)) {
    return &SqMember<C, R&>::template Func10<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const) {
    return &SqMember<C, R&>::template Func10C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, false>;
}

// Arg Count 11
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)) {
    return &SqMember<C, R>::template Func11<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) const) {
    return &SqMember<C, R>::template Func11C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, false>;
}
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11)) {
    return &SqMember<C, R&>::template Func11<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11) const) {
    return &SqMember<C, R&>::template Func11C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, false>;
}

// Arg Count 12
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)) {
    return &SqMember<C, R>::template Func12<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) const) {
    return &SqMember<C, R>::template Func12C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12)) {
    return &SqMember<C, R&>::template Func12<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12) const) {
    return &SqMember<C, R&>::template Func12C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, false>;
}

// Arg Count 13
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)) {
    return &SqMember<C, R>::template Func13<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) const) {
    return &SqMember<C, R>::template Func13C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13)) {
    return &SqMember<C, R&>::template Func13<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13) const) {
    return &SqMember<C, R&>::template Func13C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, false>;
}

// Arg Count 14
template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)) {
    return &SqMember<C, R>::template Func14<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
inline SQFUNCTION SqMemberFunc(R (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) const) {
    return &SqMember<C, R>::template Func14C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14)) {
    return &SqMember<C, R&>::template Func14<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, false>;
}

template <class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14>
inline SQFUNCTION SqMemberFunc(R& (C::* /*method*/)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14) const) {
    return &SqMember<C, R&>::template Func14C<A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, false>;
}


//
// Variable Get
//

template <class C, class V>
inline SQInteger sqDefaultGet(HSQUIRRELVM vm) {
    C* ptr;
    SQTRY()
    ptr = Var<C*>(vm, 1).value;
    SQCATCH_NOEXCEPT(vm) {
        SQCLEAR(vm); // clear the previous error
        return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
    }
    SQCATCH(vm) {
        return sq_throwerror(vm, SQWHAT(vm));
    }

    typedef V C::*M;
    M* memberPtr = NULL;
    sq_getuserdata(vm, -1, (SQUserPointer*)&memberPtr, NULL); // Get Member...
    M member = *memberPtr;

    PushVarR(vm, ptr->*member);

    return 1;
}

template <class C, class V>
inline SQInteger sqStaticGet(HSQUIRRELVM vm) {
    typedef V *M;
    M* memberPtr = NULL;
    sq_getuserdata(vm, -1, (SQUserPointer*)&memberPtr, NULL); // Get Member...
    M member = *memberPtr;

    PushVarR(vm, *member);

    return 1;
}

inline SQInteger sqVarGet(HSQUIRRELVM vm) {
    // Find the get method in the get table
    sq_push(vm, 2);
#if !defined (KALIBRI_NO_ERROR_CHECKING)
    if (SQ_FAILED(sq_rawget(vm, -2))) {
#if (SQUIRREL_VERSION_NUMBER>= 200) && (SQUIRREL_VERSION_NUMBER < 300) // Squirrel 2.x
        return sq_throwerror(vm, _SC("member variable not found"));
#else // Squirrel 3.x
        sq_pushnull(vm);
        return sq_throwobject(vm);
#endif
    }
#else
    sq_rawget(vm, -2);
#endif

    // push 'this'
    sq_push(vm, 1);

    // Call the getter
#if !defined (KALIBRI_NO_ERROR_CHECKING)
    SQRESULT result = sq_call(vm, 1, true, ErrorHandling::IsEnabled());
    if (SQ_FAILED(result)) {
        return sq_throwerror(vm, LastErrorString(vm).c_str());
    }
#else
    sq_call(vm, 1, true, ErrorHandling::IsEnabled());
#endif

    return 1;
}


//
// Variable Set
//

template <class C, class V>
inline SQInteger sqDefaultSet(HSQUIRRELVM vm) {
    C* ptr;
    SQTRY()
    ptr = Var<C*>(vm, 1).value;
    SQCATCH_NOEXCEPT(vm) {
        SQCLEAR(vm); // clear the previous error
        return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
    }
    SQCATCH(vm) {
        return sq_throwerror(vm, SQWHAT(vm));
    }

    typedef V C::*M;
    M* memberPtr = NULL;
    sq_getuserdata(vm, -1, (SQUserPointer*)&memberPtr, NULL); // Get Member...
    M member = *memberPtr;

    SQTRY()
    if (is_pointer<V>::value || is_reference<V>::value) {
        ptr->*member = Var<V>(vm, 2).value;
    } else {
        ptr->*member = Var<const V&>(vm, 2).value;
    }
    SQCATCH_NOEXCEPT(vm) {
        return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
    }
    SQCATCH(vm) {
        return sq_throwerror(vm, SQWHAT(vm));
    }

    return 0;
}

template <class C, class V>
inline SQInteger sqStaticSet(HSQUIRRELVM vm) {
    typedef V *M;
    M* memberPtr = NULL;
    sq_getuserdata(vm, -1, (SQUserPointer*)&memberPtr, NULL); // Get Member...
    M member = *memberPtr;

    SQTRY()
    if (is_pointer<V>::value || is_reference<V>::value) {
        *member = Var<V>(vm, 2).value;
    } else {
        *member = Var<const V&>(vm, 2).value;
    }
    SQCATCH_NOEXCEPT(vm) {
        return sq_throwerror(vm, SQWHAT_NOEXCEPT(vm));
    }
    SQCATCH(vm) {
        return sq_throwerror(vm, SQWHAT(vm));
    }

    return 0;
}

inline SQInteger sqVarSet(HSQUIRRELVM vm) {
    // Find the set method in the set table
    sq_push(vm, 2);
#if !defined (KALIBRI_NO_ERROR_CHECKING)
    if (SQ_FAILED(sq_rawget(vm, -2))) {
#if (SQUIRREL_VERSION_NUMBER>= 200) && (SQUIRREL_VERSION_NUMBER < 300) // Squirrel 2.x
        return sq_throwerror(vm, _SC("member variable not found"));
#else // Squirrel 3.x
        sq_pushnull(vm);
        return sq_throwobject(vm);
#endif
    }
#else
    sq_rawget(vm, -2);
#endif

    // push 'this'
    sq_push(vm, 1);
    sq_push(vm, 3);

    // Call the setter
#if !defined (KALIBRI_NO_ERROR_CHECKING)
    SQRESULT result = sq_call(vm, 2, false, ErrorHandling::IsEnabled());
    if (SQ_FAILED(result)) {
        return sq_throwerror(vm, LastErrorString(vm).c_str());
    }
#else
    sq_call(vm, 2, false, ErrorHandling::IsEnabled());
#endif

    return 0;
}

/// @endcond

}

#endif
