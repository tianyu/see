#include <QApplication>
#include <QtWebEngineWidgets>
#include <QStringList>
#include <cassert>

static const auto homepage = "http://www.google.com";

QString getInitialUrl(QStringList args) {
    if (args.size() < 2) return homepage;

    if (args.size() == 2) return args.at(1);

    assert(args.size() > 2);
    QStringList query{ args };
    query.pop_front();
    query.pop_front();

    return QString(args.at(1))
        .replace("%s", "%1")
        .arg(query.join(' '));
}

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};
    QWebEngineView webEngine{};
    webEngine.load(QUrl::fromUserInput(getInitialUrl(app.arguments())));
    webEngine.show();

    return app.exec();
}
