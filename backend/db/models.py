from sqlalchemy.orm import declarative_base
from sqlalchemy import Column, String, Integer

Base = declarative_base()

class Student(Base):
    __tablename__ = 'students'
    id = Column(Integer(), auto_increment=True, primary_key=True)
    name = Column(String(), nullable=False)
    
