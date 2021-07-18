#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>


struct P2D
{
        Q_GADGET
        Q_PROPERTY(P2D p2d READ getP2D )
        Q_PROPERTY(float m_x READ getX WRITE setX)
        Q_PROPERTY(float m_y READ getY WRITE setY)



    public:
        float m_x;
        float m_y;
        P2D getP2D() {return *this;}
        float getX() {return this->m_x;}
        void setX(float x) {this->m_x = x;}
        float getY() {return this->m_y;}
        void setY(float y) {this->m_y = y;}

    }; Q_DECLARE_METATYPE(P2D)

struct Player {

    Q_GADGET


    Q_PROPERTY(Player player READ getPlayer)
    Q_PROPERTY(PlayerType m_playerType READ getPlayerType WRITE setPlayerType)
    Q_PROPERTY(float m_speed READ getSpeed WRITE setSpeed)
    Q_PROPERTY(quint16 m_ammunition READ getAmmunition WRITE setAmmunition)
    Q_PROPERTY(bool m_active READ isActive WRITE setActive)
    Q_PROPERTY(quint8 m_numberOfCoordinates READ getNumberOfCoordinates WRITE setNumberOfCoordinates)
    Q_PROPERTY(P2D* m_coordinates READ getCoordinates WRITE setCoordinates )


public:
    enum class PlayerType {
        NO_TYPE = 0,
        TANK,
        CHARACTER,
        SHIP
    }; Q_ENUM(PlayerType)

    PlayerType m_playerType;
    float m_speed;
    quint16 m_ammunition;
    bool m_active;
    quint8 m_numberOfCoordinates;
    P2D *m_coordinates;

    Player getPlayer() { return *this;}

    float getSpeed() {return this->m_speed;}
    void setSpeed(float speed) {this->m_speed = speed;}

    PlayerType getPlayerType() { return m_playerType;}
    void setPlayerType(PlayerType pType) {this->m_playerType = pType;}

    quint16 getAmmunition() {return this->m_ammunition;}
    void setAmmunition(quint16 ammunition) {this->m_ammunition = ammunition;}

    bool isActive() {return this->m_active;}
    void setActive(bool active) {this->m_active = active;}

    quint8 getNumberOfCoordinates() {return this->m_numberOfCoordinates;}
    void setNumberOfCoordinates(quint8 coordinates) {this->m_numberOfCoordinates = coordinates;}

    P2D* getCoordinates() {return this->m_coordinates;}

    void setCoordinates(P2D *ptr)
    {

        this->m_coordinates = ptr;
    }

}; Q_DECLARE_METATYPE(Player)
#endif
