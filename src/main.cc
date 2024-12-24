#include <cpr/cpr.h>
#include <fstream>
#include <iostream>
#include <tqdm.hpp>
void download_file(const std::string &url, const std::string &output_file)
{
    try
    {
        using namespace cpr;
        // Send a GET request to the URL
        auto response = cpr::Get(cpr::Url{url}, cpr::ProgressCallback(cpr::ProgressCallback([&](cpr::cpr_off_t downloadTotal, cpr_off_t downloadNow, cpr_off_t uploadTotal, cpr_off_t uploadNow, intptr_t userdata) -> bool
                                                                                            {
        printf("\rDownload Status : %.2lf%",static_cast<double>(downloadNow)/static_cast<double>(downloadTotal)*100.0);//better than std::cout 
        return true; })));

        // Check if the request was successful
        if (response.status_code == 200)
        {
            std::cout << "\nDownload successful! Saving to " << output_file << "\n";

            // Write the response body to the output file
            std::ofstream file(output_file, std::ios::binary);
            file.write(response.text.c_str(), response.text.size());
            file.close();

            std::cout << "File saved successfully!\n";
        }
        else
        {
            std::cerr << "Failed to download file. HTTP status code: " << response.status_code << "\n";
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
    }
}

int main(int argc, char **argv)
{
    // URL of the file to download
    if (argc < 3)
    {
        fprintf(stderr, "here is how to use it : get url outputfilename.zip\n");
        return 0;
    };
    std::string url = argv[1];

    // Path to save the downloaded file
    std::string output_file = argv[2];

    // Download the file
    download_file(url, output_file);

    return 0;
}
