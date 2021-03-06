#include "ipaddresses.h"

#include <sstream>

using namespace std;
using namespace swss;

IpAddresses::IpAddresses(const string &ipsStr)
{
    string ip_str;
    istringstream iss(ipsStr);

    while (getline(iss, ip_str, ','))
    {
        IpAddress ip(ip_str);
        m_ips.insert(ip);
    }
}

void IpAddresses::add(const string &ipStr)
{
    IpAddress ip(ipStr);
    m_ips.insert(ip);
}

void IpAddresses::add(const IpAddress &ip)
{
    m_ips.insert(ip);
}

bool IpAddresses::contains(const std::string &ipStr)
{
    IpAddress ip(ipStr);
    return m_ips.find(ip) != m_ips.end();
}

bool IpAddresses::contains(const IpAddress &ip)
{
    return m_ips.find(ip) != m_ips.end();
}

void IpAddresses::remove(const string &ipStr)
{
    IpAddress ip(ipStr);
    m_ips.erase(ip);
}

void IpAddresses::remove(const IpAddress &ip)
{
    m_ips.erase(ip);
}

const string IpAddresses::to_string() const
{
    string ips_str;

    for (auto it = m_ips.begin(); it != m_ips.end(); ++it)
    {
        if (it != m_ips.begin())
        {
            ips_str += ",";
        }

        ips_str += it->to_string();
    }

    return ips_str;
}
