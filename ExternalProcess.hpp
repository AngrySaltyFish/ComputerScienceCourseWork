#include <QProcess>


class ConverterThread : public QObject
{
    Q_OBJECT;

    public:
    ConverterThread(QList < QString >, QString, bool);
    void convert();

    private:
    QProcess *convertProcess;
    bool convertVideo;

    signals:
    void finished();
    void changeProgress();
    void error(QString err);

    private slots:
    void convertStatus(int, QProcess::ExitStatus);

    protected:
    int processCount;
    QByteArray findFile(QString);
    QStringList args;
    QList < QString > trackList;
    QString programName;
};

class BurnerThread : public ConverterThread
{
    Q_OBJECT;

    public:
    explicit BurnerThread(QList < QString >, QString);

    private:
    QProcess *process;

    private slots:
    void extractDevId();
    void startBurn();
};
