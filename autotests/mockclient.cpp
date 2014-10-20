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
#include "mockclient.h"
#include <decoratedclient.h>

#include <QPalette>

MockClient::MockClient(KDecoration2::DecoratedClient *client, KDecoration2::Decoration *decoration)
    : QObject()
    , DecoratedClientPrivate(client, decoration)
{
}

Qt::Edges MockClient::borderingScreenEdges() const
{
    return Qt::Edges();
}

QString MockClient::caption() const
{
    return QString();
}

WId MockClient::decorationId() const
{
    return 0;
}

int MockClient::desktop() const
{
    return 1;
}

int MockClient::height() const
{
    return 0;
}

QIcon MockClient::icon() const
{
    return QIcon();
}

bool MockClient::isActive() const
{
    return false;
}

bool MockClient::isCloseable() const
{
    return m_closeable;
}

bool MockClient::isKeepAbove() const
{
    return m_keepAbove;
}

bool MockClient::isKeepBelow() const
{
    return m_keepBelow;
}

bool MockClient::isMaximizable() const
{
    return m_maximizable;
}

bool MockClient::isMaximized() const
{
    return isMaximizedHorizontally() && isMaximizedVertically();
}

bool MockClient::isMaximizedHorizontally() const
{
    return m_maximizedHorizontally;
}

bool MockClient::isMaximizedVertically() const
{
    return m_maximizedVertically;
}

bool MockClient::isMinimizable() const
{
    return m_minimizable;
}

bool MockClient::isModal() const
{
    return false;
}

bool MockClient::isMovable() const
{
    return false;
}

bool MockClient::isOnAllDesktops() const
{
    return m_onAllDesktops;
}

bool MockClient::isResizable() const
{
    return false;
}

bool MockClient::isShadeable() const
{
    return m_shadeable;
}

bool MockClient::isShaded() const
{
    return m_shaded;
}

QPalette MockClient::palette() const
{
    return QPalette();
}

bool MockClient::providesContextHelp() const
{
    return m_contextHelp;
}

void MockClient::requestClose()
{
    emit closeRequested();
}

void MockClient::requestContextHelp()
{
    emit quickHelpRequested();
}

void MockClient::requestMaximize(Qt::MouseButtons buttons)
{
    bool maximizedHorizontally = m_maximizedHorizontally;
    bool maximizedVertically = m_maximizedVertically;
    if (buttons.testFlag(Qt::LeftButton)) {
        maximizedHorizontally = !m_maximizedHorizontally;
        maximizedVertically = !m_maximizedVertically;
    }
    if (buttons.testFlag(Qt::MiddleButton)) {
        maximizedHorizontally = !m_maximizedHorizontally;
    }
    if (buttons.testFlag(Qt::RightButton)) {
        maximizedVertically = !m_maximizedVertically;
    }
    const bool wasMaximized = isMaximized();
    if (m_maximizedHorizontally != maximizedHorizontally) {
        m_maximizedHorizontally = maximizedHorizontally;
        emit client()->maximizedHorizontallyChanged(m_maximizedHorizontally);
    }
    if (m_maximizedVertically != maximizedVertically) {
        m_maximizedVertically = maximizedVertically;
        emit client()->maximizedVerticallyChanged(m_maximizedVertically);
    }
    if (wasMaximized != isMaximized()) {
        emit client()->maximizedChanged(isMaximized());
    }
}

void MockClient::requestMinimize()
{
    emit minimizeRequested();
}

void MockClient::requestShowWindowMenu()
{
    emit menuRequested();
}

void MockClient::requestToggleKeepAbove()
{
    m_keepAbove = !m_keepAbove;
    emit client()->keepAboveChanged(m_keepAbove);
}

void MockClient::requestToggleKeepBelow()
{
    m_keepBelow = !m_keepBelow;
    emit client()->keepBelowChanged(m_keepBelow);
}

void MockClient::requestToggleOnAllDesktops()
{
    m_onAllDesktops = !m_onAllDesktops;
    emit client()->onAllDesktopsChanged(m_onAllDesktops);
}

void MockClient::requestToggleShade()
{
    m_shaded = !m_shaded;
    emit client()->shadedChanged(m_shaded);
}

int MockClient::width() const
{
    return 0;
}

WId MockClient::windowId() const
{
    return 0;
}

void MockClient::setCloseable(bool set)
{
    m_closeable = set;
    emit client()->closeableChanged(set);
}

void MockClient::setMinimizable(bool set)
{
    m_minimizable = set;
    emit client()->minimizableChanged(set);
}

void MockClient::setProvidesContextHelp(bool set)
{
    m_contextHelp = set;
    emit client()->providesContextHelpChanged(set);
}

void MockClient::setShadeable(bool set)
{
    m_shadeable = set;
    emit client()->shadeableChanged(set);
}

void MockClient::setMaximizable(bool set)
{
    m_maximizable = set;
    emit client()->maximizableChanged(set);
}