#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <player.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qRegisterMetaType<Player>();
    qRegisterMetaType<P2D>();
    qRegisterMetaType<P2D*>();

    //Cria player de exemplo
    Player p1;
    p1.setSpeed(200.45);
    p1.setPlayerType(Player::PlayerType::NO_TYPE);
    p1.setAmmunition(31);

    P2D* ptr = new P2D();

    ptr->setX(10);
    ptr->setY(25);

    p1.setCoordinates(ptr);

    //Cria outro player de exemplo
    Player p2;
    p2.setSpeed(150.5);
    p2.setPlayerType(Player::PlayerType::TANK);
    p2.setAmmunition(5);

    P2D* ptr2 = new P2D();

    ptr->setX(50);
    ptr->setY(60);

    p2.setCoordinates(ptr2);

    //Cria lista de QVariants para enviar ao QML
    QVariantList list;
    //Armazena cada player temporariamente em var
    // para popular a tabela
    QVariant var;

    var.setValue(p1);
    list.append(var);
    var.setValue(p2);
    list.append(var);

   QQmlApplicationEngine engine;



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    //Envia a lista de players ao QML
    engine.rootContext()->setContextProperty("myList", list);
    engine.load(url);

    delete ptr;
    delete ptr2;

    return app.exec();
}
