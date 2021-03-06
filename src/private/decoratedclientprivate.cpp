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
#include "decoratedclientprivate.h"

#include <QColor>

namespace KDecoration2
{

class Q_DECL_HIDDEN DecoratedClientPrivate::Private
{
public:
    explicit Private(DecoratedClient *client, Decoration *decoration);
    DecoratedClient *client;
    Decoration *decoration;
};

DecoratedClientPrivate::Private::Private(DecoratedClient *client, Decoration *decoration)
    : client(client)
    , decoration(decoration)
{
}

DecoratedClientPrivate::DecoratedClientPrivate(DecoratedClient *client, Decoration *decoration)
    : d(new Private(client, decoration))
{
}

DecoratedClientPrivate::~DecoratedClientPrivate() = default;

Decoration *DecoratedClientPrivate::decoration()
{
    return d->decoration;
}

Decoration *DecoratedClientPrivate::decoration() const
{
    return d->decoration;
}

DecoratedClient *DecoratedClientPrivate::client()
{
    return d->client;
}

QColor DecoratedClientPrivate::color(ColorGroup group, ColorRole role) const
{
    Q_UNUSED(role)
    Q_UNUSED(group)

    return QColor();
}

ApplicationMenuEnabledDecoratedClientPrivate::ApplicationMenuEnabledDecoratedClientPrivate(DecoratedClient *client, Decoration *decoration)
    : DecoratedClientPrivate(client, decoration)
{

}

ApplicationMenuEnabledDecoratedClientPrivate::~ApplicationMenuEnabledDecoratedClientPrivate() = default;

}
