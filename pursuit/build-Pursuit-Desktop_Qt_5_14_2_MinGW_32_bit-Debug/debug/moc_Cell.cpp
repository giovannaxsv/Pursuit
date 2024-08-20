/****************************************************************************
** Meta object code from reading C++ file 'Cell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Pursuit/Cell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cell_t {
    QByteArrayData data[24];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cell_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cell_t qt_meta_stringdata_Cell = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cell"
QT_MOC_LITERAL(1, 5, 15), // "playableChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "playable"
QT_MOC_LITERAL(4, 31, 13), // "playerChanged"
QT_MOC_LITERAL(5, 45, 7), // "Player*"
QT_MOC_LITERAL(6, 53, 6), // "player"
QT_MOC_LITERAL(7, 60, 12), // "stateChanged"
QT_MOC_LITERAL(8, 73, 11), // "Cell::State"
QT_MOC_LITERAL(9, 85, 5), // "state"
QT_MOC_LITERAL(10, 91, 11), // "setPlayable"
QT_MOC_LITERAL(11, 103, 9), // "setPlayer"
QT_MOC_LITERAL(12, 113, 8), // "setState"
QT_MOC_LITERAL(13, 122, 5), // "reset"
QT_MOC_LITERAL(14, 128, 10), // "updateCell"
QT_MOC_LITERAL(15, 139, 3), // "row"
QT_MOC_LITERAL(16, 143, 3), // "col"
QT_MOC_LITERAL(17, 147, 5), // "empty"
QT_MOC_LITERAL(18, 153, 7), // "blocked"
QT_MOC_LITERAL(19, 161, 4), // "used"
QT_MOC_LITERAL(20, 166, 5), // "State"
QT_MOC_LITERAL(21, 172, 5), // "Empty"
QT_MOC_LITERAL(22, 178, 7), // "Blocked"
QT_MOC_LITERAL(23, 186, 4) // "Used"

    },
    "Cell\0playableChanged\0\0playable\0"
    "playerChanged\0Player*\0player\0stateChanged\0"
    "Cell::State\0state\0setPlayable\0setPlayer\0"
    "setState\0reset\0updateCell\0row\0col\0"
    "empty\0blocked\0used\0State\0Empty\0Blocked\0"
    "Used"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cell[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   74, // properties
       1,  106, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   63,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,
      13,    0,   72,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Int, 0x00095103,
      16, QMetaType::Int, 0x00095103,
       3, QMetaType::Bool, 0x00495103,
       6, 0x80000000 | 5, 0x0049510b,
       9, 0x80000000 | 8, 0x0049510b,
      17, QMetaType::Bool, 0x00095001,
      18, QMetaType::Bool, 0x00095001,
      19, QMetaType::Bool, 0x00095001,

 // properties: notify_signal_id
       0,
       0,
       0,
       1,
       2,
       0,
       0,
       0,

 // enums: name, alias, flags, count, data
      20,   20, 0x0,    3,  111,

 // enum data: key, value
      21, uint(Cell::Empty),
      22, uint(Cell::Blocked),
      23, uint(Cell::Used),

       0        // eod
};

void Cell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->playerChanged((*reinterpret_cast< Player*(*)>(_a[1]))); break;
        case 2: _t->stateChanged((*reinterpret_cast< Cell::State(*)>(_a[1]))); break;
        case 3: _t->setPlayable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setPlayer((*reinterpret_cast< Player*(*)>(_a[1]))); break;
        case 5: _t->setState((*reinterpret_cast< Cell::State(*)>(_a[1]))); break;
        case 6: _t->reset(); break;
        case 7: _t->updateCell(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cell::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::playableChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cell::*)(Player * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::playerChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cell::*)(Cell::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::stateChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->row(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->col(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isPlayable(); break;
        case 3: *reinterpret_cast< Player**>(_v) = _t->player(); break;
        case 4: *reinterpret_cast< Cell::State*>(_v) = _t->state(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->isEmpty(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isBlocked(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isUsed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRow(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCol(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setPlayable(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setPlayer(*reinterpret_cast< Player**>(_v)); break;
        case 4: _t->setState(*reinterpret_cast< Cell::State*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Cell::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_Cell.data,
    qt_meta_data_Cell,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cell.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Cell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Cell::playableChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cell::playerChanged(Player * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cell::stateChanged(Cell::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
