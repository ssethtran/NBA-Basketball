//
// Created by Hiep on 11/11/2021.
//

#ifndef NBA_BASKETBALL_MODDEDLABEL_H
#define NBA_BASKETBALL_MODDEDLABEL_H
#include <QLabel>
#include <iomanip>

class ModdedLabel: public QLabel
{
    Q_OBJECT

public:
    ModdedLabel();

public slots:
            void updateAccessibleName();
};


#endif //NBA_BASKETBALL_MODDEDLABEL_H
