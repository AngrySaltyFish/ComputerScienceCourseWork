/****************************************************************************
** Meta object code from reading C++ file 'LibraryTab.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/LibraryTab.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LibraryTab.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LibraryTab_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LibraryTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LibraryTab_t qt_meta_stringdata_LibraryTab = {
    {
QT_MOC_LITERAL(0, 0, 10) // "LibraryTab"

    },
    "LibraryTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LibraryTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LibraryTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LibraryTab::staticMetaObject = {
    { &TabWidget::staticMetaObject, qt_meta_stringdata_LibraryTab.data,
      qt_meta_data_LibraryTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LibraryTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LibraryTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LibraryTab.stringdata0))
        return static_cast<void*>(const_cast< LibraryTab*>(this));
    return TabWidget::qt_metacast(_clname);
}

int LibraryTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TabWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PlayListView_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayListView_t qt_meta_stringdata_PlayListView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PlayListView"
QT_MOC_LITERAL(1, 13, 14), // "changePlaylist"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "dropEvent"
QT_MOC_LITERAL(4, 39, 11), // "QDropEvent*"
QT_MOC_LITERAL(5, 51, 13) // "extractFromDB"

    },
    "PlayListView\0changePlaylist\0\0dropEvent\0"
    "QDropEvent*\0extractFromDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayListView[] = {

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
       1,    1,   29,    2, 0x08 /* Private */,
       3,    1,   32,    2, 0x08 /* Private */,
       5,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void PlayListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayListView *_t = static_cast<PlayListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changePlaylist((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 2: _t->extractFromDB(); break;
        default: ;
        }
    }
}

const QMetaObject PlayListView::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_PlayListView.data,
      qt_meta_data_PlayListView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayListView.stringdata0))
        return static_cast<void*>(const_cast< PlayListView*>(this));
    return QListWidget::qt_metacast(_clname);
}

int PlayListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_PlaylistAdder_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlaylistAdder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlaylistAdder_t qt_meta_stringdata_PlaylistAdder = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PlaylistAdder"
QT_MOC_LITERAL(1, 14, 14), // "createPlaylist"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10) // "btnPressed"

    },
    "PlaylistAdder\0createPlaylist\0\0btnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlaylistAdder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void PlaylistAdder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlaylistAdder *_t = static_cast<PlaylistAdder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createPlaylist((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->btnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlaylistAdder::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlaylistAdder::createPlaylist)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PlaylistAdder::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlaylistAdder.data,
      qt_meta_data_PlaylistAdder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlaylistAdder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlaylistAdder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlaylistAdder.stringdata0))
        return static_cast<void*>(const_cast< PlaylistAdder*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlaylistAdder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PlaylistAdder::createPlaylist(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
