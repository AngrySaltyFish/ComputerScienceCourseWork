/****************************************************************************
** Meta object code from reading C++ file 'DownloadTab.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/DownloadTab.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownloadTab.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SearchList_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SearchList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SearchList_t qt_meta_stringdata_SearchList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SearchList"
QT_MOC_LITERAL(1, 11, 15), // "requestReceived"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 43, 5) // "reply"

    },
    "SearchList\0requestReceived\0\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void SearchList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchList *_t = static_cast<SearchList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SearchList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_SearchList.data,
      qt_meta_data_SearchList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SearchList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SearchList.stringdata0))
        return static_cast<void*>(const_cast< SearchList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int SearchList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_DownloadWidget_t {
    QByteArrayData data[6];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownloadWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownloadWidget_t qt_meta_stringdata_DownloadWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DownloadWidget"
QT_MOC_LITERAL(1, 15, 6), // "search"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "itemSelectionChanged"
QT_MOC_LITERAL(4, 44, 9), // "showVideo"
QT_MOC_LITERAL(5, 54, 20) // "processDownloadVideo"

    },
    "DownloadWidget\0search\0\0itemSelectionChanged\0"
    "showVideo\0processDownloadVideo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownloadWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void DownloadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownloadWidget *_t = static_cast<DownloadWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->search(); break;
        case 1: _t->itemSelectionChanged(); break;
        case 2: _t->showVideo(); break;
        case 3: _t->processDownloadVideo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DownloadWidget::staticMetaObject = {
    { &TabWidget::staticMetaObject, qt_meta_stringdata_DownloadWidget.data,
      qt_meta_data_DownloadWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DownloadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownloadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadWidget.stringdata0))
        return static_cast<void*>(const_cast< DownloadWidget*>(this));
    return TabWidget::qt_metacast(_clname);
}

int DownloadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
