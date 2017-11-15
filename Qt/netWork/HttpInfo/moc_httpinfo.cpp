/****************************************************************************
** Meta object code from reading C++ file 'httpinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "httpinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HttpInfo_t {
    QByteArrayData data[11];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpInfo_t qt_meta_stringdata_HttpInfo = {
    {
QT_MOC_LITERAL(0, 0, 8), // "HttpInfo"
QT_MOC_LITERAL(1, 9, 20), // "on_getTimeBt_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 23), // "on_getWeatherBt_clicked"
QT_MOC_LITERAL(4, 55, 23), // "on_getAddressBt_clicked"
QT_MOC_LITERAL(5, 79, 8), // "get_time"
QT_MOC_LITERAL(6, 88, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 103, 5), // "reply"
QT_MOC_LITERAL(8, 109, 11), // "get_weather"
QT_MOC_LITERAL(9, 121, 11), // "get_address"
QT_MOC_LITERAL(10, 133, 9) // "readReply"

    },
    "HttpInfo\0on_getTimeBt_clicked\0\0"
    "on_getWeatherBt_clicked\0on_getAddressBt_clicked\0"
    "get_time\0QNetworkReply*\0reply\0get_weather\0"
    "get_address\0readReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
       9,    1,   58,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

void HttpInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpInfo *_t = static_cast<HttpInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_getTimeBt_clicked(); break;
        case 1: _t->on_getWeatherBt_clicked(); break;
        case 2: _t->on_getAddressBt_clicked(); break;
        case 3: _t->get_time((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->get_weather((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->get_address((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->readReply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject HttpInfo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HttpInfo.data,
      qt_meta_data_HttpInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HttpInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HttpInfo.stringdata0))
        return static_cast<void*>(const_cast< HttpInfo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HttpInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
