/*
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Class.h"
#include "java/lang/Object.h"
#include "java/lang/String.h"
#include "java/lang/reflect/Modifier.h"

namespace java {
    namespace lang {
        namespace reflect {

            enum {
                mid_isPublic,
                mid_isStatic,
                mid_isNative,
                mid_isFinal,
                mid_isAbstract,
                mid_isPrivate,
                mid_isProtected,
                max_mid
            };

            Class *Modifier::class$ = NULL;
            jmethodID *Modifier::_mids = NULL;

            jclass Modifier::initializeClass(bool getOnly)
            {
                if (getOnly)
                    return (jclass) (class$ == NULL ? NULL : class$->this$);
                if (!class$)
                {
                    jclass cls = env->findClass("java/lang/reflect/Modifier");

                    _mids = new jmethodID[max_mid];
                    _mids[mid_isPublic] =
                        env->getStaticMethodID(cls, "isPublic",
                                               "(I)Z");
                    _mids[mid_isStatic] =
                        env->getStaticMethodID(cls, "isStatic",
                                               "(I)Z");
                    _mids[mid_isNative] =
                        env->getStaticMethodID(cls, "isNative",
                                               "(I)Z");
                    _mids[mid_isFinal] =
                        env->getStaticMethodID(cls, "isFinal",
                                               "(I)Z");
                    _mids[mid_isAbstract] =
                        env->getStaticMethodID(cls, "isAbstract",
                                               "(I)Z");
                    _mids[mid_isPrivate] =
                        env->getStaticMethodID(cls, "isPrivate",
                                               "(I)Z");
                    _mids[mid_isProtected] =
                        env->getStaticMethodID(cls, "isProtected",
                                               "(I)Z");

                    class$ = (Class *) new JObject(cls);
                }

                return (jclass) class$->this$;
            }

            int Modifier::isPublic(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isPublic], mod);
            }

            int Modifier::isStatic(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isStatic], mod);
            }

            int Modifier::isNative(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isNative], mod);
            }

            int Modifier::isFinal(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isFinal], mod);
            }

            int Modifier::isAbstract(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isAbstract], mod);
            }

            int Modifier::isPrivate(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isPrivate], mod);
            }

            int Modifier::isProtected(int mod)
            {
                jclass cls = env->getClass(initializeClass);
                return (int) env->callStaticBooleanMethod(cls, _mids[mid_isProtected], mod);
            }
        }
    }
}


#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {
        namespace reflect {

            static PyObject *t_Modifier_isPublic(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isStatic(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isNative(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isFinal(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isAbstract(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isPrivate(PyTypeObject *type, PyObject *arg);
            static PyObject *t_Modifier_isProtected(PyTypeObject *type, PyObject *arg);

            static PyMethodDef t_Modifier__methods_[] = {
                DECLARE_METHOD(t_Modifier, isPublic, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isStatic, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isNative, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isFinal, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isAbstract, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isPrivate, METH_O | METH_CLASS),
                DECLARE_METHOD(t_Modifier, isProtected, METH_O | METH_CLASS),
                { NULL, NULL, 0, NULL }
            };

            static PyType_Slot PY_TYPE_SLOTS(Modifier)[] = {
                { Py_tp_methods, t_Modifier__methods_ },
                { Py_tp_init, (void *) abstract_init },
                { 0, 0 }
            };

            static PyType_Def *PY_TYPE_BASES(Modifier)[] = {
                &PY_TYPE_DEF(Object),
                NULL
            };

            DEFINE_TYPE(Modifier, t_Modifier, Modifier);

            static PyObject *t_Modifier_isPublic(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isPublic;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isPublic = Modifier::isPublic(mod));
                Py_RETURN_BOOL(isPublic);
            }

            static PyObject *t_Modifier_isStatic(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isStatic;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isStatic = Modifier::isStatic(mod));
                Py_RETURN_BOOL(isStatic);
            }

            static PyObject *t_Modifier_isNative(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isNative;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isNative = Modifier::isNative(mod));
                Py_RETURN_BOOL(isNative);
            }

            static PyObject *t_Modifier_isFinal(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isFinal;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isFinal = Modifier::isFinal(mod));
                Py_RETURN_BOOL(isFinal);
            }

            static PyObject *t_Modifier_isAbstract(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isAbstract;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isAbstract = Modifier::isAbstract(mod));
                Py_RETURN_BOOL(isAbstract);
            }

            static PyObject *t_Modifier_isPrivate(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isPrivate;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isPrivate = Modifier::isPrivate(mod));
                Py_RETURN_BOOL(isPrivate);
            }

            static PyObject *t_Modifier_isProtected(PyTypeObject *type, PyObject *arg)
            {
                if (!PyLong_Check(arg))
                {
                    PyErr_SetObject(PyExc_TypeError, arg);
                    return NULL;
                }

                int mod = PyLong_AsLong(arg);
                int isProtected;

                if (PyErr_Occurred())
                    return NULL;

                OBJ_CALL(isProtected = Modifier::isProtected(mod));
                Py_RETURN_BOOL(isProtected);
            }
        }
    }
}
