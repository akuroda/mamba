// Copyright (c) 2019, QuantStack and Mamba Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef MAMBA_CORE_PREFIX_DATA_HPP
#define MAMBA_CORE_PREFIX_DATA_HPP

#include <string>
#include <unordered_map>

#include "error_handling.hpp"
#include "history.hpp"
#include "package_info.hpp"

namespace mamba
{
    class PrefixData
    {
    public:
        using package_map = std::unordered_map<std::string, PackageInfo>;

        static expected_t<PrefixData> create(const fs::u8path& prefix_path);

        void add_packages(const std::vector<PackageInfo>& packages);
        const package_map& records() const;
        void load_single_record(const fs::u8path& path);

        History& history();
        const fs::u8path& path() const;
        std::vector<PackageInfo> sorted_records() const;

    private:
        PrefixData(const fs::u8path& prefix_path);
        void load();

        History m_history;
        std::unordered_map<std::string, PackageInfo> m_package_records;
        fs::u8path m_prefix_path;
    };
}  // namespace mamba

#endif
