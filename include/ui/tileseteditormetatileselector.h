#ifndef TILESETEDITORMETATILESELECTOR_H
#define TILESETEDITORMETATILESELECTOR_H

#include "selectablepixmapitem.h"
#include "tileset.h"

class TilesetEditorMetatileSelector: public SelectablePixmapItem {
    Q_OBJECT
public:
    TilesetEditorMetatileSelector(Tileset *primaryTileset, Tileset *secondaryTileset): SelectablePixmapItem(32, 32, 1, 1) {
        this->primaryTileset = primaryTileset;
        this->secondaryTileset = secondaryTileset;
        this->numMetatilesWide = 8;
        setAcceptHoverEvents(true);
    }
    void draw();
    void select(uint16_t metatileId);
    void setTilesets(Tileset*, Tileset*);
    uint16_t getSelectedMetatile();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    void hoverMoveEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);

private:
    Tileset *primaryTileset;
    Tileset *secondaryTileset;
    uint16_t selectedMetatile;
    int numMetatilesWide;
    void updateSelectedMetatile();
    uint16_t getMetatileId(int x, int y);
    QPoint getMetatileIdCoords(uint16_t);

signals:
    void hoveredMetatileChanged(uint16_t);
    void hoveredMetatileCleared();
    void selectedMetatileChanged(uint16_t);
};

#endif // TILESETEDITORMETATILESELECTOR_H
