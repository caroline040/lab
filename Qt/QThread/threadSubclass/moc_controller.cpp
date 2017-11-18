/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_controller_t {
    QByteArrayData data[15];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controller_t qt_meta_stringdata_controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "controller"
QT_MOC_LITERAL(1, 11, 7), // "recvMsg"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "msg"
QT_MOC_LITERAL(4, 24, 9), // "progress1"
QT_MOC_LITERAL(5, 34, 7), // "percent"
QT_MOC_LITERAL(6, 42, 9), // "progress2"
QT_MOC_LITERAL(7, 52, 20), // "on_btnStart1_clicked"
QT_MOC_LITERAL(8, 73, 19), // "on_btnTerm1_clicked"
QT_MOC_LITERAL(9, 93, 16), // "on_btnF1_clicked"
QT_MOC_LITERAL(10, 110, 16), // "on_btnF2_clicked"
QT_MOC_LITERAL(11, 127, 20), // "on_btnStart2_clicked"
QT_MOC_LITERAL(12, 148, 19), // "on_btnTerm2_clicked"
QT_MOC_LITERAL(13, 168, 16), // "on_btnF3_clicked"
QT_MOC_LITERAL(14, 185, 16) // "on_btnF4_clicked"

    },
    "controller\0recvMsg\0\0msg\0progress1\0"
    "percent\0progress2\0on_btnStart1_clicked\0"
    "on_btnTerm1_clicked\0on_btnF1_clicked\0"
    "on_btnF2_clicked\0on_btnStart2_clicked\0"
    "on_btnTerm2_clicked\0on_btnF3_clicked\0"
    "on_btnF4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       6,    1,   75,    2, 0x08 /* Private */,
       7,    0,   78,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controller *_t = static_cast<controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->progress1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->progress2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_btnStart1_clicked(); break;
        case 4: _t->on_btnTerm1_clicked(); break;
        case 5: _t->on_btnF1_clicked(); break;
        case 6: _t->on_btnF2_clicked(); break;
        case 7: _t->on_btnStart2_clicked(); break;
        case 8: _t->on_btnTerm2_clicked(); break;
        case 9: _t->on_btnF3_clicked(); break;
        case 10: _t->on_btnF4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject controller::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_controller.data,
      qt_meta_data_controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_controller.stringdata0))
        return static_cast<void*>(const_cast< controller*>(this));
    return QWidget::qt_metacast(_clname);
}

int controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
