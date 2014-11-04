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
#ifndef KDECORATION2_DECORATIONBUTTON_P_H
#define KDECORATION2_DECORATIONBUTTON_P_H

#include "decorationbutton.h"

class QElapsedTimer;
class QTimer;

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

class DecorationButton::Private
{
public:
    explicit Private(DecorationButtonType type, const QPointer<Decoration> &decoration, DecorationButton *parent);
    ~Private();

    const QRect &geometry() const {
        return m_geometry;
    }
    void setGeometry(const QRect &geometry);
    DecorationButtonType type() const {
        return m_type;
    }

    bool isHovered() const {
        return m_hovered;
    }
    bool isPressed() const {
        return m_pressed != Qt::NoButton;
    }
    bool isPressed(Qt::MouseButton button) const {
        return m_pressed.testFlag(button);
    }

    QPointer<Decoration> decoration() const {
        return m_decoration;
    }
    void setHovered(bool hovered);
    void setPressed(Qt::MouseButton, bool pressed);
    void setAcceptedButtons(Qt::MouseButtons buttons);
    Qt::MouseButtons acceptedButtons() const {
        return m_buttons;
    }
    void setEnabled(bool enabled);
    bool isEnabled() const {
        return m_enabled;
    }
    bool isChecked() const {
        return m_checked;
    }
    bool isCheckable() const {
        return m_checkable;
    }
    bool isVisible() const {
        return m_visible;
    }
    void setChecked(bool checked);
    void setCheckable(bool checkable);
    void setVisible(bool visible);
    bool isDoubleClickEnabled() const {
        return m_doubleClickEnabled;
    }
    void setDoubleClickEnabled(bool enable) {
        m_doubleClickEnabled = enable;
    }
    void startDoubleClickTimer();
    void invalidateDoubleClickTimer();
    bool wasDoubleClick() const;
    bool isPressAndHold() const {
        return m_pressAndHold;
    }
    void setPressAndHold(bool enable);
    void startPressAndHold();
    void stopPressAndHold();

private:
    void init();
    DecorationButton *q;
    QPointer<Decoration> m_decoration;
    DecorationButtonType m_type;
    QRect m_geometry;
    bool m_hovered;
    bool m_enabled;
    bool m_checkable;
    bool m_checked;
    bool m_visible;
    Qt::MouseButtons m_pressed;
    Qt::MouseButtons m_buttons;
    bool m_doubleClickEnabled;
    QScopedPointer<QElapsedTimer> m_doubleClickTimer;
    bool m_pressAndHold;
    QScopedPointer<QTimer> m_pressAndHoldTimer;
};

}

#endif
