/****************************************************************************
** Meta object code from reading C++ file 'TicTacController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt/cm/TicTacToe/TicTacController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TicTacController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TicTacController_t {
    QByteArrayData data[12];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TicTacController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TicTacController_t qt_meta_stringdata_TicTacController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TicTacController"
QT_MOC_LITERAL(1, 17, 10), // "rowChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "columnChanged"
QT_MOC_LITERAL(4, 43, 13), // "playerChanged"
QT_MOC_LITERAL(5, 57, 8), // "aIplayer"
QT_MOC_LITERAL(6, 66, 3), // "row"
QT_MOC_LITERAL(7, 70, 6), // "column"
QT_MOC_LITERAL(8, 77, 13), // "humanPlayerAt"
QT_MOC_LITERAL(9, 91, 8), // "rowCount"
QT_MOC_LITERAL(10, 100, 11), // "columnCount"
QT_MOC_LITERAL(11, 112, 12) // "playerSymbol"

    },
    "TicTacController\0rowChanged\0\0columnChanged\0"
    "playerChanged\0aIplayer\0row\0column\0"
    "humanPlayerAt\0rowCount\0columnCount\0"
    "playerSymbol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TicTacController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    7,

 // properties: name, type, flags
       9, QMetaType::UInt, 0x00495003,
      10, QMetaType::UInt, 0x00495003,
      11, QMetaType::Char, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void TicTacController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TicTacController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rowChanged(); break;
        case 1: _t->columnChanged(); break;
        case 2: _t->playerChanged(); break;
        case 3: _t->aIplayer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->humanPlayerAt((*reinterpret_cast< const uint(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TicTacController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacController::rowChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TicTacController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacController::columnChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TicTacController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacController::playerChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TicTacController::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacController::aIplayer)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TicTacController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->getRows(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->getColumns(); break;
        case 2: *reinterpret_cast< char*>(_v) = _t->getPlayerSymbol(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TicTacController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRows(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setColumns(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setPlayerSymbol(*reinterpret_cast< char*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TicTacController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TicTacController.data,
    qt_meta_data_TicTacController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TicTacController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TicTacController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TicTacController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TicTacController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TicTacController::rowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TicTacController::columnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TicTacController::playerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TicTacController::aIplayer(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
