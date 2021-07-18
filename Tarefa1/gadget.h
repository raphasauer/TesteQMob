#ifndef GADGET_H
#define GADGET_H

#include <QObject>

struct P2D
{
    Q_GADGET
    Q_PROPERTY(P2D p2d READ getP2D)
    Q_PROPERTY(float m_x READ getX WRITE setX)
    Q_PROPERTY(float m_y READ getY WRITE setY)

public:
    float m_x;
    float m_y;
    void setX(float x) {this->m_x = x;}
    void setY(float y) {this->m_y = y;}
    float getX() {return this->m_x;}
    float getY() {return this->m_y;}
    P2D getP2D() {return *this;}

}; Q_DECLARE_METATYPE(P2D)

struct Player {
    Q_GADGET
public:

    enum PlayerType {
        NO_TYPE = 0,
        TANK,
        CHARACTER,
        SHIP
    }; Q_ENUM(PlayerType)

    Q_PROPERTY(float m_speed READ getSpeed WRITE setSpeed)
    Q_PROPERTY(PlayerType m_playerType READ getPlayerType WRITE setPlayerType)
    Q_PROPERTY(quint16 m_ammunition READ getAmmunition WRITE setAmmunition)
    Q_PROPERTY(bool m_active READ isActive WRITE setActive)
    Q_PROPERTY(quint8 m_numberOfCoordinates READ getNumberOfCoordinates WRITE setNumberOfCoordinates)
    Q_PROPERTY(P2D *m_coordinates READ getCoordinates)

    Player getPlayer() { return *this;}
    float getSpeed() {return m_speed;}
    PlayerType getPlayerType() { return m_playerType;}
    quint8 getAmmunition() { return m_ammunition;}
    bool isActive() {return m_active;}
    quint8 getNumberOfCoordinates() {return m_numberOfCoordinates;}
    P2D* getCoordinates() {return m_coordinates;}

public:
    PlayerType m_playerType;
    float m_speed;
    quint16 m_ammunition;
    bool m_active;
    quint8 m_numberOfCoordinates;
    P2D *m_coordinates;

    void setAmmunition(quint16 x) {m_ammunition = x;}
    void setNumberOfCoordinates(quint8 x) {m_numberOfCoordinates = x;}
    void setSpeed(float x) {m_speed = x;}
    void setActive(bool x) {m_active = x;}
    void setPlayerType(int x) {m_playerType = (PlayerType) x;}

}; Q_DECLARE_METATYPE(Player)

#endif // GADGET_H
