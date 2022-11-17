/*
** EPITECH PROJECT, 2022
** include
** File description:
** ArgumentParser
*/

#pragma once

#include <string>

namespace indie {

/*
 * ArgumentParser error thrown when an error occurred
 */
class ArgumentParserError : public std::exception {
   public:
    ArgumentParserError() noexcept = delete;
    explicit ArgumentParserError(std::string const& message);
    ArgumentParserError(ArgumentParserError const& other) = default;
    ArgumentParserError(ArgumentParserError&& other) = default;
    ~ArgumentParserError() override = default;

    ArgumentParserError& operator=(ArgumentParserError const& other) = default;
    ArgumentParserError& operator=(ArgumentParserError&& other) = default;

    /*
     * Return the error message
     */
    const char* what() const noexcept final;

   protected:
    /*
     * Message that describe the error
     */
    std::string message;
};

/*
 * Parser of program argument
 */
class ArgumentParser {
   public:
    ArgumentParser() noexcept = delete;
    ArgumentParser(ArgumentParser const& other) noexcept = delete;
    ArgumentParser(ArgumentParser&& other) noexcept = delete;
    ~ArgumentParser() noexcept = delete;

    ArgumentParser& operator=(ArgumentParser const& other) noexcept = delete;
    ArgumentParser& operator=(ArgumentParser&& other) noexcept = delete;

    /*
     * Parse program arguments
     *
     * No return value
     *
     * ac -> The number of arguments
     *
     * av -> The arguments as an array
     */
    static void parse(int ac, const char* av[]);
    /*
     * Get the json config file path
     *
     * Return the filepath
     */
    static std::string getConfigFilePath() noexcept;

   private:
    static std::string configPath;
};

} // namespace indie
