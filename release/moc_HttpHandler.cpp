/****************************************************************************
** Meta object code from reading C++ file 'HttpHandler.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/HttpHandler.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpHandler.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpHandler_t {
    QByteArrayData data[18];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpHandler_t qt_meta_stringdata_HttpHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HttpHandler"
QT_MOC_LITERAL(1, 12, 5), // "error"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 16), // "downloadProgress"
QT_MOC_LITERAL(4, 36, 16), // "downloadFinished"
QT_MOC_LITERAL(5, 53, 9), // "download*"
QT_MOC_LITERAL(6, 63, 20), // "allDownloadsFinished"
QT_MOC_LITERAL(7, 84, 15), // "progressChanged"
QT_MOC_LITERAL(8, 100, 13), // "bytesReceived"
QT_MOC_LITERAL(9, 114, 10), // "bytesTotal"
QT_MOC_LITERAL(10, 125, 11), // "dataHandler"
QT_MOC_LITERAL(11, 137, 22), // "handleFinishedDownload"
QT_MOC_LITERAL(12, 160, 18), // "handleNetworkReply"
QT_MOC_LITERAL(13, 179, 14), // "QNetworkReply*"
QT_MOC_LITERAL(14, 194, 14), // "handleSSLError"
QT_MOC_LITERAL(15, 209, 5), // "reply"
QT_MOC_LITERAL(16, 215, 16), // "QList<QSslError>"
QT_MOC_LITERAL(17, 232, 6) // "errors"

    },
    "HttpHandler\0error\0\0downloadProgress\0"
    "downloadFinished\0download*\0"
    "allDownloadsFinished\0progressChanged\0"
    "bytesReceived\0bytesTotal\0dataHandler\0"
    "handleFinishedDownload\0handleNetworkReply\0"
    "QNetworkReply*\0handleSSLError\0reply\0"
    "QList<QSslError>\0errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    2,   62,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,
       7,    2,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   76,    2, 0x09 /* Protected */,
      11,    1,   77,    2, 0x09 /* Protected */,
      12,    1,   80,    2, 0x09 /* Protected */,
      14,    2,   83,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 16,   15,   17,

       0        // eod
};

void HttpHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpHandler *_t = static_cast<HttpHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 2: _t->downloadFinished((*reinterpret_cast< download*(*)>(_a[1]))); break;
        case 3: _t->allDownloadsFinished(); break;
        case 4: _t->progressChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->dataHandler(); break;
        case 6: _t->handleFinishedDownload((*reinterpret_cast< download*(*)>(_a[1]))); break;
        case 7: _t->handleNetworkReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->handleSSLError((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HttpHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpHandler::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (HttpHandler::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpHandler::downloadProgress)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (HttpHandler::*_t)(download * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpHandler::downloadFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (HttpHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpHandler::allDownloadsFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (HttpHandler::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HttpHandler::progressChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject HttpHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpHandler.data,
      qt_meta_data_HttpHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HttpHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpHandler.stringdata0))
        return static_cast<void*>(const_cast< HttpHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int HttpHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void HttpHandler::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpHandler::downloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HttpHandler::downloadFinished(download * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HttpHandler::allDownloadsFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void HttpHandler::progressChanged(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
