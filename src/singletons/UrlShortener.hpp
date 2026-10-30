// SPDX-FileCopyrightText: 2026 Contributors to Chatterino
//
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>
#include <QPointer>

namespace chatterino
{

class ResizingTextEdit;
class Channel;
class NetworkResult;

using ChannelPtr = std::shared_ptr<Channel>;

class UrlShortener final
{
public:
    void shorten(const QString &url, ChannelPtr channel,
                 QPointer<ResizingTextEdit> textEdit);

private:
    void sendShortenRequest(const QString &url, ChannelPtr channel,
                            QPointer<ResizingTextEdit> textEdit);

    void handleSuccessfulShorten(const NetworkResult &result,
                                 ChannelPtr channel,
                                 QPointer<ResizingTextEdit> textEdit);

    void handleFailedShorten(const NetworkResult &result,
                             ChannelPtr channel);
};
}