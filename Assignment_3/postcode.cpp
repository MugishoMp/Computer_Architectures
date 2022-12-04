/*
 * Skeleton code for use with Computer Architecture 2022 assignment 3,
 * LIACS, Leiden University.
 */

#include "postcode.h"

#include <unordered_map>
#include <algorithm>

#include <iostream>


static void
run_query_scan(const std::vector<Record> &postcode_table,
               std::vector<Record> &result_table,
               const size_t blockSize)
{
  for (auto &result : result_table)
    {
      auto it = std::find(postcode_table.begin(), postcode_table.end(),
                          result.postcode);
      if (it != postcode_table.end())
        {
          strncpy(result.street.data(), it->street.data(), Record::STREET_LEN);
          strncpy(result.city.data(), it->city.data(), Record::CITY_LEN);
        }
    }
}

static void
run_query_hash(const std::vector<Record> &postcode_table,
               std::vector<Record> &result_table,
               const size_t blockSize)
{
  std::unordered_map<Record::Postcode, size_t> hash;

  /* Setting the number of buckets in advance has a positive effect
   * on performance. The hash function provided is near perfect.
   */
  hash.rehash(postcode_table.size());

  for (size_t i = 0; i < postcode_table.size(); ++i)
    hash[postcode_table[i].postcode] = i;

  for (auto &result : result_table)
    {
      auto it = hash.find(result.postcode);
      if (it != hash.end())
        {
          strncpy(result.street.data(), postcode_table[it->second].street.data(), Record::STREET_LEN);
          strncpy(result.city.data(), postcode_table[it->second].city.data(), Record::CITY_LEN);
        }
    }
}

/* Add additional variants here. In support/postcode.h you can find
 * a binary_search routine you can use. You can add the new routines
 * in the main function below to test and benchmark these.
 */



int
main (int argc, char **argv)
{
  if (argc < 4)
    {
      std::cerr << "usage: " << argv[0]
                << " <postcode_file> <query_file> <n_repeat>" << std::endl;
      std::cerr << std::endl;
      std::cerr << "  if <n_repeat> equals 't', test mode is enabled which " << std::endl
                << "  will output the results of the query to stdout." << std::endl;
      return EXIT_FAILURE;
    }

  std::string postcode_filename(argv[1]);
  std::string query_filename(argv[2]);
  bool testMode = false;
  long int n_repeat = 0;
  if (argv[3][0] == 't')
    testMode = true;
  else
    {
      n_repeat = strtol(argv[3], NULL, 10);
      if (errno > 0 || n_repeat == 0)
        {
          std::cerr << "Could not convert <n_repeat> to integer." << std::endl;
          return EXIT_FAILURE;
        }
    }

  /* Load files */
  std::vector<Record> postcode_table;
  if (! read_postcode_table(postcode_filename, postcode_table))
    return EXIT_FAILURE;

  std::cerr << "loaded " << postcode_table.size() << " entries." << std::endl;

  std::vector<Record> result_table_blank;
  if (! read_query(query_filename, result_table_blank))
    return EXIT_FAILURE;

  /* Run */
  bool result = false;
  if (testMode)
    {
#if 1
      result = test_query_function(run_query_scan, 0,
                                   postcode_table, result_table_blank);
#elif 0
      result = test_query_function(run_query_hash, 0,
                                   postcode_table, result_table_blank);
#endif
    }
  else
    {
      result |= bench_query_function(run_query_scan,
                                     "scan", n_repeat, 0,
                                     postcode_table, result_table_blank,
                                     postcode_filename, query_filename);

      result |= bench_query_function(run_query_hash,
                                     "hash", n_repeat, 0,
                                     postcode_table, result_table_blank,
                                     postcode_filename, query_filename);
    }

  return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
