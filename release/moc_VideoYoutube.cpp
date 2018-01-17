/****************************************************************************
** Meta object code from reading C++ file 'VideoYoutube.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/VideoYoutube.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoYoutube.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoYoutube_t {
    QByteArrayData data[9];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoYoutube_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoYoutube_t qt_meta_stringdata_VideoYoutube = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VideoYoutube"
QT_MOC_LITERAL(1, 13, 5), // "error"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "VideoYoutube*"
QT_MOC_LITERAL(4, 34, 17), // "analysingFinished"
QT_MOC_LITERAL(5, 52, 21), // "audioDownloadFinished"
QT_MOC_LITERAL(6, 74, 15), // "handleDownloads"
QT_MOC_LITERAL(7, 90, 21), // "slotAnalysingFinished"
QT_MOC_LITERAL(8, 112, 12) // "networkError"

    },
    "VideoYoutube\0error\0\0VideoYoutube*\0"
    "analysingFinished\0audioDownloadFinished\0"
    "handleDownloads\0slotAnalysingFinished\0"
    "networkError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoYoutube[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       1,    2,   52,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    1,

       0        // eod
};

void VideoYoutube::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoYoutube *_t = static_cast<VideoYoutube *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< VideoYoutube*(*)>(_a[2]))); break;
        case 2: _t->analysingFinished(); break;
        case 3: _t->audioDownloadFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handleDownloads(); break;
        case 5: _t->slotAnalysingFinished(); break;
        case 6: _t->networkError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoYoutube* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoYoutube::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoYoutube::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoYoutube::*_t)(QString , VideoYoutube * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoYoutube::error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VideoYoutube::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoYoutube::analysingFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (VideoYoutube::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoYoutube::audioDownloadFinished)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject VideoYoutube::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VideoYoutube.data,
      qt_meta_data_VideoYoutube,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VideoYoutube::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoYoutube::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoYoutube.stringdata0))
        return static_cast<void*>(const_cast< VideoYoutube*>(this));
    return QObject::qt_metacast(_clname);
}

int VideoYoutube::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void VideoYoutube::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoYoutube::error(QString _t1, VideoYoutube * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoYoutube::analysingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VideoYoutube::audioDownloadFinished(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
