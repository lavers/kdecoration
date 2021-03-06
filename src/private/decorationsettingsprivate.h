/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KDECORATION2_DECORATION_SETTINGS_PRIVATE_H
#define KDECORATION2_DECORATION_SETTINGS_PRIVATE_H

#include <kdecoration2/private/kdecoration2_private_export.h>
#include "../decorationdefines.h"
#include <QVector>
#include <QFont>
#include <QFontMetricsF>

//
//  W A R N I N G
//  -------------
//
// This file is not part of the KDecoration2 API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

namespace KDecoration2
{

class DecorationSettings;

class KDECORATIONS_PRIVATE_EXPORT DecorationSettingsPrivate
{
public:
    virtual ~DecorationSettingsPrivate();
    virtual bool isOnAllDesktopsAvailable() const = 0;
    virtual bool isAlphaChannelSupported() const = 0;
    virtual bool isCloseOnDoubleClickOnMenu() const = 0;
    virtual QVector<DecorationButtonType> decorationButtonsLeft() const = 0;
    virtual QVector<DecorationButtonType> decorationButtonsRight() const = 0;
    virtual BorderSize borderSize() const = 0;
    virtual QFont font() const;
    virtual QFontMetricsF fontMetrics() const;

    DecorationSettings *decorationSettings();
    const DecorationSettings *decorationSettings() const;

    int gridUnit() const;
    int smallSpacing() const;
    int largeSpacing() const;
    void setGridUnit(int unit);
    void setLargeSpacing(int spacing);
    void setSmallSpacing(int spacing);

protected:
    explicit DecorationSettingsPrivate(DecorationSettings *parent);

private:
    class Private;
    const QScopedPointer<Private> d;
};
}

#endif
