/****************************************************************************
** Meta object code from reading C++ file 'DataHandler.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/DataHandler.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataHandler.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseHandler_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseHandler_t qt_meta_stringdata_DatabaseHandler = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DatabaseHandler"
QT_MOC_LITERAL(1, 16, 15), // "playlistCreated"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "createPlaylist"
QT_MOC_LITERAL(4, 48, 25), // "std::shared_ptr<Playlist>"
QT_MOC_LITERAL(5, 74, 8) // "allSongs"

    },
    "DatabaseHandler\0playlistCreated\0\0"
    "createPlaylist\0std::shared_ptr<Playlist>\0"
    "allSongs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   30,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 4, QMetaType::QString, QMetaType::Bool,    2,    5,
    0x80000000 | 4, QMetaType::QString,    2,

       0        // eod
};

void DatabaseHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseHandler *_t = static_cast<DatabaseHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playlistCreated(); break;
        case 1: { std::shared_ptr<Playlist> _r = _t->createPlaylist((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::shared_ptr<Playlist>*>(_a[0]) = std::move(_r); }  break;
        case 2: { std::shared_ptr<Playlist> _r = _t->createPlaylist((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::shared_ptr<Playlist>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DatabaseHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatabaseHandler::playlistCreated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DatabaseHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DatabaseHandler.data,
      qt_meta_data_DatabaseHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseHandler.stringdata0))
        return static_cast<void*>(const_cast< DatabaseHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int DatabaseHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DatabaseHandler::playlistCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_PlaylistView_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistView_t qt_meta_stringdata_PlaylistView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlaylistView"
QT_MOC_LITERAL(1, 13, 9), // "deleteRow"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "reorderSong"
QT_MOC_LITERAL(4, 36, 8) // "playSong"

    },
    "PlaylistView\0deleteRow\0\0reorderSong\0"
    "playSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    2,   32,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void PlaylistView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistView *_t = static_cast<PlaylistView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->reorderSong((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->playSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlaylistView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlaylistView::deleteRow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlaylistView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlaylistView::reorderSong)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlaylistView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlaylistView::playSong)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PlaylistView::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_PlaylistView.data,
      qt_meta_data_PlaylistView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistView.stringdata0))
        return static_cast<void*>(const_cast< PlaylistView*>(this));
    return QTableView::qt_metacast(_clname);
}

int PlaylistView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PlaylistView::deleteRow(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlaylistView::reorderSong(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlaylistView::playSong(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_Playlist_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Playlist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Playlist_t qt_meta_stringdata_Playlist = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Playlist"
QT_MOC_LITERAL(1, 9, 9), // "playTrack"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 35, 10), // "reorderRow"
QT_MOC_LITERAL(5, 46, 9), // "removeRow"
QT_MOC_LITERAL(6, 56, 8) // "playSong"

    },
    "Playlist\0playTrack\0\0QList<QString>\0"
    "reorderRow\0removeRow\0playSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Playlist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   39,    2, 0x08 /* Private */,
       5,    1,   44,    2, 0x08 /* Private */,
       6,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Playlist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Playlist *_t = static_cast<Playlist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playTrack((*reinterpret_cast< QList<QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->reorderRow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->removeRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->playSong((*reinterpret_cast< int(*)>(_a[1]))); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Playlist::*_t)(QList<QString> , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Playlist::playTrack)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Playlist::staticMetaObject = {
    { &QSqlRelationalTableModel::staticMetaObject, qt_meta_stringdata_Playlist.data,
      qt_meta_data_Playlist,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Playlist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Playlist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Playlist.stringdata0))
        return static_cast<void*>(const_cast< Playlist*>(this));
    return QSqlRelationalTableModel::qt_metacast(_clname);
}

int Playlist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlRelationalTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Playlist::playTrack(QList<QString> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
