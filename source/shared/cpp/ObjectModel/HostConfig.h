#pragma once

#include "pch.h"
#include "Enums.h"
#include "json/json.h"

namespace AdaptiveCards
{
struct SpacingDefinition
{
    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int top = 0;
    unsigned int bottom = 0;

    static SpacingDefinition Deserialize(const Json::Value& json, const SpacingDefinition& defaultValue);
};

struct FontSizesConfig
{
    unsigned int smallFontSize = 10;
    unsigned int defaultFontSize = 12;
    unsigned int mediumFontSize = 14;
    unsigned int largeFontSize = 17;
    unsigned int extraLargeFontSize = 20;

    static FontSizesConfig Deserialize(const Json::Value& json, const FontSizesConfig& defaultValue);
};

struct ColorConfig
{
    std::string defaultColor;
    std::string subtleColor;

    static ColorConfig Deserialize(const Json::Value& json, const ColorConfig& defaultValue);
};

struct ColorsConfig
{
    ColorConfig defaultColor = { "#FF000000", "#B2000000" };
    ColorConfig accent = { "#FF0000FF", "#B20000FF" };
    ColorConfig dark = { "#FF101010", "#B2101010" };
    ColorConfig light = { "#FFFFFFFF", "#B2FFFFFF" };
    ColorConfig good = { "#FF008000", "#B2008000" };
    ColorConfig warning = { "#FFFFD700", "#B2FFD700" };
    ColorConfig attention = { "#FF8B0000", "#B28B0000" };

    static ColorsConfig Deserialize(const Json::Value& json, const ColorsConfig& defaultValue);
};

struct TextConfig
{
    TextWeight weight = TextWeight::Default;
    TextSize size = TextSize::Default;
    ForegroundColor color = ForegroundColor::Default;
    bool isSubtle = false;

    static TextConfig Deserialize(const Json::Value& json, const TextConfig& defaultValue);
};

struct SpacingConfig
{
    unsigned int smallSpacing = 3;
    unsigned int defaultSpacing = 8;
    unsigned int mediumSpacing = 20;
    unsigned int largeSpacing = 30;
    unsigned int extraLargeSpacing = 40;

    static SpacingConfig Deserialize(const Json::Value& json, const SpacingConfig& defaultValue);
};

struct SeparatorThicknessConfig
{
    unsigned int defaultSeparatorThickness = 1;
    unsigned int thickSeparatorThickness = 4;

    static SeparatorThicknessConfig Deserialize(const Json::Value& json, const SeparatorThicknessConfig& defaultValue);
};

struct ImageSizesConfig
{
    unsigned int smallSize = 80;
    unsigned int mediumSize = 120;
    unsigned int largeSize = 180;

    static ImageSizesConfig Deserialize(const Json::Value& json, const ImageSizesConfig& defaultValue);
};

struct ImageSetConfig
{
    ImageSize imageSize = ImageSize::Medium;

    static ImageSetConfig Deserialize(const Json::Value& json, const ImageSetConfig& defaultValue);
};

struct AdaptiveCardConfig
{
    SpacingDefinition padding = { 8, 8, 8, 8 };
    bool allowCustomStyle = true;

    static AdaptiveCardConfig Deserialize(const Json::Value& json, const AdaptiveCardConfig& defaultValue);
};

struct FactSetConfig
{
    TextConfig title = { TextWeight::Bolder };
    TextConfig value;
    unsigned int spacing = 20;

    static FactSetConfig Deserialize(const Json::Value& json, const FactSetConfig& defaultValue);
};

struct ContainerStyleDefinition
{
    std::string backgroundColor = "#FFFFFFFF";
    ColorsConfig foregroundColors;

    static ContainerStyleDefinition Deserialize(const Json::Value& json, const ContainerStyleDefinition& defaultValue);
};

struct ContainerStylesDefinition
{
    ContainerStyleDefinition defaultPalette;
    ContainerStyleDefinition emphasisPalette = 
    { "#08000000",
        {
            { "#333333", "#EE333333" },     //defaultColor
            { "#2E89FC", "#882E89FC" },     //accent
            { "#FF101010", "#B2101010" },   //dark
            { "#FFFFFFFF", "#B2FFFFFF" },   //light
            { "#54a254", "#DD54a254" },     //good
            { "#e69500", "#DDe69500" },     //warning
            { "#cc3300", "#DDcc3300" }      //attention
        }
    };

    static ContainerStylesDefinition Deserialize(const Json::Value& json, const ContainerStylesDefinition& defaultValue);
};

struct ShowCardActionConfig
{
    ActionMode actionMode = ActionMode::InlineEdgeToEdge;
    ContainerStyle style = ContainerStyle::Emphasis;
    unsigned int inlineTopMargin = 16;
    SpacingDefinition padding = { 16, 16, 16, 16 };

    static ShowCardActionConfig Deserialize(const Json::Value& json, const ShowCardActionConfig& defaultValue);
};

struct ActionsConfig
{
    ShowCardActionConfig showCard;
    ActionsOrientation actionsOrientation = ActionsOrientation::Horizontal;
    ActionAlignment actionAlignment = ActionAlignment::Center;
    unsigned int buttonSpacing = 8;
    unsigned int maxActions = 5;
    Spacing spacing;

    static ActionsConfig Deserialize(const Json::Value& json, const ActionsConfig& defaultValue);
};

struct HostConfig
{
    std::string fontFamily = "Calibri";
    FontSizesConfig fontSizes;
    bool supportsInteractivity = true;
    ImageSizesConfig imageSizes;
    unsigned int maxActions = 5;
    SeparatorThicknessConfig separatorThickness;
    SpacingConfig spacing;
    AdaptiveCardConfig adaptiveCard;
    ImageSetConfig imageSet;
    FactSetConfig factSet;
    ActionsConfig actions;
    ContainerStylesDefinition containerStyles;

    static HostConfig Deserialize(const Json::Value& json);
    static HostConfig DeserializeFromString(const std::string jsonString);
};
}
