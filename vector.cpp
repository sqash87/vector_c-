 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>
 #include <cstdlib>
 #include <vector>
 #include <iterator>
 #include <algorithm>
 using namespace std;

class Sorted_vector
{
private:
    vector<int>myvec{};
    
public:
    Sorted_vector(int cap=10);
    int getcapacity () const;
    int getsize() const;
    bool isEmpty() const;
    void insert_val(int val);
    int binary_func1(vector<int>myvec, int start_pos, int end_pos, int target_val);
    int find( int val);
    void delete_func(int terget_val);
    friend std::ostream & operator<<(std::ostream &out, const Sorted_vector & sV);
};
Sorted_vector::Sorted_vector(int cap) // reserving the capacity of the vector.
{
    myvec.reserve(cap);
}

int Sorted_vector::getcapacity() const
{
    return myvec.capacity();
}

int Sorted_vector::getsize() const // returning the size of the vector.
{
    return myvec.size();
}

bool Sorted_vector::isEmpty() const // checking if the vector is full or empty.
{
    int size= getsize();
    if (size==0)
        return true;
    else
        return false;
}

void Sorted_vector::insert_val(int val)
{
    if (myvec.size()<1)
    {
        myvec.insert(myvec.begin()+0,val);
    }

    else
    {
        int index=0;
      
        while (index<myvec.size())
           {
                   if (val>=myvec[index])
                       index++;
                   else
                   {
                       myvec.insert(myvec.begin()+index,val);
                       break;
                   }
            }

        if (index==myvec.size())
        myvec.insert(myvec.begin()+index,val);
    }
}
int Sorted_vector::binary_func1(vector<int> myvec, int start_pos, int end_pos, int target_val) // binary seacrch
{
    int middle_pos= (start_pos+ end_pos)/2; // end position is always less than the size of the vector or the list and start position is always 0.
        
        int middle_val= myvec[middle_pos]; // finding the middle value of the vector.
        
        if ( start_pos>end_pos) // base case which just returns -1 to the main function to pring out that the valuse does not contain inside the list.
            return -1;
        
        
        if (target_val==middle_val) // comapring the target value with the middle_val and then return the position number of the target value.
        {
            return middle_pos;
        }
    
        if (target_val>middle_val)
        {
            start_pos= middle_pos+1;
            end_pos= end_pos;
            return binary_func1( myvec, start_pos, end_pos, target_val);
        }
        
        else
            start_pos= start_pos;
            end_pos= middle_pos-1;
            return binary_func1(myvec, start_pos, end_pos,target_val);
}

void Sorted_vector::delete_func(int terget_val) // deleting the target value
    {
        cout<< " deleting " << terget_val <<endl;
        int start_pos=0;
        
        int end_pos= myvec.size()-1;
        
        int index_pos= binary_func1(myvec, start_pos, end_pos, terget_val);
        if (index_pos<0)
        {
            cout<< " The target value is not in the vector " <<endl;
        }
        else
            myvec.erase(myvec.begin()+index_pos);
    }
        
std::ostream & operator<<(std::ostream &out, const Sorted_vector & sV) // printing out the elements of the vector.
{
   for(int i=0;i<sV.getsize();i++){
       out<<sV.myvec[i]<<" ";
   }
   return out;
}

int main()
{
    Sorted_vector v1;
    cout<< " The current size of the vector is: " << v1.getsize() <<endl;
    cout<< " The current capacity of the vector is "<< v1.getcapacity() <<endl;
    bool bool_val = v1.isEmpty();
    if (bool_val==true)
    {
        cout<< " The vector is empty" <<endl;
    }
    else
        cout<< " The vector is not empty" <<endl;
    
    v1.insert_val(7);
    cout<<"vector : "<<v1<<"\n\n";
    v1.insert_val(15);
    cout<< "vector: " <<v1 << "\n\n";
    v1.insert_val(10);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(35);
    cout<< "vector: " <<v1 << "\n\n";
   
    v1.insert_val(17);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(22);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(10);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(33);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(15);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(40);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(28);
    cout<< "vector: " <<v1 << "\n\n";
 
    v1.insert_val(30);
    cout<< "vector: " <<v1 << "\n\n";
    
    v1.insert_val(27);
    cout<< "vector: " <<v1 << "\n\n";
   
    v1.insert_val(55);
    cout<< "vector: " <<v1 << "\n\n";
 
    v1.insert_val(20);
    cout<< "vector: " <<v1 << "\n\n";
    
    cout<< " The current size of the vector is: " << v1.getsize() <<endl;
    
    bool bool_val2 = v1.isEmpty();
    if (bool_val2==true)
    {
        cout<< " The vector is empty" <<endl;
    }
    else
        cout<< " The vector is not empty" <<endl;
                            
                            cout<< "     **********************************       " <<endl;
   
    v1.delete_func(17);
    cout<< "vector: " <<v1 << "\n\n";
    v1.delete_func(30);
    cout<< "vector: " <<v1 << "\n\n";
    v1.delete_func(75);
    cout<< "vector: " <<v1 << "\n\n";
    v1.delete_func(10);
    cout<< "vector: " <<v1 << "\n\n";
    v1.delete_func(22);
    cout<< "vector: " <<v1 << "\n\n";
                            cout<< "     **********************************       " <<endl;
    cout<< " The current size of the vector is: " << v1.getsize() <<endl;
    
}
