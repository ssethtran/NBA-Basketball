//
// Created by Hiep on 11/11/2021.
//

#include "ModdedLabel.h"

ModdedLabel::ModdedLabel() {

}

void ModdedLabel::updateAccessibleName()
{
    setAccessibleName(this->text());
}
