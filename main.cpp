#include <QApplication>
#include <QtWebEngineWidgets>

static const auto homepage = "http://www.google.com";

int main(int argc, char *argv[])
{
    const auto initialUrl = argc < 2? homepage : argv[1];

    QApplication app{argc, argv};
    QWebEngineView webEngine{};
    webEngine.load(QUrl::fromUserInput(initialUrl));
    webEngine.show();

    return app.exec();
}
