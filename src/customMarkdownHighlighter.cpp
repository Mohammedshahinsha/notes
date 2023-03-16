#include "customMarkdownHighlighter.h"

CustomMarkdownHighlighter::CustomMarkdownHighlighter(QTextDocument *parent,
                                                     HighlightingOptions highlightingOptions)
    : MarkdownHighlighter(parent, highlightingOptions)
{
}

void CustomMarkdownHighlighter::setHeaderColors(QColor color)
{
    // set all header colors to the same color
    for (int i = HighlighterState::H1; i <= HighlighterState::H6; ++i) {
        _formats[static_cast<HighlighterState>(i)].setForeground(color);
    }
}

void CustomMarkdownHighlighter::setFontSize(qreal fontSize)
{
    // change font size for all formats
    for (auto &format : _formats) {
        format.setFontPointSize(fontSize);
    }

    // change header sizes
    for (int i = HighlighterState::H1; i <= HighlighterState::H6; ++i) {
        // H1 => size = fontSize * 1.6
        // H6 => size = fontSize * 1.1
        qreal size = fontSize * (1.6 - (i - HighlighterState::H1) * 0.1);
        _formats[static_cast<HighlighterState>(i)].setFontPointSize(size);
    }
}

void CustomMarkdownHighlighter::setTheme(Theme theme, QColor textColor, qreal fontSize)
{
    setHeaderColors(textColor);
    setFontSize(fontSize);

    switch (theme) {
    case Theme::Light:
    case Theme::Dark:
    case Theme::Sepia:
        break;
    }
}