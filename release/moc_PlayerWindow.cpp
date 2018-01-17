/****************************************************************************
** Meta object code from reading C++ file 'PlayerWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/PlayerWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerWindow_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerWindow_t qt_meta_stringdata_PlayerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayerWindow"
QT_MOC_LITERAL(1, 13, 9), // "openMedia"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "VideoYoutube*"
QT_MOC_LITERAL(4, 38, 12), // "seekBySlider"
QT_MOC_LITERAL(5, 51, 5), // "value"
QT_MOC_LITERAL(6, 57, 9), // "playPause"
QT_MOC_LITERAL(7, 67, 13), // "startDownload"
QT_MOC_LITERAL(8, 81, 13), // "changeQuality"
QT_MOC_LITERAL(9, 95, 22), // "changeDownloadProgress"
QT_MOC_LITERAL(10, 118, 12), // "updateSlider"
QT_MOC_LITERAL(11, 131, 16) // "updateSliderUnit"

    },
    "PlayerWindow\0openMedia\0\0VideoYoutube*\0"
    "seekBySlider\0value\0playPause\0startDownload\0"
    "changeQuality\0changeDownloadProgress\0"
    "updateSlider\0updateSliderUnit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    1,   67,    2, 0x0a /* Public */,
       4,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    2,   76,    2, 0x09 /* Protected */,
      10,    1,   81,    2, 0x09 /* Protected */,
      10,    0,   84,    2, 0x09 /* Protected */,
      11,    0,   85,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerWindow *_t = static_cast<PlayerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openMedia((*reinterpret_cast< VideoYoutube*(*)>(_a[1]))); break;
        case 1: _t->seekBySlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->seekBySlider(); break;
        case 3: _t->playPause(); break;
        case 4: _t->startDownload(); break;
        case 5: _t->changeQuality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changeDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 7: _t->updateSlider((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->updateSlider(); break;
        case 9: _t->updateSliderUnit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VideoYoutube* >(); break;
            }
            break;
        }
    }
}

const QMetaObject PlayerWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerWindow.data,
      qt_meta_data_PlayerWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerWindow.stringdata0))
        return static_cast<void*>(const_cast< PlayerWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
struct qt_meta_stringdata_AudioPlayer_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioPlayer_t qt_meta_stringdata_AudioPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AudioPlayer"
QT_MOC_LITERAL(1, 12, 9), // "openMedia"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 38, 8), // "nextSong"
QT_MOC_LITERAL(5, 47, 12) // "previousSong"

    },
    "AudioPlayer\0openMedia\0\0QList<QString>\0"
    "nextSong\0previousSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       4,    0,   34,    2, 0x08 /* Private */,
       5,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioPlayer *_t = static_cast<AudioPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openMedia((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->nextSong(); break;
        case 2: _t->previousSong(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    }
}

const QMetaObject AudioPlayer::staticMetaObject = {
    { &PlayerWindow::staticMetaObject, qt_meta_stringdata_AudioPlayer.data,
      qt_meta_data_AudioPlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AudioPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioPlayer.stringdata0))
        return static_cast<void*>(const_cast< AudioPlayer*>(this));
    return PlayerWindow::qt_metacast(_clname);
}

int AudioPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PlayerWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
