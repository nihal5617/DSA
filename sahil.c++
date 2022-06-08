vector<int> findIndices(vector<int> queries, vector<int> input, int X)
{
    vector<int> temp;
    for (int i = 0; i < input.size(); i++)
    {

        if (input[i] == X)
        {

            // 1 based indexing

            temp.push_back(i + 1);
        }
    }
    vector<int> output;
    for (int i = 0; i < queries.size(); i++)
    {
        if (temp[queries[i] - 1])
        {
            output.push_back(temp[queries[i] - 1]);
        }
        else
        {
            output.push_back(-1);
        }
    }
    return output;
}